/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlorette <mlorette@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/07 20:51:44 by mlorette          #+#    #+#             */
/*   Updated: 2020/12/04 00:22:55 by mlorette         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

void	*ft_calloc2(size_t count)
{
	char	*str;
	size_t	i;

	if (!(str = malloc(sizeof(char) * count)))
		return (NULL);
	i = 0;
	while (i <= count)
		str[i++] = 0;
	return (str);
}

size_t	ft_strlen2(const char *str)
{
	size_t x;

	x = 0;
	while (str[x] != 0)
		x++;
	return (x);
}

void	ft_bzero2(void *b, size_t len)
{
	size_t	i;

	i = 0;
	while (i < len)
	{
		*((char *)b + i) = 0;
		i++;
	}
}

void	*ft_memmove2(void *dst, const void *src, size_t len)
{
	size_t i;

	i = 0;
	if (dst == 0 && src == 0)
		return (0);
	if (dst <= src)
	{
		while (i < len)
		{
			*((char *)dst + i) = *((char *)src + i);
			i++;
		}
		return ((char *)dst);
	}
	else
	{
		i = len - 1;
		while (i + 1 > 0)
		{
			*((char *)dst + i) = *((char *)src + i);
			i--;
		}
		return ((char *)dst);
	}
}

char	*ft_strjoin2(char *s1, char *s2, size_t stop, size_t stop2)
{
	size_t	i;
	size_t	j;
	char	*fin;

	i = 0;
	j = 0;
	fin = malloc(ft_strlen2(s1) + ft_strlen2(s2) + 1);
	if (fin == NULL)
		return (NULL);
	if (*s1)
	{
		while (s1[i] != 0 && i < stop2)
		{
			fin[i] = s1[i];
			i++;
		}
	}
	if (*s2)
		while (s2[j] != 0 && j < stop)
			fin[i++] = s2[j++];
	fin[i] = '\0';
	free(s1);
	return (fin);
}
