/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlorette <mlorette@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/31 19:52:42 by mlorette          #+#    #+#             */
/*   Updated: 2020/12/07 14:27:43 by mlorette         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	int		i;
	int		j;
	char	*fin;

	i = 0;
	j = 0;
	fin = malloc(ft_strlen(s1) + ft_strlen(s2) + 1);
	if (fin == NULL)
		return (NULL);
	while (s1[i] != 0)
	{
		fin[i] = s1[i];
		i++;
	}
	while (s2[j] != 0)
	{
		fin[i] = s2[j];
		j++;
		i++;
	}
	fin[i] = '\0';
	return (fin);
}
