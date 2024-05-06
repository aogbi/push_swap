/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aogbi <aogbi@student.1337.ma>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/04 16:02:38 by aogbi             #+#    #+#             */
/*   Updated: 2024/05/06 12:28:49 by aogbi            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap_bonus.h"

int	helper_function(t_list **stack_a, t_list **stack_b, char *line)
{
	if (!ft_strncmp(line, "pb\n", 3))
		push(stack_a, stack_b);
	else if (!ft_strncmp(line, "pa\n", 3))
		push(stack_b, stack_a);
	else if (!ft_strncmp(line, "sa\n", 3))
		swap(*stack_a);
	else if (!ft_strncmp(line, "ra\n", 3))
		rotate(stack_a);
	else if (!ft_strncmp(line, "rra\n", 4))
		reverse_rotate(stack_a);
	else if (!ft_strncmp(line, "sb\n", 3))
		swap(*stack_b);
	else if (!ft_strncmp(line, "ss\n", 3))
	{
		swap(*stack_a);
		swap(*stack_b);
	}
	else
		return (0);
	return (1);
}

int	is_valid_bonus(t_list **stack_a, t_list **stack_b, char *line)
{
	if (!helper_function(stack_a, stack_b, line))
	{
		if (!ft_strncmp(line, "rb\n", 3))
			rotate(stack_b);
		else if (!ft_strncmp(line, "rr\n", 3))
		{
			rotate(stack_a);
			rotate(stack_b);
		}
		else if (!ft_strncmp(line, "rrb\n", 4))
			reverse_rotate(stack_b);
		else if (!ft_strncmp(line, "rrr\n", 4))
		{
			reverse_rotate(stack_a);
			reverse_rotate(stack_b);
		}
		else
			return (0);
	}
	return (1);
}

int	read_from_input_fd(t_list **stack_a)
{
	char	*line;
	t_list	*stack_b;

	stack_b = NULL;
	line = get_next_line(0);
	while (line)
	{
		if (!is_valid_bonus(stack_a, &stack_b, line))
		{
			write(2, "Error\n", 7);
			free_memory(&line);
			ft_clearstack(&stack_b);
			return (0);
		}
		free_memory(&line);
		line = get_next_line(0);
	}
	ft_clearstack(&stack_b);
	return (1);
}

int	main(int argc, char **argv)
{
	t_list	*stack;
	int		size;

	if (argc < 2)
		return (1);
	stack = parsing_arg(argc, argv);
	if (!stack || !only_in_stack(stack))
	{
		ft_clearstack(&stack);
		write(2, "Error\n", 7);
		return (1);
	}
	size = ft_lstsize(stack);
	if (!read_from_input_fd(&stack))
	{
		ft_clearstack(&stack);
		return (1);
	}
	if (size == ft_lstsize(stack) && is_sorted(stack))
		ft_printf("OK\n");
	else
		ft_printf("KO\n");
	ft_clearstack(&stack);
	return (0);
}
