#ifndef CUB3D_H
# define CUB3D_H

# include "./../libft/libft.h"
# include "./../gnl/get_next_line.h"
# include "./../minilibx_opengl_20191021/mlx.h"
# include <fcntl.h>
# include <math.h>
# include <fcntl.h>
# include <unistd.h>

/*
** STRUCT FOR DATA MAP
*/

typedef struct	s_map
{
	int				portal_x;
	int				portal_y;
	int				portal_sprite;
	int				x;
	int				y;
	char			*no;
	char			*so;
	char			*we;
	char			*ea;
	char			*s;
	char			*f;
	char			*c;
	char			**map;
	int				p_pos[2];
	int				save_flag;
	int				next_map;
}				t_map;

/*
** IMAGE DATA
*/

typedef struct	s_data
{
	void		*img;
	char		*addr;
	int			bpp;
	int			line_length;
	int			endian;
}				t_data;

/*
** STRUCT FOR MLX
*/

typedef struct	s_pix
{
	void		*mlx;
	void		*win;
}				t_pix;

/*
** PLAYER CURRENT POS, POV, POF
*/

typedef struct	s_player
{
	double		xpos;
	double		ypos;
	double		xdir;
	double		ydir;
	double		xplane;
	double		yplane;
	double		old_xpos;
	double		old_ypos;
	int			pos_flag;
}				t_player;

/*
** MOVEMENT FLAGS
*/

typedef struct	s_move
{
	int			moveflag1;
	int			moveflag2;
	int			moveflag3;
	int			moveflag4;
	int			moveflag5;
	int			moveflag6;
	int			mouseleft;
	int			mouseright;
	double		sense;
}				t_move;

/*
** RAY VARIABLES FOR RAYCASTING
*/

typedef struct	s_rayl
{
	double		fov;
	double		screen_widght;
	double		screen_height;
	double		map_height;
	double		map_widght;
	int			map_x;
	int			map_y;
	double		xray_lenght;
	double		yray_lenght;
	double		ray_dist_to_plane;
	int			step_x;
	int			step_y;
	int			side;
	double		dist_to_next_xpos;
	double		dist_to_next_ypos;
	int			height_of_line;
	int			start_point;
	int			end_point;
	double		camera;
	double		ray_dirx;
	double		ray_diry;
	int			x;
	int			hit;
	double		movespeed;
	double		old_dirx;
	double		old_planex;
	double		rotspeed;
}				t_rayl;

/*
** TEXTURE PARAMS
*/

typedef struct	s_tex
{
	int			height[8];
	int			width[8];
	double		wall_x;
	int			tex_x;
	int			tex_y;
	double		tex_pos;
	double		step;
}				t_tex;

/*
** TEXTURE DATA
*/

typedef struct	s_tex_data
{
	void		*img;
	char		*addr;
	int			bpp;
	int			line_length;
	int			endian;
}				t_tex_data;

/*
** FLOOR AND CEILING PARAMS
*/

typedef struct	s_floor
{
	float		ray_dir_x0;
	float		ray_dir_x1;
	float		ray_dir_y0;
	float		ray_dir_y1;
	int			horizon;
	float		pos_z;
	float		row_distance;
	float		floor_step_x;
	float		floor_step_y;
	float		floor_x;
	float		floor_y;
	int			cell_x;
	int			cell_y;
	int			tex_x;
	int			tex_y;
}				t_floor;

/*
** SPRITES PARAMS AND VARIABLES
*/

typedef struct	s_sprite
{
	double		sprite_x;
	double		sprite_y;
	double		inv_det;
	double		depth_x;
	double		depth_y;
	int			pos_on_screen;
	int			sprite_height;
	int			start_point_y;
	int			stop_point_y;
	int			start_point_x;
	int			stop_point_x;
	int			sprite_width;
	int			**sprite[2];
	int			stroke;
	int			tex_x;
	int			tex_y;
	int			sprite_num;
}				t_sprite;

/*
** STRUCT FOR ALL STRUCTURES
*/

