/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aogbi <aogbi@student.1337.ma>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/01 10:24:47 by aogbi             #+#    #+#             */
/*   Updated: 2024/01/01 12:24:05 by aogbi            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "push_swap.h"

void	push_swap(t_list *head)
{

}

int	main(int argc, char **argv)
{
	t_list	*head;
	t_list	*tmp;
	size_t	index;

	index = 1;
	if (argc > 1)
	{
		head = ft_lstnew(ft_atoi(*argv[index++]));
		tmp = head -> next;
	}
	while(argc > index)
	{
		tmp = ft_lstnew(ft_atoi(*argv[index++]));
		tmp = tmp -> next;
	}
	push_swap(head);
	return (0);
}
