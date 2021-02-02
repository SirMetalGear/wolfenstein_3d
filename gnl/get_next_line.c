/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlorette <mlorette@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/06 20:06:13 by mlorette          #+#    #+#             */
/*   Updated: 2020/12/03 22:57:42 by mlorette         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

int		filler(int fd, char **line, char *buf, int i)
{
	while (buf[i] != 0)
	{
		if (buf[i] == '\n')
		{
			*line = ft_strjoin2(*line, buf, i, ft_strlen2(*line));
			ft_memmove2(buf, buf + i + 1, ft_strlen2(buf));
			ft_bzero2(&buf[BUFFER_SIZE - i - 1], i + 1);
			return (1);
		}
		i++;
		if (buf[i] == '\0')
		{
			*line = ft_strjoin2(*line, buf, i, ft_strlen2(*line));
			ft_bzero2(buf, ft_strlen2(buf));
			if ((read(fd, buf, BUFFER_SIZE) == 0))
				return (0);
			i = 0;
		}
	}
	return (-1);
}

int		ft_get_line(int fd, char **line, char *buf)
{
	size_t	i;

	i = 0;
	if (buf[i] == '\0')
	{
		*line = ft_strjoin2(*line, buf, i, ft_strlen2(*line));
		ft_bzero2(buf, ft_strlen2(buf));
		if ((read(fd, buf, BUFFER_SIZE) == 0))
			return (0);
	}
	if (filler(fd, line, buf, i) == 1)
		return (1);
	return (0);
}

int		get_next_line(int fd, char **line)
{
	static char	*buf;
	int			z;

	*line = ft_calloc2(1);
	if (buf == NULL)
	{
		if (!(buf = ft_calloc2(BUFFER_SIZE + 1)))
			return (-1);
		if ((read(fd, buf, BUFFER_SIZE) < 0))
		{
			free(buf);
			return (-1);
		}
	}
	z = ft_get_line(fd, line, buf);
	if (z == 0)
	{
		free(buf);
		buf = 0;
	}
	return (z);
}
