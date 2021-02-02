#include "cub3d.h"

int			scene_checker(char **map, t_all *all)
{
	int	i;
	int	j;
	int	flag;

	i = -1;
	flag = 0;
	while (map[++i])
	{
		j = -1;
		while (map[i][++j])
		{
			if (compare(map[i][j], "NSWE0123 ") == 0)
				return (0);
			if (compare(map[i][j], "NSWE") == 1)
			{
				player_pos_flag(all, i, j, map);
				flag++;
			}
		}
		if (j == 0)
			return (0);
	}
	if (flag > 1 || flag == 0)
		return (0);
	return (1);
}

void		cutter(char **map, int j)
{
	int	i;

	i = 0;
	j--;
	while (map[j][0] == 0)
	{
		free(map[j]);
		map[j] = 0;
		j--;
	}
}

char		**ft_record(char **map, char *tmp, int fd)
{
	int	i;

	i = 0;
	while (get_next_line(fd, &tmp))
	{
		if (ft_strncmp(tmp, "\n", ft_strlen(tmp)) == 0)
		{
			if (i > 1)
				return (0);
		}
		else
			map = ft_realloc(map, ++i, tmp);
		free(tmp);
	}
	if (ft_strncmp(tmp, "\n", ft_strlen(tmp)) == 0)
	{
		if (i > 1)
			return (0);
	}
	else
		map = ft_realloc(map, ++i, tmp);
	free(tmp);
	return (map);
}

char		**get_map(int fd, t_all *all)
{
	char	*tmp;
	char	**map;

	tmp = 0;
	map = (char **)ft_calloc(sizeof(char *), 1);
	if ((map = ft_record(map, tmp, fd)) == 0)
		return (0);
	cutter(map, count_lines(map));
	if (scene_checker(map, all) == 0)
		return (0);
	if (map_logic(map) == 0)
		return (0);
	return (map);
}
