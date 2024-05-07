/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   clean.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aogbi <aogbi@student.1337.ma>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/02 08:30:31 by aogbi             #+#    #+#             */
/*   Updated: 2024/05/07 10:24:15 by aogbi            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

int	spaces_arg(char *str)
{
	int	i;

	i = 0;
	while (str[i])
	{
		if (str[i] != ' ')
			return (1);
		i++;
	}
	return (0);
}

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

void	clean(char **stack)
{
	int	i;

	i = 0;
	while (stack[i])
	{
		free(stack[i]);
		i++;
	}
	free(stack);
}

void	ft_clearstack(t_list **lst)
{
	t_list	*head;

	if (!lst)
		return ;
	while (*lst)
	{
		head = *lst;
		*lst = head->next;
		free(head);
	}
}

int	only_in_stack(t_list *stack)
{
	t_list	*tmp1;
	t_list	*tmp2;

	tmp1 = stack;
	while (tmp1)
	{
		tmp2 = tmp1->next;
		while (tmp2)
		{
			if (tmp1->content == tmp2->content)
				return (0);
			tmp2 = tmp2->next;
		}
		tmp1 = tmp1->next;
	}
	return (1);
}
