/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlorette <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/29 20:33:10 by mlorette          #+#    #+#             */
/*   Updated: 2020/11/02 20:30:18 by mlorette         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdio.h>

static int	ft_strncmp2(const char *s1, const char *s2, int k, int l)
{
	unsigned int	i;

	i = 0;
	while (s1[i] != 0 && i < ft_strlen(s2))
	{
		i++;
		k++;
	}
	if (k > l)
		return (10);
	i = 0;
	while (((*(s1 + i) != 0) || (*(s2 + i) != 0)) && i < ft_strlen(s2))
	{
		if (*((unsigned char *)s1 + i) > *((unsigned char *)s2 + i))
			return (1);
		if (*((unsigned char *)s1 + i) < *((unsigned char *)s2 + i))
			return (-1);
		i++;
	}
	return (0);
}

char		*ft_strnstr(const char *s, const char *n, size_t len)
{
	size_t	i;

	i = 0;
	if (n[0] == '\0')
		return ((char *)&s[0]);
	while (s[i] != 0 && i < len)
	{
		if (s[i] == n[0])
			if (ft_strncmp2((char *)&s[i], &n[0], i, len) == 0)
				return ((char *)&s[i]);
		i++;
	}
	return (NULL);
}
