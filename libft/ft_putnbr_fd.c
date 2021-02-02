/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlorette <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/02 16:22:39 by mlorette          #+#    #+#             */
/*   Updated: 2020/11/02 16:30:28 by mlorette         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_putnbr_fd(int n, int fd)
{
	unsigned int		nb1;
	char				stroka[10];
	char				c;
	int					x;
	int					i;

	nb1 = n;
	i = 0;
	if (n == 0)
		write(fd, "0", 1);
	if (n < 0)
	{
		write(fd, "-", 1);
		nb1 = (n * -1);
	}
	while (nb1 != 0)
	{
		x = (nb1 % 10);
		nb1 = (nb1 / 10);
		c = (x + '0');
		*(stroka + (i++)) = c;
	}
	while ((i--) != 0)
		write(fd, (stroka + i), 1);
}
