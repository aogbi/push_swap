/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aogbi <aogbi@student.1337.ma>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/02 06:32:04 by aogbi             #+#    #+#             */
/*   Updated: 2024/05/07 10:26:59 by aogbi            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "../Libft/libft.h"
# include "../printf/ft_printf.h"
# include <limits.h>

typedef struct s_init
{
	int	*array;
	int	*i;
	int	range;
	int	size;
}		t_init;

void	swap(t_list *stack);

void	rotate(t_list **stack);

void	reverse_rotate(t_list **stack);

void	push(t_list **stack_1, t_list **stack_2);

void	ft_clearstack(t_list **lst);

int		only_in_stack(t_list *stack);

t_list	*parsing_arg(int argc, char **argv);

void	clean(char **stack);

void	push_to_a(t_list **a, t_list **b);

void	push_to_b(t_list **a, t_list **b);

int		is_sorted(t_list *list);

void	prepar(t_list **list, char c);

int		spaces_arg(char *str);

#endif