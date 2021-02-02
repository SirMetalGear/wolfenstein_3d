#include "cub3d.h"

int				get_pixel_color(t_all *all, int x, int y)
{
	char			*dst;
	unsigned int	color;

	dst = all->img.addr + (x * all->img.line_length +
		y * (all->img.bpp / 8));
	color = *(unsigned int*)dst;
	return (color);
}

int				screenshot(t_all *all)
{
	unsigned char	image[all->map.y][all->map.x][3];
	int				i;
	int				j;

	i = -1;
	while (++i < all->ray.screen_height)
	{
		j = all->ray.screen_widght;
		while (--j >= 0)
		{
			image[i][j][2] = get_pixel_color(all, i, j) >> 16 & 0xFF;
			image[i][j][1] = get_pixel_color(all, i, j) >> 8 & 0xFF;
			image[i][j][0] = get_pixel_color(all, i, j) & 0xFF;
		}
	}
	if ((generate_bitmap_image((unsigned char*)image,
		all->ray.screen_height, all->ray.screen_widght)) == 0)
		return (0);
	write(1, "Screeshot has been created!\n", 28);
	return (1);
}

int				generate_bitmap_image(unsigned char *image,
	int height, int width)
{
	int					width_in_bytes;
	const unsigned char	padding[3] = {0, 0, 0};
	int					padding_size;
	int					stride;
	int					fd;

	width_in_bytes = width * 3;
	padding_size = (4 - (width_in_bytes) % 4) % 4;
	stride = (width_in_bytes) + padding_size;
	if ((fd = open("shot.bmp", O_RDWR | O_CREAT | O_TRUNC, S_IRWXU)) == 0)
		return (0);
	if ((write(fd, create_bmp_header(height, width, stride), 54)) < 53)
		return (0);
	while (--height >= 0)
	{
		write(fd, image + (height * width_in_bytes), 3 * width);
		write(fd, padding, padding_size);
	}
	close(fd);
	return (1);
}

unsigned char	*create_bmp_header(int height, int width, int stride)
{
	int						file_size;
	static unsigned char	file_header[54];

	file_size = 14 + 40 + (stride * height);
	file_header[0] = (unsigned char)('B');
	file_header[1] = (unsigned char)('M');
	file_header[2] = (unsigned char)(file_size);
	file_header[3] = (unsigned char)(file_size >> 8);
	file_header[4] = (unsigned char)(file_size >> 16);
	file_header[5] = (unsigned char)(file_size >> 24);
	file_header[10] = (unsigned char)(14 + 40);
	file_header[14 + 0] = (unsigned char)(40);
	file_header[14 + 4] = (unsigned char)(width);
	file_header[14 + 5] = (unsigned char)(width >> 8);
	file_header[14 + 6] = (unsigned char)(width >> 16);
	file_header[14 + 7] = (unsigned char)(width >> 24);
	file_header[14 + 8] = (unsigned char)(height);
	file_header[14 + 9] = (unsigned char)(height >> 8);
	file_header[14 + 10] = (unsigned char)(height >> 16);
	file_header[14 + 11] = (unsigned char)(height >> 24);
	file_header[14 + 12] = (unsigned char)(1);
	file_header[14 + 14] = (unsigned char)(3 * 8);
	return (file_header);
}

int				ft_save(t_all *all)
{
	all->map.save_flag = 1;
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
	ray_cast(all);
	if ((screenshot(all)) == 0)
		return (0);
	return (1);
}
