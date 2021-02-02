#include "cub3d.h"

int	ft_next_level(t_all *all)
{
	char	*next_map[2];
	int		i;

	i = 0;
	all->map.next_map = 0;
	next_map[1] = ft_strdup("./maps/map2.cub");
	mlx_destroy_image(all->pix.mlx, all->img.img);
	mlx_destroy_window(all->pix.mlx, all->pix.win);
	system("pkill afplay");
	background_music(2);
	exit(main(2, next_map));
	return (0);
}
