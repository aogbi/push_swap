/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aogbi <aogbi@student.1337.ma>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/02 06:31:19 by aogbi             #+#    #+#             */
/*   Updated: 2024/05/06 12:30:27 by aogbi            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	prepar(t_list **list, char c)
{
	if (((ssize_t)(*list)->content > (ssize_t)(*list)->next->content)
		&& ((ssize_t)(*list)->content > (ssize_t)ft_lstlast(*list)->content))
	{
		rotate(list);
		ft_printf("r%c\n", c);
	}
	else if (((ssize_t)ft_lstlast(*list)->content < (ssize_t)(*list)->content)
			&& ((ssize_t)ft_lstlast(*list)->content < (ssize_t)
				(*list)->next->content))
	{
		reverse_rotate(list);
		ft_printf("rr%c\n", c);
	}
	else
	{
		swap(*list);
		ft_printf("s%c\n", c);
	}
}

void	push_swap(t_list **stack_a)
{
	t_list	*stack_b;

	stack_b = NULL;
	push_to_b(stack_a, &stack_b);
	push_to_a(stack_a, &stack_b);
	while ((ssize_t)(*stack_a)->content > (ssize_t)
		ft_lstlast(*stack_a)->content)
	{
		reverse_rotate(stack_a);
		ft_printf("rra\n");
	}
}

int	main(int argc, char **argv)
{
	t_list	*stack;

	if (argc < 2)
		return (1);
	stack = parsing_arg(argc, argv);
	if (!stack || !only_in_stack(stack))
	{
		ft_clearstack(&stack);
		write(2, "Error\n", 7);
		return (1);
	}
	if (ft_lstsize(stack) > 1 && !is_sorted(stack))
		push_swap(&stack);
	ft_clearstack(&stack);
	return (0);
}
