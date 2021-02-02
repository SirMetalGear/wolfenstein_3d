#include "cub3d.h"

void			struct_init(t_all *all)
{
	all->map.no = 0;
	all->map.so = 0;
	all->map.we = 0;
	all->map.ea = 0;
	all->map.s = 0;
	all->map.save_flag = 0;
	all->map.next_map = 0;
	all->map.portal_x = 0;
	all->map.portal_y = 0;
}

int				data_collect(char **argv, t_all *all)
{
	int		fd;
	char	**data;
	char	**map;

	if ((data = (char **)ft_calloc(8 + 1, sizeof(char *))) == 0)
		return (0);
	if ((fd = open(argv[1], O_RDONLY)) < 0)
		return (error_exit(all, 0, data));
	if ((map_parser(fd, data, all) == 0))
		return (error_exit(all, 0, data));
	error_exit(all, 1, data);
	if ((map = get_map(fd, all)) == 0)
		return (error_exit(all, 0, map));
	close(fd);
	if ((all->map.map = ft_realloc(map, count_lines(map) - 1, 0)) == 0)
		return (error_exit(all, 0, map));
	return (1);
}

void			background_music(int f)
{
	int	pid;

	pid = fork();
	if (f == 1)
	{
		if (pid == 0)
			system("afplay ./sounds/music.mp3");
		if (pid == 0)
			exit(0);
	}
	if (f == 2)
	{
		if (pid == 0)
			system("afplay ./sounds/portal_sound.mp3");
		if (pid == 0)
			exit(0);
	}
}

int				main(int argc, char **argv)
{
	t_all	all;

	if (argc > 3 || argc < 2)
		return (write(1, "Wrong arguments\n", 16));
	struct_init(&all);
	if (data_collect(argv, &all) == 0)
		return (0);
	if ((all.sprite.sprite[0] = sprite_coordinates(&all, '2')) == 0)
		return (0);
	if ((all.sprite.sprite[1] = sprite_coordinates(&all, '3')) == 0)
		return (0);
	if (argc == 3)
	{
		if (ft_strncmp(argv[2], "--save", 7) == 0)
			return (ft_save(&all));
		else
			return (write(1, "Wrong arguments\n", 16));
	}
	background_music(1);
	if (mlx_start(&all) == 0)
		return (0);
	return (0);
}
