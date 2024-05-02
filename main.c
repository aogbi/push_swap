/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aogbi <aogbi@student.1337.ma>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/02 06:31:19 by aogbi             #+#    #+#             */
/*   Updated: 2024/05/02 15:54:22 by aogbi            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	is_sorted(t_list *list)
{
	if (((ssize_t)ft_lstlast(list)->content < (ssize_t)list->content)
		|| ((ssize_t)ft_lstlast(list)->content < (ssize_t)list->next->content))
		return (0);
	if (((ssize_t)list->content > (ssize_t)list->next->content))
		return (0);
	return (1);
}

void	prepar(t_list **list, char c)
{
	if (is_sorted(*list))
		return ;
	if (((ssize_t)(*list)->content > (ssize_t)(*list)->next->content)
		&& ((ssize_t)(*list)->content > (ssize_t)ft_lstlast(*list)->content))
	{
		rotate(list);
		ft_printf("r%c\n", c);
	}
	else if (((ssize_t)ft_lstlast(*list)->content < (ssize_t)(*list)->content)
			&& ((ssize_t)ft_lstlast(*list)->content < (ssize_t)(*list)->next->content))
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
void	sort_array(int **array, int size)
{
	int	i;
	int	j;
	int	temp;

	i = 0;
	j = 0;
	while (i < size)
	{
		j = 0;
		while (j < size - 1)
		{
			if ((*array)[j] > (*array)[j + 1])
			{
				temp = (*array)[j];
				(*array)[j] = (*array)[j + 1];
				(*array)[j + 1] = temp;
			}
			j++;
		}
		i++;
	}
}

int	*store_stack(t_list *list, int size)
{
	int	*array;
	int	i;

	i = 0;
	array = malloc(sizeof(int) * size);
	while (list)
	{
		array[i] = (int)(ssize_t)list->content;
		list = list->next;
		i++;
	}
	sort_array(&array, size);
	return (array);
}

void	push_to_b(t_list **a, t_list **b)
{
	
}

void	push_swap(t_list **stack_a)
{
	t_list	*stack_b;

	stack_b = NULL;
	push_to_b(stack_a, &stack_b);
	push_to_a(stack_a, &stack_b);
	// ft_printf("stack_b = ");
	// print_stack(stack_b);
}

int	main(int argc, char **argv)
{
	t_list	*stack;

	if (argc < 2)
		return (1);
	stack = parsing_arg(argc, argv);
	if (!stack || !only_in_stack(stack))
		return (1);
	push_swap(&stack);
	// ft_printf("stack_a = ");
	// print_stack(stack);
	ft_clearstack(&stack);
	return (0);
}
