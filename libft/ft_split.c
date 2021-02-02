/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlorette <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/01 16:32:10 by mlorette          #+#    #+#             */
/*   Updated: 2020/11/07 11:05:58 by mlorette         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_count(char const *s, char c)
{
	int i;
	int j;
	int z;

	i = 0;
	j = 0;
	z = 0;
	while (s[i] != 0)
	{
		while (s[i] != c && s[i] != 0)
			i++;
		if (i != j)
			z++;
		j = i;
		while (s[j] == c && s[j] != 0)
		{
			j++;
			i++;
		}
		j = i;
	}
	return (z);
}

static int	ft_start(char const *s, char c, int z)
{
	int	i;

	i = z;
	while (s[i] == c && s[i] != 0)
		i++;
	return (i);
}

static int	ft_finish(char const *s, char c, int z)
{
	int	i;

	i = z;
	while (s[i] != c && s[i] != 0)
		i++;
	return (i);
}

static char	**ft_free(char **str, int w)
{
	while (w >= 0)
	{
		free(str[w]);
		w--;
	}
	free(str);
	return (0);
}

char		**ft_split(char const *s, char c)
{
	int		i;
	char	**str;
	int		j;
	int		w;
	int		z;

	i = 0;
	j = 0;
	w = 0;
	if ((str = (char**)malloc(sizeof(char*) * ft_count(s, c) + 1)) == 0)
		return (0);
	while (w < ft_count(s, c))
	{
		z = 0;
		i = ft_start(s, c, i);
		j = ft_finish(s, c, i);
		if ((str[w] = (char *)malloc(sizeof(char) * (j - i) + 1)) == 0)
			return (ft_free(str, w));
		while (i < j)
			str[w][z++] = s[i++];
		str[w][z] = '\0';
		w++;
	}
	str[w] = 0;
	return (str);
}
