#include "cub3d.h"

void	tex_pixel_put(t_all *all, int w)
{
	int	z;

	z = get_tex_params(all);
	if (all->ray.side == 0)
		all->tex.wall_x = all->player.ypos + all->ray.ray_dist_to_plane *
			all->ray.ray_diry;
	else
		all->tex.wall_x = all->player.xpos + all->ray.ray_dist_to_plane *
			all->ray.ray_dirx;
	all->tex.wall_x -= floor(all->tex.wall_x);
	all->tex.tex_x = (int)(all->tex.wall_x * (double)(all->tex.width[z]));
	if (all->ray.side == 0 && all->ray.ray_dirx > 0)
		all->tex.tex_x = all->tex.width[z] - all->tex.tex_x - 1;
	if (all->ray.side == 1 && all->ray.ray_diry < 0)
		all->tex.tex_x = all->tex.width[z] - all->tex.tex_x - 1;
	all->tex.step = 1.0 * all->tex.height[z] / all->ray.height_of_line;
	all->tex.tex_pos = (all->ray.start_point - all->ray.screen_height / 2
		+ all->ray.height_of_line / 2) * all->tex.step;
	while (all->ray.start_point < all->ray.end_point)
	{
		all->tex.tex_y = (int)all->tex.tex_pos & (all->tex.height[z] - 1);
		all->tex.tex_pos += all->tex.step;
		my_mlx_pixel_put(all, w, all->ray.start_point++, tex_color(all,
			all->tex.tex_x, all->tex.tex_y, z));
	}
}

void	ray_calc(t_all *all, int w)
{
	all->ray.camera = 2 * w / all->ray.screen_widght - 1;
	all->ray.ray_dirx = all->player.xdir + all->player.xplane * all->ray.camera;
	all->ray.ray_diry = all->player.ydir + all->player.yplane * all->ray.camera;
	all->ray.map_x = all->player.xpos;
	all->ray.map_y = all->player.ypos;
	if (all->ray.ray_diry == 0)
		all->ray.dist_to_next_xpos = 0;
	else if (all->ray.ray_dirx == 0)
		all->ray.dist_to_next_xpos = 0;
	else
		all->ray.dist_to_next_xpos = fabs(1 / all->ray.ray_dirx);
	if (all->ray.ray_dirx == 0)
		all->ray.dist_to_next_ypos = 0;
	else if (all->ray.ray_dirx == 0)
		all->ray.dist_to_next_ypos = 0;
	else
		all->ray.dist_to_next_ypos = fabs(1 / all->ray.ray_diry);
}

void	ray_step_calc(t_all *all)
{
	if (all->ray.ray_dirx < 0)
	{
		all->ray.step_x = -1;
		all->ray.xray_lenght = (all->player.xpos - all->ray.map_x) *
			all->ray.dist_to_next_xpos;
	}
	else
	{
		all->ray.step_x = 1;
		all->ray.xray_lenght = (all->ray.map_x + 1.0 - all->player.xpos) *
			all->ray.dist_to_next_xpos;
	}
	if (all->ray.ray_diry < 0)
	{
		all->ray.step_y = -1;
		all->ray.yray_lenght = (all->player.ypos - all->ray.map_y) *
			all->ray.dist_to_next_ypos;
	}
	else
	{
		all->ray.step_y = 1;
		all->ray.yray_lenght = (all->ray.map_y + 1.0 - all->player.ypos)
			* all->ray.dist_to_next_ypos;
	}
}

void	ray_hit_wall(t_all *all)
{
	all->ray.hit = 0;
	while (all->ray.hit == 0)
	{
		if (all->ray.xray_lenght < all->ray.yray_lenght)
		{
			all->ray.xray_lenght += all->ray.dist_to_next_xpos;
			all->ray.map_x += all->ray.step_x;
			all->ray.side = 0;
		}
		else
		{
			all->ray.yray_lenght += all->ray.dist_to_next_ypos;
			all->ray.map_y += all->ray.step_y;
			all->ray.side = 1;
		}
		if (all->map.map[(int)all->ray.map_x][(int)all->ray.map_y] == '1')
			all->ray.hit = 1;
	}
	if (all->ray.side == 0)
		all->ray.ray_dist_to_plane = (all->ray.map_x - all->player.xpos +
			((1 - all->ray.step_x) / 2)) / all->ray.ray_dirx;
	else
		all->ray.ray_dist_to_plane = (all->ray.map_y - all->player.ypos +
			((1 - all->ray.step_y) / 2)) / all->ray.ray_diry;
}
