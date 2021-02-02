#include "cub3d.h"

void	ray_line_height(t_all *all)
{
	all->ray.height_of_line = (int)(all->ray.screen_height /
		all->ray.ray_dist_to_plane);
	all->ray.start_point = -all->ray.height_of_line / 2 +
		all->ray.screen_height / 2;
	if (all->ray.start_point < 0)
		all->ray.start_point = 0;
	all->ray.end_point = all->ray.height_of_line / 2 +
		all->ray.screen_height / 2;
	if (all->ray.end_point >= all->ray.screen_height)
		all->ray.end_point = all->ray.screen_height - 1;
	if (all->ray.end_point % 2 != 0)
		all->ray.end_point += 0.035;
	if (all->ray.start_point % 2 != 0)
		all->ray.start_point += 0.035;
}

int		get_tex_params(t_all *all)
{
	int	a;

	if (all->player.xpos >= all->ray.map_x && all->player.ypos >=
		all->ray.map_y)
		a = all->ray.side == 1 ? 0 : 1;
	else if (all->player.xpos >= all->ray.map_x && all->player.ypos <=
		all->ray.map_y)
		a = all->ray.side == 1 ? 2 : 1;
	else if (all->player.xpos <= all->ray.map_x && all->player.ypos <=
		all->ray.map_y)
		a = all->ray.side == 1 ? 2 : 3;
	else
		a = all->ray.side == 1 ? 0 : 3;
	return (a);
}

int		ray_cast(t_all *all)
{
	int		w;
	double	buffer_w[(int)all->ray.screen_widght];

	w = -1;
	movement(all);
	key_mouse_flagoff(all);
	floor_cast(all);
	while (++w <= all->ray.screen_widght)
	{
		ray_calc(all, w);
		ray_step_calc(all);
		ray_hit_wall(all);
		ray_line_height(all);
		tex_pixel_put(all, w);
		buffer_w[w] = all->ray.ray_dist_to_plane;
	}
	sprite_cast(all, buffer_w, 6, '2');
	sprite_cast(all, buffer_w, 7, '3');
	mlx_put_image_to_window(all->pix.mlx, all->pix.win, all->img.img, 0, 0);
	if (all->map.save_flag == 0)
	{
		mlx_destroy_image(all->pix.mlx, all->img.img);
		all->img.img = mlx_new_image(all->pix.mlx, all->map.x, all->map.y);
	}
	return (0);
}
