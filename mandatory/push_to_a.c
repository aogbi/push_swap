/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_to_a.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aogbi <aogbi@student.1337.ma>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/02 12:38:22 by aogbi             #+#    #+#             */
/*   Updated: 2024/05/07 10:24:35 by aogbi            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

t_list	*big_num(t_list *list)
{
	t_list	*tmp;
	t_list	*big;

	tmp = list;
	big = list;
	while (tmp)
	{
		if ((ssize_t)tmp->content > (ssize_t)big->content)
			big = tmp;
		tmp = tmp->next;
	}
	return (big);
}

void	make_big_in_top(t_list **list)
{
	t_list	*big;
	int		list_size;
	int		big_size;

	big = big_num(*list);
	big_size = ft_lstsize(big);
	list_size = ft_lstsize(*list);
	while (big != *list)
	{
		if (big_size < list_size / 2)
		{
			reverse_rotate(list);
			ft_printf("rrb\n");
		}
		else
		{
			rotate(list);
			ft_printf("rb\n");
		}
	}
}

void	push_to_a(t_list **a, t_list **b)
{
	while (*b)
	{
		make_big_in_top(b);
		while ((ssize_t)(*a)->content > (ssize_t)ft_lstlast(*a)->content)
		{
			reverse_rotate(a);
			ft_printf("rra\n");
		}
		if ((ssize_t)big_num(*a)->content > (ssize_t)(*b)->content)
		{
			while ((ssize_t)(*b)->content > (ssize_t)(*a)->content)
			{
				rotate(a);
				ft_printf("ra\n");
			}
		}
		push(b, a);
		ft_printf("pa\n");
	}
	if ((ssize_t)ft_lstlast(*a)->content < (ssize_t)(*a)->content)
	{
		reverse_rotate(a);
		ft_printf("rra\n");
	}
}
