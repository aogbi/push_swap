/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aogbi <aogbi@student.1337.ma>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/02 06:31:19 by aogbi             #+#    #+#             */
/*   Updated: 2024/05/03 16:59:07 by aogbi            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	is_sorted(t_list *list)
{
	t_list	*tmp;

	tmp = list;
	while (tmp->next)
	{
		if ((ssize_t)tmp->content > (ssize_t)tmp->next->content)
			return (0);
		tmp = tmp->next;
	}
	return (1);
}

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
		ft_printf("Error\n");
		return (1);
	}
	if (ft_lstsize(stack) > 1 && !is_sorted(stack))
		push_swap(&stack);
	ft_clearstack(&stack);
	return (0);
}
