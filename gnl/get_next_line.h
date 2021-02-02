/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlorette <mlorette@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/08 14:04:37 by mlorette          #+#    #+#             */
/*   Updated: 2020/12/03 22:57:53 by mlorette         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H
# include <fcntl.h>
# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>

int		get_next_line(int fd, char **line);
int		ft_get_line(int fd, char **line, char *ostatok);
void	*ft_calloc2(size_t count);
size_t	ft_strlen2(const char *str);
char	*ft_strjoin2(char *s1, char *s2, size_t stop, size_t stop2);
void	*ft_memmove2(void *dst, const void *src, size_t len);
void	ft_bzero2(void *b, size_t len);
int		filler(int fd, char **line, char *buf, int i);

#endif
