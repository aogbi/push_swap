/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aogbi <aogbi@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/01 10:24:47 by aogbi             #+#    #+#             */
/*   Updated: 2024/04/11 06:29:28 by aogbi            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "push_swap.h"

t_list	*stack_a(int argc, char **argv)
{
	t_list	*head;
	t_list	*node;

	if (argc < 2)
		return (NULL);
	head = NULL;
	while(--argc)
	{
		node = ft_lstnew((void *)(size_t)ft_atoi(argv[argc]));
		if (!node)
			return (NULL);
		ft_lstadd_front(&head, node);
	}
	return (head);
}

void	swap(t_list *stack)
{
	if (!stack)
	    return ;
	stack -> content = (void *)((size_t)stack -> content + (size_t)stack -> next -> content);
	stack -> next -> content = (void *)((size_t)stack -> content - (size_t)stack -> next -> content);
	stack -> content = (void *)((size_t)stack -> content - (size_t)stack -> next -> content);
}

void	rotate(t_list **stack)
{
	t_list	*tmp;

	if (!stack || !*stack)
		return ;
	tmp = ft_lstlast(*stack);
	tmp -> next = (*stack);
	tmp = (*stack) -> next;
	(*stack) -> next = NULL;
	(*stack) = tmp;
}

void	reverse_rotate(t_list **stack)
{
	t_list	*tmp;

	if (!stack || !*stack)
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
	*stack_1 = (*stack_1) -> next;
	tmp -> next = (*stack_2);
	(*stack_2) = tmp;
}

void	print_stack(t_list *head)
{
	t_list	*current;

	current = head;
	while (current)
	{
		ft_printf("%d ", (int)(size_t)current->content);
		current = current->next;
	}
	ft_printf("\n");
}

void	del(void *content)
{
	ft_printf("%d ", (int)(size_t)content);
}

int	main(int argc, char **argv)
{
    t_list    *A;
	t_list    *B;

    A = stack_a(argc, argv);
	B = NULL;
	swap(A);
	rotate(&A);
	// reverse_rotate(&A);
	// push(&A, &B);
	ft_lstclear(&A, del);
    // print_stack(A);
	// print_stack(B);
    return (0);
}
