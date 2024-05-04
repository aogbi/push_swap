/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aogbi <aogbi@student.1337.ma>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/13 20:56:57 by aogbi             #+#    #+#             */
/*   Updated: 2024/05/04 18:29:43 by aogbi            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

size_t	ft_strlen(const char *s)
{
	size_t	i;

	i = 0;
	while (s[i])
		i++;
	return (i);
}

void	free_memory(char **ptr)
{
	if (*ptr)
	{
		free(*ptr);
		*ptr = NULL;
	}
}

size_t	ft_strlcat(char *dst, const char *src, size_t size)
{
	size_t	len_dest;
	size_t	len_src;
	size_t	i;
	size_t	ret;

	i = 0;
	len_dest = ft_strlen(dst);
	len_src = ft_strlen(src);
	if (size == 0)
		return (len_src);
	if (len_dest > size)
		return (len_src + size);
	else
	{
		ret = len_dest + len_src;
		while (src[i] && (len_dest + i) < (size - 1))
		{
			dst[len_dest + i] = src[i];
			i++;
		}
		dst[len_dest + i] = '\0';
		return (ret);
	}
}

char	*ft_strdup_get(char *s)
{
	char	*copy;
	size_t	len;

	if (!s)
		return (NULL);
	len = ft_strlen(s);
	copy = (char *)malloc(sizeof(char) * (len + 1));
	if (!copy)
		return (NULL);
	*copy = '\0';
	ft_strlcat(copy, s, len + 1);
	return (copy);
}

char	*ft_strchr(const char *s, int c)
{
	if (!s)
		return (NULL);
	while (*s)
	{
		if (*s == (char)c)
			return ((char *)s);
		s++;
	}
	if (*s == (char)c)
		return ((char *)s);
	return (NULL);
}
