#include "cub3d.h"

void	floor_calc(t_all *all, int y)
{
	all->floor.ray_dir_x0 = all->player.xdir - all->player.xplane;
	all->floor.ray_dir_y0 = all->player.ydir - all->player.yplane;
	all->floor.ray_dir_x1 = all->player.xdir + all->player.xplane;
	all->floor.ray_dir_y1 = all->player.ydir + all->player.yplane;
	all->floor.horizon = y - all->ray.screen_height / 2;
	all->floor.pos_z = 0.5 * all->ray.screen_height;
	all->floor.row_distance = all->floor.pos_z / all->floor.horizon;
	all->floor.floor_step_x = all->floor.row_distance * (all->floor.ray_dir_x1
		- all->floor.ray_dir_x0) / all->ray.screen_widght;
	all->floor.floor_step_y = all->floor.row_distance * (all->floor.ray_dir_y1
		- all->floor.ray_dir_y0) / all->ray.screen_widght;
	all->floor.floor_x = all->player.xpos + all->floor.row_distance *
		all->floor.ray_dir_x0;
	all->floor.floor_y = all->player.ypos + all->floor.row_distance *
		all->floor.ray_dir_y0;
}

int		floor_cast(t_all *all)
{
	int		y;
	int		x;

	y = all->ray.screen_height / 2 + 1;
	while (++y < all->ray.screen_height)
	{
		floor_calc(all, y);
		x = -1;
		while (++x < all->ray.screen_widght)
		{
			all->floor.cell_x = (int)(all->floor.floor_x);
			all->floor.cell_y = (int)(all->floor.floor_y);
			all->floor.tex_x = (int)(all->tex.width[4] * (all->floor.floor_x
				- all->floor.cell_x)) & (all->tex.width[4] - 1);
			all->floor.tex_y = (int)(all->tex.height[4] * (all->floor.floor_y
				- all->floor.cell_y)) & (all->tex.height[4] - 1);
			all->floor.floor_x += all->floor.floor_step_x;
			all->floor.floor_y += all->floor.floor_step_y;
			my_mlx_pixel_put(all, x, y, tex_color(all, all->floor.tex_x,
				all->floor.tex_y, 4));
		}
	}
	ceil_cast(all);
	return (0);
}

void	ceil_calc(t_all *all, int y)
{
	all->floor.ray_dir_x0 = all->player.xdir - all->player.xplane;
	all->floor.ray_dir_y0 = all->player.ydir - all->player.yplane;
	all->floor.ray_dir_x1 = all->player.xdir + all->player.xplane;
	all->floor.ray_dir_y1 = all->player.ydir + all->player.yplane;
	all->floor.horizon = y - all->ray.screen_height / 2;
	all->floor.pos_z = 0.5 * all->ray.screen_height;
	all->floor.row_distance = all->floor.pos_z / all->floor.horizon;
	all->floor.floor_step_x = all->floor.row_distance * (all->floor.ray_dir_x1
		- all->floor.ray_dir_x0) / all->ray.screen_widght;
	all->floor.floor_step_y = all->floor.row_distance * (all->floor.ray_dir_y1
		- all->floor.ray_dir_y0) / all->ray.screen_widght;
	all->floor.floor_x = all->player.xpos + all->floor.row_distance *
		all->floor.ray_dir_x0;
	all->floor.floor_y = all->player.ypos + all->floor.row_distance *
		all->floor.ray_dir_y0;
}

int		ceil_cast(t_all *all)
{
	int		y;
	int		x;

	y = all->ray.screen_height / 2 + 1;
	while (++y < all->ray.screen_height)
	{
		ceil_calc(all, y);
		x = -1;
		while (++x < all->ray.screen_widght)
		{
			all->floor.cell_x = (int)(all->floor.floor_x);
			all->floor.cell_y = (int)(all->floor.floor_y);
			all->floor.tex_x = (int)(all->tex.width[5] * (all->floor.floor_x
				- all->floor.cell_x)) & (all->tex.width[5] - 1);
			all->floor.tex_y = (int)(all->tex.height[5] * (all->floor.floor_y
				- all->floor.cell_y)) & (all->tex.height[5] - 1);
			all->floor.floor_x += all->floor.floor_step_x;
			all->floor.floor_y += all->floor.floor_step_y;
			my_mlx_pixel_put(all, x, all->ray.screen_height - 1 - y,
				tex_color(all, all->floor.tex_x, all->floor.tex_y, 5));
		}
	}
	return (0);
}
