/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operations.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aogbi <aogbi@student.1337.ma>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/02 06:42:29 by aogbi             #+#    #+#             */
/*   Updated: 2024/05/07 10:25:49 by aogbi            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap_bonus.h"

void	swap(t_list *stack)
{
	if (!stack || ft_lstsize(stack) <= 1)
		return ;
	stack -> content = (void *)((size_t)stack -> content + (size_t)
			stack -> next -> content);
	stack -> next -> content = (void *)((size_t)
			stack -> content - (size_t)stack -> next -> content);
	stack -> content = (void *)((size_t)stack -> content - (size_t)
			stack -> next -> content);
}

void	rotate(t_list **stack)
{
	t_list	*tmp;

	if (!stack || !*stack || ft_lstsize(*stack) <= 1)
		return ;
	tmp = ft_lstlast(*stack);
	tmp->next = (*stack);
	tmp = (*stack)->next;
	(*stack)->next = NULL;
	(*stack) = tmp;
}

void	reverse_rotate(t_list **stack)
{
	t_list	*tmp;

	if (!stack || !*stack || ft_lstsize(*stack) <= 1)
		return ;
	tmp = ft_lstbeforlast(*stack);
	tmp -> next -> next = (*stack);
	(*stack) = tmp -> next;
	tmp -> next = NULL;
}

void	push(t_list **stack_1, t_list **stack_2)
{
	t_list	*tmp;

	if (!stack_1 || !stack_2 || !*stack_1)
		return ;
	tmp = *stack_1;
	*stack_1 = (*stack_1)->next;
	tmp->next = (*stack_2);
	(*stack_2) = tmp;
}
