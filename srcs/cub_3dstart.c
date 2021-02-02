#include "cub3d.h"

unsigned int	tex_color(t_all *all, int x, int y, int z)
{
	char			*dst;
	unsigned int	color;

	dst = all->tex_data[z].addr + (y * all->tex_data[z].line_length +
		x * (all->tex_data[z].bpp / 8));
	color = *(unsigned int*)dst;
	return (color);
}

void			my_mlx_pixel_put(t_all *all, int x, int y, int color)
{
	char	*dst;

	dst = all->img.addr + (y * all->img.line_length + x * (all->img.bpp / 8));
	*(unsigned int*)dst = color;
}

int				esc_exit(t_all *all)
{
	int	i;

	i = 0;
	while (all->map.map[i])
		free(all->map.map[i++]);
	free(all->map.map);
	free(all->map.no);
	free(all->map.so);
	free(all->map.we);
	free(all->map.ea);
	free(all->map.s);
	system("pkill afplay");
	exit(1);
	return (1);
}

int				mlx_start(t_all *all)
{
	all->pix.mlx = mlx_init();
	if ((all->pix.win = mlx_new_window(all->pix.mlx, all->map.x, all->map.y,
		"CUBED")) == 0)
		return (0);
	all->img.img = mlx_new_image(all->pix.mlx, all->map.x, all->map.y);
	all->img.addr = mlx_get_data_addr(all->img.img, &all->img.bpp,
	&all->img.line_length, &all->img.endian);
	ray_init(all);
	tex_init(all);
	tex_init2(all);
	mlx_hook(all->pix.win, 2, 0, key_flagon, all);
	mlx_hook(all->pix.win, 17, 0, esc_exit, all);
	mlx_hook(all->pix.win, 3, 0, key_flagoff, all);
	mlx_hook(all->pix.win, 6, 0, mouse_move, all);
	mlx_loop_hook(all->pix.mlx, ray_cast, all);
	mlx_loop(all->pix.mlx);
	return (0);
}
