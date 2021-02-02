#include "cub3d.h"

void	tex_init2(t_all *all)
{
	all->tex_data[2].addr = mlx_get_data_addr(all->tex_data[2].img,
		&all->tex_data[2].bpp, &all->tex_data[2].line_length,
			&all->tex_data[2].endian);
	all->tex_data[4].img = mlx_xpm_file_to_image(all->pix.mlx, all->map.f,
		&all->tex.width[4], &all->tex.height[4]);
	all->tex_data[4].addr = mlx_get_data_addr(all->tex_data[4].img,
		&all->tex_data[4].bpp,
		&all->tex_data[4].line_length, &all->tex_data[4].endian);
	all->tex_data[5].img = mlx_xpm_file_to_image(all->pix.mlx, all->map.c,
		&all->tex.width[5], &all->tex.height[5]);
	all->tex_data[5].addr = mlx_get_data_addr(all->tex_data[5].img,
		&all->tex_data[5].bpp,
		&all->tex_data[5].line_length, &all->tex_data[5].endian);
	all->tex_data[6].img = mlx_xpm_file_to_image(all->pix.mlx, all->map.s,
		&all->tex.width[6], &all->tex.height[6]);
	all->tex_data[6].addr = mlx_get_data_addr(all->tex_data[6].img,
		&all->tex_data[6].bpp,
		&all->tex_data[6].line_length, &all->tex_data[6].endian);
	all->tex_data[7].img = mlx_xpm_file_to_image(all->pix.mlx,
		"./textures/portal.xpm", &all->tex.width[7], &all->tex.height[7]);
	all->tex_data[7].addr = mlx_get_data_addr(all->tex_data[7].img,
		&all->tex_data[7].bpp,
		&all->tex_data[7].line_length, &all->tex_data[7].endian);
}

void	tex_init(t_all *all)
{
	all->tex_data[1].img = mlx_xpm_file_to_image(all->pix.mlx, all->map.no,
		&all->tex.width[1], &all->tex.height[1]);
	all->tex_data[1].addr = mlx_get_data_addr(all->tex_data[1].img,
		&all->tex_data[1].bpp,
		&all->tex_data[1].line_length, &all->tex_data[1].endian);
	all->tex_data[3].img = mlx_xpm_file_to_image(all->pix.mlx, all->map.so,
		&all->tex.width[3], &all->tex.height[3]);
	all->tex_data[3].addr = mlx_get_data_addr(all->tex_data[3].img,
		&all->tex_data[3].bpp,
		&all->tex_data[3].line_length, &all->tex_data[3].endian);
	all->tex_data[0].img = mlx_xpm_file_to_image(all->pix.mlx, all->map.we,
		&all->tex.width[0], &all->tex.height[0]);
	all->tex_data[0].addr = mlx_get_data_addr(all->tex_data[0].img,
		&all->tex_data[0].bpp,
		&all->tex_data[0].line_length, &all->tex_data[0].endian);
	all->tex_data[2].img = mlx_xpm_file_to_image(all->pix.mlx, all->map.ea,
		&all->tex.width[2], &all->tex.height[2]);
}

int		player_n_s(t_all *all)
{
	if (all->player.pos_flag == 1)
	{
		all->player.xdir = -1;
		all->player.ydir = 0;
		all->player.xplane = 0;
		all->player.yplane = 0.66;
		return (1);
	}
	if (all->player.pos_flag == 2)
	{
		all->player.xdir = 1;
		all->player.ydir = 0;
		all->player.xplane = 0;
		all->player.yplane = -0.66;
		return (1);
	}
	return (0);
}

void	player_pos(t_all *all)
{
	if (player_n_s(all) == 1)
		return ;
	if (all->player.pos_flag == 3)
	{
		all->player.xdir = 0;
		all->player.ydir = 1;
		all->player.xplane = 0.66;
		all->player.yplane = 0;
	}
	if (all->player.pos_flag == 4)
	{
		all->player.xdir = 0;
		all->player.ydir = -1;
		all->player.xplane = -0.66;
		all->player.yplane = 0;
	}
}

void	ray_init(t_all *all)
{
	all->player.xpos = all->map.p_pos[0] + 0.5;
	all->player.ypos = all->map.p_pos[1];
	player_pos(all);
	all->ray.screen_height = all->map.y;
	all->ray.screen_widght = all->map.x;
	all->ray.movespeed = 0.1;
	all->ray.rotspeed = 0.04;
	all->move.moveflag1 = 0;
	all->move.moveflag2 = 0;
	all->move.moveflag3 = 0;
	all->move.moveflag4 = 0;
	all->move.moveflag5 = 0;
	all->move.moveflag6 = 0;
}
