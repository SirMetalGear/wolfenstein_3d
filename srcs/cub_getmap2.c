#include "cub3d.h"

char		**ft_realloc(char **map, int add_mem, char *add)
{
	int		i;
	int		j;
	char	**tmp;

	i = 0;
	j = 0;
	if ((tmp = (char **)malloc(sizeof(char *) * add_mem + 2)) == 0)
		return (0);
	while (map[i] != 0)
	{
		tmp[j++] = ft_strdup(map[i]);
		free(map[i++]);
	}
	free(map);
	if (add != NULL)
		tmp[j++] = ft_strdup(add);
	tmp[j] = 0;
	return (tmp);
}

int			isempty(char **map, int x, int y)
{
	if (compare(map[x - 1][y], "NSWE0123") == 0)
		return (0);
	if (compare(map[x + 1][y], "NSWE0123") == 0)
		return (0);
	if (compare(map[x][y + 1], "NSWE0123") == 0)
		return (0);
	if (compare(map[x][y - 1], "NSWE0123") == 0)
		return (0);
	if (compare(map[x - 1][y + 1], "NSWE0123") == 0)
		return (0);
	if (compare(map[x - 1][y - 1], "NSWE0123") == 0)
		return (0);
	if (compare(map[x + 1][y - 1], "NSWE0123") == 0)
		return (0);
	if (compare(map[x + 1][y + 1], "NSWE0123") == 0)
		return (0);
	return (1);
}

int			zero_check(char **map, int x)
{
	int	y;

	y = -1;
	while (map[x][++y])
		if (compare(map[x][y], "NSWE023") == 1)
			return (0);
	x = -1;
	while (map[++x])
	{
		y = 0;
		if (map[x][y] == ' ')
			y++;
		if (compare(map[x][y], "NSWE023") == 1)
			return (0);
		y = ft_strlen(map[x]);
		if (compare(map[x][y], "NSWE023") == 1)
			return (0);
	}
	x = count_lines(map) - 1;
	y = -1;
	while (map[x][++y])
		if (compare(map[x][y], "NSWE023") == 1)
			return (0);
	return (1);
}

int			map_logic(char **map)
{
	int	x;
	int	y;

	x = 0;
	if (zero_check(map, x) == 0)
		return (0);
	while (map[x])
	{
		y = 0;
		while (map[x][y])
		{
			if (compare(map[x][y], "NSWE023") == 1)
				if (isempty(map, x, y) == 0)
					return (0);
			y++;
		}
		x++;
	}
	return (1);
}

void		player_pos_flag(t_all *all, int i, int j, char **map)
{
	all->map.p_pos[0] = i;
	all->map.p_pos[1] = j;
	if (map[i][j] == 'N')
		all->player.pos_flag = 1;
	if (map[i][j] == 'S')
		all->player.pos_flag = 2;
	if (map[i][j] == 'E')
		all->player.pos_flag = 3;
	if (map[i][j] == 'W')
		all->player.pos_flag = 4;
}
