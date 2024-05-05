/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_bonus.h                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aogbi <aogbi@student.1337.ma>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/04 16:03:43 by aogbi             #+#    #+#             */
/*   Updated: 2024/05/04 22:26:03 by aogbi            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_BONUS_H
# define PUSH_SWAP_BONUS_H

# include "Libft/libft.h"
# include "printf/ft_printf.h"
# include "get_next_line.h"
# include <limits.h>

void	swap(t_list *stack);

void	rotate(t_list **stack);

void	reverse_rotate(t_list **stack);

void	push(t_list **stack_1, t_list **stack_2);

void	ft_clearstack(t_list **lst);

int		only_in_stack(t_list *stack);

t_list	*parsing_arg(int argc, char **argv);

void	clean(char **stack);

int		is_sorted(t_list *list);

int		spaces_arg(char *str);

#endif
