#include "cub3d.h"

int		sprite_count(t_all *all, char sprite)
{
	int x;
	int y;
	int sprite_num;

	x = -1;
	sprite_num = 0;
	while (all->map.map[++x])
	{
		y = -1;
		while (all->map.map[x][++y])
		{
			if (all->map.map[x][y] == sprite)
				sprite_num++;
		}
	}
	return (sprite_num);
}

int		**sprite_coordinates(t_all *all, char sprite)
{
	int		**sprite_coordinates;
	int		x;
	int		y;
	int		i;

	x = -1;
	i = -1;
	if ((sprite_coordinates = (int **)ft_calloc(sprite_count(all, sprite) + 1,
		sizeof(int *))) == 0)
		return (0);
	while (all->map.map[++x])
	{
		y = -1;
		while (all->map.map[x][++y])
		{
			if (all->map.map[x][y] == sprite)
			{
				if ((sprite_coordinates[++i] = ft_calloc(sizeof(int), 3)) == 0)
					return (0);
				sprite_coordinates[i][0] = x;
				sprite_coordinates[i][1] = y;
			}
		}
	}
	return (sprite_coordinates);
}

double	get_distance(t_all *all, int j)
{
	return (((all->player.xpos - all->sprite.sprite[0][j][0]) *
		(all->player.xpos - all->sprite.sprite[0][j][0]) + (all->player.ypos -
			all->sprite.sprite[0][j][1]) * (all->player.ypos -
				all->sprite.sprite[0][j][1])));
}

void	sort_sprites(int amount, t_all *all, int z)
{
	int		j;
	double	distance1;
	double	distance2;
	int		x;
	int		y;

	j = -1;
	while (++j < amount - 1)
	{
		distance1 = get_distance(all, j);
		distance2 = get_distance(all, j + 1);
		if (distance1 < distance2)
		{
			x = all->sprite.sprite[z][j][0];
			y = all->sprite.sprite[z][j][1];
			all->sprite.sprite[z][j][0] = all->sprite.sprite[z][j + 1][0];
			all->sprite.sprite[z][j][1] = all->sprite.sprite[z][j + 1][1];
			all->sprite.sprite[z][j + 1][0] = x;
			all->sprite.sprite[z][j + 1][1] = y;
			j = -1;
		}
	}
}
