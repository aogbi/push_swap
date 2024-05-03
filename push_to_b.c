/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_to_b.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aogbi <aogbi@student.1337.ma>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/03 09:43:40 by aogbi             #+#    #+#             */
/*   Updated: 2024/05/03 18:55:14 by aogbi            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	sort_array(int **array, int size)
{
	int	i;
	int	j;
	int range;
	int	temp;

	i = 0;
	j = 0;
	range = 0;
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
				range++;
			}
			j++;
		}
		i++;
	}
	return (range);
}

int	*store_stack(t_list *list, int size, int *range)
{
	int	*array;
	int	i;

	i = 0;
	array = malloc(sizeof(int) * (size + 1));
	while (list)
	{
		array[i] = (int)(ssize_t)list->content;
		list = list->next;
		i++;
	}
	*range = sort_array(&array, size);
	return (array);
}

void	init_helper(t_list **a, t_list **b, t_init init)
{
	int	j;
	int	bool;

	j = 0;
	bool = 0;
	while (j < init.range)
	{
		if (j + *init.i > init.size - 1)
			break ;
		if ((ssize_t)(*a)->content == init.array[j + *init.i])
		{
			push(a, b);
			(*init.i)++;
			ft_printf("pb\n");
			bool = 1;
		}
		j++;
	}
	if (!bool)
	{
		rotate(a);
		ft_printf("ra\n");
	}
}

void	init_and_push(t_list **a, t_list **b, t_init init)
{
	if ((ssize_t)(*a)->content < init.array[*init.i])
	{
		push(a, b);
		rotate(b);
		(*init.i)++;
		ft_printf("pb\nrb\n");
	}
	else
		init_helper(a, b, init);
}

void	push_to_b(t_list **a, t_list **b)
{
	int	*array;
	int	size;
	int	index;
	int	s_range;
	int    range;

	index = 0;
	size = ft_lstsize(*a);
	array = store_stack(*a, size, &s_range);
	range = (s_range * 2/ (size + size)) / 3;
	if (range <= 0)
		range = 2;
	while (ft_lstsize(*a) > 3)
		init_and_push(a, b, (t_init){array, &index, range, size});
	while (!is_sorted(*a))
		prepar(a, 'a');
	free(array);
}