typedef struct	s_all
{
	t_map		map;
	t_data		img;
	t_pix		pix;
	t_rayl		ray;
	t_player	player;
	t_tex		tex;
	t_tex_data	tex_data[8];
	t_floor		floor;
	t_move		move;
	t_sprite	sprite;
}				t_all;

/*
** MAIN FUNCS AND UTILS
*/

int				main(int argc, char **argv);
int				data_collect(char **argv, t_all *all);
int				error_exit(t_all *all, int x, char **data);
size_t			ft_count(int n);
void			freesher(char **trash);
int				count_lines(char **map);
char			**ft_realloc(char **map, int add_mem, char *add);
int				mlx_win(t_all *all);
void			struct_init(t_all *all);
int				zero_check(char **map, int x);
int				esc_exit(t_all *all);
int				ft_next_level(t_all *all);
void			background_music(int f);

/*
**DATA PARSER
*/

int				res_parser(char *map, int j, t_all *all);
char			*texture_parser(char *map, int j);
int				skip_to_next(char *map, int j);
int				color_parser(char *map, int *paint, int j);
int				tex_checker(char **map, int i, int j, t_all *all);
int				data_parser(char **map, t_all *all);
int				map_cmp(char **map, int i, int j);
int				map_check(char **map);
int				texmap_checker(t_all *all);
int				map_parser(int fd, char **map, t_all *all);

/*
**MAP PARSER
*/

int				compare(char s1, char *s2);
int				isempty(char **map, int x, int y);
int				map_logic(char **map);
void			player_pos_flag(t_all *all, int i, int j, char **map);
int				scene_checker(char **map, t_all *all);
void			cutter(char **map, int j);
char			**ft_record(char **map, char *tmp, int fd);
char			**get_map(int fd, t_all *all);

/*
** INITIALIZATION BEFORE RAYCASTING
*/

void			tex_init(t_all *all);
void			tex_init2(t_all *all);
void			player_pos(t_all *all);
int				player_n_s(t_all *all);
void			ray_init(t_all *all);

/*
** RAYCASTING
*/

int				ray_cast(t_all *all);
void			ray_calc(t_all *all, int w);
void			ray_step_calc(t_all *all);
void			ray_hit_wall(t_all *all);
void			ray_calc_dist_to_plane(t_all *all);
void			ray_line_height(t_all *all);

/*
** SPRITES CASTING
*/

int				sprite_count(t_all *all, char sprite);
int				**sprite_coordinates(t_all *all, char sprite);
void			sprite_cast(t_all *all, double *buffer_w, int z, char sprite);
void			sort_sprites(int amount, t_all *all, int z);
double			get_distance(t_all *all, int j);

/*
** CEILING AND FLOOR PAINTING
*/

int				ceil_cast(t_all *all);
int				floor_cast(t_all *all);
void			ceil_calc(t_all *all, int y);
void			floor_calc(t_all *all, int y);

/*
** WORKING WITH IMAGES
*/

int				cub_3d(t_all *all);
int				mlx_start(t_all *all);
int				tex_put(t_all *all);
void			tex_pixel_put(t_all *all, int w);
int				get_tex_params(t_all *all);
unsigned int	tex_color(t_all *all, int x, int y, int z);
void			my_mlx_pixel_put(t_all *all, int x, int y, int color);

/*
** PLAYER MOVEMENT
*/

void			movement(t_all *all);
int				key_flagoff(int key, t_all *all);
int				key_flagon(int key, t_all *all);
int				mouse_move(int x, int y, t_all *all);
void			key_forward(t_all *all);
void			key_back(t_all *all);
void			key_left(t_all *all);
void			key_right(t_all *all);
void			turn_right(t_all *all, int sense);
void			turn_left(t_all *all, int sense);
int				key_mouse_flagoff(t_all *all);

/*
** SCREENSHOT
*/

int				ft_save(t_all *all);
int				screenshot(t_all *all);
int				generate_bitmap_image(unsigned char *image,
										int height, int width);
unsigned char	*create_bmp_header(int height, int width, int stride);
int				get_pixel_color(t_all *all, int x, int y);

#endif
