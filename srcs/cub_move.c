#include "cub3d.h"

void	movement(t_all *all)
{
	if (all->move.moveflag1 == 1)
		key_forward(all);
	if (all->move.moveflag2 == 1)
		key_back(all);
	if (all->move.moveflag3 == 1)
		key_left(all);
	if (all->move.moveflag4 == 1)
		key_right(all);
	if (all->move.moveflag5 == 1)
		turn_left(all, 3);
	if (all->move.moveflag6 == 1)
		turn_right(all, 3);
}

int		key_flagoff(int key, t_all *all)
{
	if (key == 13)
		all->move.moveflag1 = 0;
	else if (key == 1)
		all->move.moveflag2 = 0;
	else if (key == 0)
		all->move.moveflag3 = 0;
	else if (key == 2)
		all->move.moveflag4 = 0;
	else if (key == 123)
		all->move.moveflag6 = 0;
	else if (key == 124)
		all->move.moveflag5 = 0;
	else if (key == 53)
		esc_exit(all);
	return (0);
}

int		key_mouse_flagoff(t_all *all)
{
	if (all->map.next_map == 1)
		ft_next_level(all);
	return (0);
}

int		key_flagon(int key, t_all *all)
{
	if (key == 13)
		all->move.moveflag1 = 1;
	else if (key == 1)
		all->move.moveflag2 = 1;
	else if (key == 0)
		all->move.moveflag3 = 1;
	else if (key == 2)
		all->move.moveflag4 = 1;
	else if (key == 123)
		all->move.moveflag6 = 1;
	else if (key == 124)
		all->move.moveflag5 = 1;
	return (0);
}

int		mouse_move(int x, int y, t_all *all)
{
	int		a;
	int		sense;

	a = 300;
	(void)y;
	sense = 3;
	mlx_mouse_hide();
	mlx_mouse_move(all->pix.win, a, 300);
	if (x > a)
		turn_left(all, sense);
	else if (x < a)
		turn_right(all, sense);
	return (0);
}
