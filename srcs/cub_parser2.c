#include "cub3d.h"

int		res_parser(char *map, int j, t_all *all)
{
	j++;
	while (map[j] == ' ')
		j++;
	j += ft_count(all->map.x = ft_atoi(&map[j]));
	while (map[j] == ' ')
		j++;
	j += ft_count(all->map.y = ft_atoi(&map[j]));
	while (map[j] != 0)
		if (map[j++] != ' ')
			return (0);
	if (all->map.x > 2560)
		all->map.x = 2560;
	if (all->map.y > 1440)
		all->map.y = 1440;
	if (all->map.x >= 1 && all->map.y >= 1)
		return (1);
	return (0);
}

char	*texture_parser(char *map, int j)
{
	int		i;
	int		fd;
	char	*tex;

	i = 0;
	j += 2;
	while (map[j] == ' ')
		j++;
	if ((tex = ft_strdup(&map[j])) == 0)
		return (0);
	while (map[j] != ' ' && map[j] != 0)
		tex[i++] = map[j++];
	tex[i] = '\0';
	while (map[j] != 0)
		if (map[j++] != ' ')
			return (0);
	if ((fd = open(tex, O_RDONLY)) <= 0)
		return (0);
	close(fd);
	return (tex);
}

int		skip_to_next(char *map, int j)
{
	int	i;

	i = j;
	if (map[j] == ',')
		j++;
	while (map[j] == ' ')
		j++;
	if (map[j] == ',')
		j++;
	while (map[j] == ' ')
		j++;
	return (j - i);
}

int		color_parser(char *map, int *paint, int j)
{
	int	i;

	j++;
	i = j - 1;
	while (map[++i] != 0)
		if (map[i] != ' ' && map[i] != ',' && (map[i] <= '0' && map[i] >= '9'))
			return (0);
	while (!(map[j] <= '9' && map[j] >= '0'))
	{
		if (map[j] != ' ')
			return (0);
		j++;
	}
	j += ft_count(paint[0] = ft_atoi(&map[j]));
	j += skip_to_next(map, j);
	j += ft_count(paint[1] = ft_atoi(&map[j]));
	j += skip_to_next(map, j);
	j += ft_count(paint[2] = ft_atoi(&map[j]));
	while (map[j] != 0)
		if (map[j++] != ' ')
			return (0);
	if (paint[0] >= 0 && paint[0] <= 255 && paint[1] >= 0 && paint[1] <= 255
	&& paint[2] >= 0 && paint[2] <= 255)
		return (1);
	return (0);
}

int		tex_checker(char **map, int i, int j, t_all *all)
{
	if (map[i][j] == 'N' && map[i][j + 1] == 'O' && map[i][j + 2] == ' ')
		if ((all->map.no = texture_parser(map[i], j)) == 0)
			return (0);
	if (map[i][j] == 'S' && map[i][j + 1] == 'O' && map[i][j + 2] == ' ')
		if ((all->map.so = texture_parser(map[i], j)) == 0)
			return (0);
	if (map[i][j] == 'W' && map[i][j + 1] == 'E' && map[i][j + 2] == ' ')
		if ((all->map.we = texture_parser(map[i], j)) == 0)
			return (0);
	if (map[i][j] == 'E' && map[i][j + 1] == 'A' && map[i][j + 2] == ' ')
		if ((all->map.ea = texture_parser(map[i], j)) == 0)
			return (0);
	if (map[i][j] == 'S' && map[i][j + 1] == ' ')
		if ((all->map.s = texture_parser(map[i], j)) == 0)
			return (0);
	if (map[i][j] == 'F' && map[i][j + 1] == ' ')
		if ((all->map.f = texture_parser(map[i], j)) == 0)
			return (0);
	if (map[i][j] == 'C' && map[i][j + 1] == ' ')
		if ((all->map.c = texture_parser(map[i], j)) == 0)
			return (0);
	return (1);
}
