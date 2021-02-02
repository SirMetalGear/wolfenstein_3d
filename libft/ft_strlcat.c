/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlorette <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/29 13:35:03 by mlorette          #+#    #+#             */
/*   Updated: 2020/11/02 21:25:02 by mlorette         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *d, const char *s, size_t n)
{
	size_t	i;
	size_t	j;
	size_t	k;

	j = 0;
	i = 0;
	k = 0;
	while (d[k] != 0 && k < n)
		k++;
	j = k;
	if (n == 0)
		return (ft_strlen(s));
	while (i < n - 1 && j < n - 1 && s[i] != 0)
	{
		d[j] = s[i];
		j++;
		i++;
	}
	if (n != 0 && k < n)
		d[j] = '\0';
	return (k + ft_strlen(s));
}
