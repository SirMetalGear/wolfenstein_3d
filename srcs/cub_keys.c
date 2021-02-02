#include "cub3d.h"

void	key_forward(t_all *all)
{
	double	x;
	double	y;

	x = all->player.xpos + (all->player.xdir * all->ray.movespeed);
	y = all->player.ypos + (all->player.ydir * all->ray.movespeed);
	if (all->map.map[(int)x][(int)(all->player.ypos)] != '1')
		if (all->map.map[(int)x][(int)(all->player.ypos)] != '2')
			all->player.xpos = x;
	if (all->map.map[(int)x][(int)(all->player.ypos)] == '3')
		all->map.next_map = 1;
	if (all->map.map[(int)(all->player.xpos)][(int)y] != '1')
		if (all->map.map[(int)(all->player.xpos)][(int)y] != '2')
			all->player.ypos = y;
	if (all->map.map[(int)(all->player.xpos)][(int)y] == '3')
		all->map.next_map = 1;
}

void	key_back(t_all *all)
{
	double	x;
	double	y;

	x = all->player.xpos - all->player.xdir * all->ray.movespeed;
	y = all->player.ypos - all->player.ydir * all->ray.movespeed;
	if (all->map.map[(int)x][(int)(all->player.ypos)] != '1')
		if (all->map.map[(int)x][(int)(all->player.ypos)] != '2')
			all->player.xpos = x;
	if (all->map.map[(int)x][(int)(all->player.ypos)] == '3')
		all->map.next_map = 1;
	if (all->map.map[(int)(all->player.xpos)][(int)y] != '1')
		if (all->map.map[(int)(all->player.xpos)][(int)y] != '2')
			all->player.ypos = y;
	if (all->map.map[(int)(all->player.xpos)][(int)y] == '3')
		all->map.next_map = 1;
}

void	key_left(t_all *all)
{
	double	x;
	double	y;

	x = all->player.xpos - all->player.ydir * all->ray.movespeed;
	y = all->player.ypos + all->player.xdir * all->ray.movespeed;
	if (all->map.map[(int)x][(int)(all->player.ypos)] != '1')
		if (all->map.map[(int)x][(int)(all->player.ypos)] != '2')
			all->player.xpos = x;
	if (all->map.map[(int)x][(int)(all->player.ypos)] == '3')
		all->map.next_map = 1;
	if (all->map.map[(int)(all->player.xpos)][(int)y] != '1')
		if (all->map.map[(int)(all->player.xpos)][(int)y] != '2')
			all->player.ypos = y;
	if (all->map.map[(int)(all->player.xpos)][(int)y] == '3')
		all->map.next_map = 1;
}

void	key_right(t_all *all)
{
	double	x;
	double	y;

	x = all->player.xpos + all->player.ydir * all->ray.movespeed;
	y = all->player.ypos - all->player.xdir * all->ray.movespeed;
	if (all->map.map[(int)x][(int)(all->player.ypos)] != '1')
		if (all->map.map[(int)x][(int)(all->player.ypos)] != '2')
			all->player.xpos = x;
	if (all->map.map[(int)x][(int)(all->player.ypos)] == '3')
		all->map.next_map = 1;
	if (all->map.map[(int)(all->player.xpos)][(int)y] != '1')
		if (all->map.map[(int)(all->player.xpos)][(int)y] != '2')
			all->player.ypos = y;
	if (all->map.map[(int)(all->player.xpos)][(int)y] == '3')
		all->map.next_map = 1;
}
