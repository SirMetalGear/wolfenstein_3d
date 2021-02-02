/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlorette <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/31 20:15:10 by mlorette          #+#    #+#             */
/*   Updated: 2020/11/05 11:49:00 by mlorette         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static size_t	ft_count(char const *s1, char const *set)
{
	int	i;
	int	j;
	int	z;

	i = 0;
	j = 0;
	z = 0;
	while (s1[i] != 0)
	{
		while (set[j] != 0)
		{
			if (set[j] != s1[i] && set[j] != 0)
				z++;
			j++;
		}
		if (z == j)
			return (i);
		z = 0;
		j = 0;
		i++;
	}
	return (i);
}

static size_t	ft_discount(char const *s1, char const *set)
{
	int	i;
	int	j;
	int z;

	i = 0;
	j = 0;
	z = 0;
	while (s1[i] != 0)
		i++;
	i = i - 1;
	while (i > 0)
	{
		while (set[j] != 0)
		{
			if (set[j] != s1[i] && set[j] != 0)
				z++;
			j++;
		}
		if (z == j)
			return (i);
		j = 0;
		z = 0;
		i--;
	}
	return (i);
}

static char		*ft_zero(void)
{
	char	*str;

	str = malloc(1);
	str[0] = '\0';
	return (str);
}

char			*ft_strtrim(char const *s1, char const *set)
{
	char	*copy;
	size_t	i;
	size_t	j;
	size_t	z;

	z = 0;
	i = ft_count(s1, set);
	j = ft_discount(s1, set);
	if (i == ft_strlen(s1))
		return (ft_zero());
	if (s1[0] == '\0')
		return (ft_zero());
	copy = malloc(j - i + 2);
	if (copy == NULL)
		return (NULL);
	while (i <= j)
	{
		copy[z] = s1[i];
		z++;
		i++;
	}
	copy[z] = '\0';
	return (copy);
}
