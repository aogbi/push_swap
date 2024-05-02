/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aogbi <aogbi@student.1337.ma>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/02 08:45:39 by aogbi             #+#    #+#             */
/*   Updated: 2024/05/02 12:42:29 by aogbi            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

char	*all_arg_in_string(int argc, char **argv)
{
	int		i;
	char	*str;
	char	*tmp;

	i = 1;
	str = ft_strdup("\0");
	while (i < argc)
	{
		tmp = ft_strjoin(str, argv[i]);
		free(str);
		str = tmp;
		tmp = ft_strjoin(str, " ");
		free(str);
		str = tmp;
		i++;
	}
	return (str);
}

int	str_check(char *str)
{
	int	i;

	i = 0;
	while (str[i])
	{
		if (!ft_isdigit(str[i]) && str[i] != '-' && str[i] != '+'
			&& str[i] != ' ')
			return (0);
		i++;
	}
	return (1);
}

int	ziro(char *str)
{
	int	i;

	i = 0;
	if (str[i] == '-' || str[i] == '+')
		i++;
	if (str[i] == '\0')
		return (0);
	while (str[i])
	{
		if (str[i] != '0')
			return (0);
		i++;
	}
	return (1);
}

t_list	*is_valid(char **str)
{
	int		i;
	int		num;
	t_list	*list;

	i = 0;
	list = NULL;
	while (str[i])
	{
		num = ft_atoi(str[i]);
		if (num == 0 && !ziro(str[i]))
			return (NULL);
		ft_lstadd_back(&list, ft_lstnew((void *)(ssize_t)num));
		i++;
	}
	return (list);
}

t_list	*parsing_arg(int argc, char **argv)
{
	char *str;
	char **stack;
	t_list *list;

	str = all_arg_in_string(argc, argv);
	if (!str_check(str))
		return (NULL);
	stack = ft_split(str, ' ');
	free(str);
	list = is_valid(stack);
	clean(stack);
	return (list);
}
