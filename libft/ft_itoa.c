/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlorette <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/02 11:30:52 by mlorette          #+#    #+#             */
/*   Updated: 2020/11/06 16:41:47 by mlorette         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_count(int n)
{
	int	i;

	i = 0;
	if (n == 0)
		i++;
	if (n < 0)
	{
		n = n * -1;
		i++;
	}
	while (n != 0 && n > 0)
	{
		n = n / 10;
		i++;
	}
	return (i);
}

static char	*ft_costil(char *s)
{
	char	*ko;
	int		i;

	i = 0;
	ko = malloc(sizeof(char) * 11 + 1);
	while (s[i] != 0)
	{
		ko[i] = s[i];
		i++;
	}
	ko[i] = '\0';
	return (ko);
}

static char	*ft_rev(char *str)
{
	int		i;
	int		j;
	char	c;

	i = 0;
	c = '\0';
	j = ft_strlen(str) - 1;
	while (i < j)
	{
		c = str[i];
		str[i] = str[j];
		str[j] = c;
		i++;
		j--;
	}
	str[ft_strlen(str)] = '\0';
	return (str);
}

static char	*ft_zero(void)
{
	char	*str;

	if ((str = malloc(sizeof(char) * 1 + 1)) == 0)
		return (0);
	str[0] = '0';
	str[1] = '\0';
	return (str);
}

char		*ft_itoa(int n)
{
	int		i;
	char	*str;
	int		z;

	i = 0;
	z = n;
	if (n == -2147483648)
		return (ft_costil("-2147483648"));
	if (n == 0)
		return (ft_zero());
	if ((str = malloc(sizeof(char) * ft_count(n) + 1)) == 0)
		return (0);
	if (n < 0)
		n = n * -1;
	while (n)
	{
		str[i++] = n % 10 + '0';
		n = n / 10;
	}
	if (z < 0)
		str[i++] = '-';
	str[i] = '\0';
	return (ft_rev(str));
}
