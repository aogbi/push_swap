/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aogbi <aogbi@student.1337.ma>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/02 06:32:04 by aogbi             #+#    #+#             */
/*   Updated: 2024/05/02 12:39:01 by aogbi            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "Libft/libft.h"
# include "printf/ft_printf.h"

void	swap(t_list *stack);

void	rotate(t_list **stack);

void	reverse_rotate(t_list **stack);

void	push(t_list **stack_1, t_list **stack_2);

void	print_stack(t_list *head);

void	ft_clearstack(t_list **lst);

int		only_in_stack(t_list *stack);

t_list	*parsing_arg(int argc, char **argv);

void	clean(char **stack);

void	push_to_a(t_list **a, t_list **b);

#endif