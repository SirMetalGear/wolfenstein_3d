/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlorette <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/30 14:16:46 by mlorette          #+#    #+#             */
/*   Updated: 2020/10/31 17:55:55 by mlorette         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dst, const void *src, size_t len)
{
	size_t i;

	i = 0;
	if (dst <= src)
		return (ft_memcpy(dst, src, len));
	else
	{
		if (dst == 0 && src == 0)
			return (0);
		i = len - 1;
		while (i + 1 > 0)
		{
			*((char *)dst + i) = *((char *)src + i);
			i--;
		}
		return ((char *)dst);
	}
}
