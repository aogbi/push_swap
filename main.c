/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aogbi <aogbi@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/01 10:24:47 by aogbi             #+#    #+#             */
/*   Updated: 2024/04/11 02:03:19 by aogbi            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "push_swap.h"
#include <stdio.h>

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

int	main(int argc, char **argv)
{
    t_list    *head_a;

    head_a = stack_a(argc, argv);
    print_stack(head_a);
    return (0);
}
