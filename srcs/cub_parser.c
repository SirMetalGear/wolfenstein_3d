#include "cub3d.h"

int	data_parser(char **map, t_all *all)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (map[i])
	{
		while (map[i][j])
		{
			while (map[i][j] == ' ')
				j++;
			if (map[i][j] == 'R' && map[i][j + 1] == ' ')
				if (res_parser(map[i], j, all) == 0)
					return (0);
			if ((tex_checker(map, i, j, all) == 0))
				return (0);
			break ;
		}
		j = 0;
		i++;
	}
	return (1);
}

int	map_cmp(char **map, int i, int j)
{
	int	z;

	z = 0;
	if (ft_strncmp(&map[i][j], "R ", 2) == 0)
		z++;
	if (ft_strncmp(&map[i][j], "NO ", 3) == 0)
		z++;
	if (ft_strncmp(&map[i][j], "WE ", 3) == 0)
		z++;
	if (ft_strncmp(&map[i][j], "SO ", 3) == 0)
		z++;
	if (ft_strncmp(&map[i][j], "EA ", 3) == 0)
		z++;
	if (ft_strncmp(&map[i][j], "S ", 2) == 0)
		z++;
	if (ft_strncmp(&map[i][j], "F ", 2) == 0)
		z++;
	if (ft_strncmp(&map[i][j], "C ", 2) == 0)
		z++;
	return (z);
}

int	map_check(char **map)
{
	int	i;
	int	j;
	int	z;

	i = 0;
	j = 0;
	z = 0;
	while (map[i])
	{
		while (map[i][j] == ' ')
			j++;
		z += map_cmp(map, i, j);
		i++;
		j = 0;
	}
	if (z != 8)
		return (0);
	return (1);
}

int	texmap_checker(t_all *all)
{
	if (all->map.no == 0)
		return (0);
	if (all->map.so == 0)
		return (0);
	if (all->map.we == 0)
		return (0);
	if (all->map.ea == 0)
		return (0);
	if (all->map.s == 0)
		return (0);
	if (all->map.f == 0)
		return (0);
	if (all->map.c == 0)
		return (0);
	return (1);
}

int	map_parser(int fd, char **map, t_all *all)
{
	int		i;
	int		j;

	i = 0;
	j = 0;
	while (get_next_line(fd, &map[i]) && i < 7)
	{
		if (ft_strncmp(map[i], "\n", ft_strlen(map[i])))
			i++;
		else
			free(map[i]);
	}
	if (map_check(map) == 0)
		return (0);
	if (data_parser(map, all) == 0)
		return (0);
	if (texmap_checker(all) == 0)
		return (0);
	return (1);
}
