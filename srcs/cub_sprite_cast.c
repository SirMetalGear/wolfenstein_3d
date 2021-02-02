#include "cub3d.h"

void	sprite_calc(t_all *all, int i, int j)
{
	all->sprite.sprite_x = all->sprite.sprite[j][i][0] - all->player.xpos + 0.5;
	all->sprite.sprite_y = all->sprite.sprite[j][i][1] - all->player.ypos + 0.5;
	all->sprite.inv_det = 1.0 / (all->player.xplane * all->player.ydir -
		all->player.xdir * all->player.yplane);
	all->sprite.depth_x = all->sprite.inv_det * (all->player.ydir *
		all->sprite.sprite_x - all->player.xdir * all->sprite.sprite_y);
	all->sprite.depth_y = all->sprite.inv_det * (-all->player.yplane *
		all->sprite.sprite_x + all->player.xplane * all->sprite.sprite_y);
	all->sprite.pos_on_screen = (int)((all->ray.screen_widght / 2) *
		(1 + all->sprite.depth_x / all->sprite.depth_y));
	all->sprite.sprite_height = fabs((all->ray.screen_height /
		(all->sprite.depth_y)));
	all->sprite.start_point_x = -all->sprite.sprite_height / 2 +
		all->ray.screen_height / 2;
}

void	sprite_start_end(t_all *all)
{
	if (all->sprite.start_point_x < 0)
		all->sprite.start_point_x = 0;
	all->sprite.start_point_y = all->sprite.sprite_height / 2 +
		all->ray.screen_height / 2;
	if (all->sprite.start_point_y >= all->ray.screen_height)
		all->sprite.start_point_y = all->ray.screen_height - 1;
	all->sprite.sprite_width = fabs((all->ray.screen_height /
		(all->sprite.depth_y)));
	all->sprite.stop_point_y = -all->sprite.sprite_width / 2 +
		all->sprite.pos_on_screen;
	if (all->sprite.stop_point_y < 0)
		all->sprite.stop_point_y = 0;
	all->sprite.stop_point_x = all->sprite.sprite_width / 2 +
		all->sprite.pos_on_screen;
	if (all->sprite.stop_point_x >= all->ray.screen_widght)
		all->sprite.stop_point_x = all->ray.screen_widght - 1;
}

void	sprite_stroke_draw(t_all *all, int z)
{
	int				y;
	int				d;
	unsigned int	color;

	y = all->sprite.start_point_x - 1;
	while (++y < all->sprite.start_point_y)
	{
		d = (y) * 256 - all->ray.screen_height * 128 +
			all->sprite.sprite_height * 128;
		all->sprite.tex_y = ((d * all->tex.height[z]) /
			all->sprite.sprite_height) / 256;
		color = tex_color(all, all->sprite.tex_x, all->sprite.tex_y, z);
		if ((color & 0x00FFFFFF) != 0)
			my_mlx_pixel_put(all, all->sprite.stroke, y, color);
	}
}

void	sprite_cast(t_all *all, double *buffer_w, int z, char sprite)
{
	int	i;

	i = -1;
	all->sprite.sprite_num = sprite_count(all, sprite);
	sort_sprites(all->sprite.sprite_num, all, 0);
	while (++i < all->sprite.sprite_num)
	{
		if (z == 7)
			sprite_calc(all, i, 1);
		else
			sprite_calc(all, i, 0);
		sprite_start_end(all);
		all->sprite.stroke = all->sprite.stop_point_y - 1;
		while (++all->sprite.stroke < all->sprite.stop_point_x)
		{
			all->sprite.tex_x = (int)(256 * (all->sprite.stroke -
				(-all->sprite.sprite_width / 2 + all->sprite.pos_on_screen))
					* all->tex.width[z] / all->sprite.sprite_width) / 256;
			if (all->sprite.depth_y > 0 && all->sprite.stroke > 0 &&
				all->sprite.stroke < all->ray.screen_widght &&
					all->sprite.depth_y < buffer_w[all->sprite.stroke])
				sprite_stroke_draw(all, z);
			all->map.portal_sprite = 0;
		}
	}
}
