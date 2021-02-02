#include "cub3d.h"

void	freesher(char **trash)
{
	int	i;

	i = 0;
	while (trash[i] != 0)
		free(trash[i++]);
	if (trash)
		free(trash);
}

int		error_exit(t_all *all, int x, char **data)
{
	int	i;

	(void)data;
	i = 0;
	if (x == 0)
		write(1, "map error\n", 10);
	if (data)
	{
		while (data[i])
			free(data[i++]);
		free(data);
	}
	if (x == 1)
		return (1);
	if (all->map.no)
		free(all->map.no);
	if (all->map.so)
		free(all->map.so);
	if (all->map.we)
		free(all->map.we);
	if (all->map.ea)
		free(all->map.ea);
	if (all->map.s)
		free(all->map.s);
	return (0);
}

int		count_lines(char **map)
{
	int	i;

	i = 0;
	while (map[i])
		i++;
	return (i);
}

size_t	ft_count(int n)
{
	size_t			i;
	unsigned int	z;

	i = 0;
	z = n;
	if (n == 0)
		i++;
	while (z)
	{
		z = z / 10;
		i++;
	}
	return (i);
}

int		compare(char s1, char *s2)
{
	int j;

	j = 0;
	while (s2[j])
	{
		if (s1 == s2[j])
			return (1);
		j++;
	}
	return (0);
}
