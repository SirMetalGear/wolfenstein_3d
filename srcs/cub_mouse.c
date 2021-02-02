#include "cub3d.h"

void	turn_right(t_all *all, int sense)
{
	all->ray.old_dirx = all->player.xdir;
	all->player.xdir = all->player.xdir * cos(all->ray.rotspeed * sense) -
		all->player.ydir * sin(all->ray.rotspeed * sense);
	all->player.ydir = all->ray.old_dirx * sin(all->ray.rotspeed * sense) +
		all->player.ydir * cos(all->ray.rotspeed * sense);
	all->ray.old_planex = all->player.xplane;
	all->player.xplane = all->player.xplane * cos(all->ray.rotspeed * sense) -
		all->player.yplane * sin(all->ray.rotspeed * sense);
	all->player.yplane = all->ray.old_planex * sin(all->ray.rotspeed * sense) +
		all->player.yplane * cos(all->ray.rotspeed * sense);
}

void	turn_left(t_all *all, int sense)
{
	all->ray.old_dirx = all->player.xdir;
	all->player.xdir = all->player.xdir * cos(-all->ray.rotspeed * sense) -
		all->player.ydir * sin(-all->ray.rotspeed * sense);
	all->player.ydir = all->ray.old_dirx * sin(-all->ray.rotspeed * sense) +
		all->player.ydir * cos(-all->ray.rotspeed * sense);
	all->ray.old_planex = all->player.xplane;
	all->player.xplane = all->player.xplane * cos(-all->ray.rotspeed * sense)
	- all->player.yplane * sin(-all->ray.rotspeed * sense);
	all->player.yplane = all->ray.old_planex * sin(-all->ray.rotspeed * sense)
	+ all->player.yplane * cos(-all->ray.rotspeed * sense);
}
