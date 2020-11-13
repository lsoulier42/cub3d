/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: louise <lsoulier@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/18 14:53:16 by louise            #+#    #+#             */
/*   Updated: 2020/11/13 01:25:53 by user42           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_H
# define CUB3D_H
# include <stdlib.h>
# include <unistd.h>
# include <fcntl.h>
# include <sys/types.h>
# include <sys/uio.h>
# include <math.h>
# include <stdio.h>
# include <mlx.h>
# define CARD_CHARSET "NSEW"
# define FORWARD 1
# define BACKWARD -1
# define ROT_RIGHT 1
# define ROT_LEFT -1
# define ESCAPE 65307
# define FOV_ANGLE 60
# define MINIMAP_SCALE 0.2

typedef enum	e_map_elem
{
	EMPTY,
	WALL,
	SPRITE,
	ELEM_TOTAL
}				t_map_elem;

typedef enum	e_arrow
{
	ARROW_LEFT = 65361,
	ARROW_UP,
	ARROW_RIGHT,
	ARROW_DOWN
}				t_arrow;

typedef enum	e_const_color
{
	BLACK,
	WHITE,
	RED,
	BLUE,
	YELLOW,
	GREEN,
	PURPLE,
	PINK,
	ORANGE
}				t_const_color;

typedef enum	e_const_error
{
	EXT_ERROR,
	PARSING_ERROR,
	FILE_ERROR,
	ARG_ERROR
}				t_const_error;

typedef struct	s_point
{
	double x;
	double y;
}				t_point;

typedef struct	s_dimension
{
	double width;
	double height;
}				t_dimension;

typedef struct	s_color
{
	unsigned char r;
	unsigned char g;
	unsigned char b;
}				t_color;

typedef struct	s_game
{
	char		**map;
	t_point		player_start;
	char		player_start_card;
	t_dimension	map_res;
	t_dimension	window_res;
	char		*no_text;
	char		*so_text;
	char		*we_text;
	char		*ea_text;
	char		*sprite_text;
	t_color		floor_color;
	t_color		ceiling_color;
}				t_game;

typedef struct	s_image_data
{
	void		*img;
	char		*addr;
	int			bits_per_pixel;
	int			line_length;
	int			endian;
}				t_image_data;

typedef struct	s_player
{
	t_point			current_pos;
	int				size;
	int				turn_direction;
	int				walk_direction;
	double			rotation_angle;
	double			move_speed;
	double			rotation_speed;
}				t_player;

typedef struct	s_mlx_vars
{
	void			*mlx;
	void			*win;
	char			**map;
	t_image_data	map_img;
	t_dimension		win_res;
	t_dimension		map_res;
	int				tile_size;
	t_player		player;
}				t_mlx_vars;

typedef struct	s_ray
{
	double	distance;
	t_point	wall_hit;
	int		was_hit_vertical;
	double	ray_angle;
	int		facing_down;
	int		facing_left;
	int		column_index;
}				t_ray;

typedef struct	s_line_drawing
{
	t_point	coord;
	t_point	step;
	t_point	abs;
}				t_line_drawing;

//file functions
int				check_file(char *path);
void			close_game_files(t_game *parsed_map);

//exit and error fct
int				exit_game(t_mlx_vars *vars);
int				error_msg(int error_type);

//basic struct fct
void			set_point(t_point *point, double x, double y);
void			set_dimension(t_dimension *dimension, int width, int height);
void			set_color(t_color *color, unsigned char r, unsigned char g,
					unsigned char b);

//parsing functions
t_game			*parse_file(char *path);
t_game			*init_parsed_map(void);
void			check_config(t_game	*parsed_map, char **line, int fd);
void			set_window_res(char *line, t_dimension *window_res);
void			set_map_texture(char *line, char **file_path);
void			set_map_color(char *line, t_color *color);
void			set_map(t_game *parsed_map, char **line, int fd);
char			**create_map(char **map, char *line, int nb_lines);
void			set_player_start(t_game *parsed_map);
int				check_map(char **map, int map_height);
void			set_parsed_map(t_game *parsed_map, char **map,
					int map_width, int map_height);

//initialize mlx game vars
void			init_vars(t_mlx_vars *vars, t_game *parsed_map);
void			init_player(t_player *player, t_point start, char card,
					int tile_size);

//render fct
void			fill_map(t_image_data *map_img, char **map_array,
					int tile_size);
int				tile_color(char map_elem);
void			print_player(t_mlx_vars *vars, t_player player);
int				is_wall(t_mlx_vars *vars, double x, double y);
void			update_player_position(t_mlx_vars *vars);
void			print_minimap(t_mlx_vars *vars, t_ray *rays);
void			render_ray(t_mlx_vars *vars, t_ray *rays);
void 			render_wall(t_mlx_vars *vars, t_image_data *view,
					t_ray *rays);
double			fishbowl_correct(t_mlx_vars *vars, t_ray ray,
					double projection_plane_distance);
double 			max_height_correct(double calculated_wall_height,
					double win_height);
t_point			ylocation_correct(double win_height,
					double wall_height, int i);

//event fcts
int				key_press_hook(int keycode, t_mlx_vars *vars);
int				key_release_hook(int keycode, t_mlx_vars *vars);
int				update_hook(t_mlx_vars *vars);
void			event_mngt(t_mlx_vars *vars);

//mlx utils
void			my_mlx_new_image(void *mlx_ptr, t_image_data *img,
					int width, int height);
void			my_mlx_pixel_put(t_image_data *img, int x, int y, int color);
int				create_trgb(int t, int r, int g, int b);
int				color_trgb(int const_color);

//geometry fct
void			draw_rect(t_image_data *map, t_point location,
					t_dimension dimension, int color);
void			draw_line(t_image_data *map, t_point start,
					t_point end, int color);
void			line_vertical(t_image_data *map, t_point start,
					t_point end, int color);
void			line_horizontal(t_image_data *map, t_point start,
					t_point end, int color);
void			line_diagonal(t_image_data *map, t_point start,
					t_point end, int color);
void			line_low_angle(t_image_data *map, t_point start,
					t_point end, int color);
void			line_low_angle_loop(t_image_data *map,
					t_line_drawing low, int color);
void			line_big_angle(t_image_data *map, t_point start,
					t_point end, int color);
void			line_big_angle_loop(t_image_data *map,
					t_line_drawing big, int color);
void			draw_circle(t_image_data *map, t_point center,
					int ray, int color);
void			cl_pixelset(t_image_data *map, t_point center,
					t_point coord, int color);
double			distance_points(t_point start, t_point end);
double			degree_to_radian(double angle);
double			normalize_angle(double angle);


//raycasting fct
t_ray			*cast_all_rays(t_mlx_vars *vars);
void			init_ray(t_ray *ray, double ray_angle, int column_index);
void			cast_ray(t_mlx_vars *vars, t_ray *ray);
t_point			find_horizontal_intercept(t_mlx_vars *vars, t_ray ray);
t_point			first_horizontal_intercept(t_mlx_vars *vars, t_ray ray);
t_point			find_vertical_intercept(t_mlx_vars *vars, t_ray ray);
t_point			first_vertical_intercept(t_mlx_vars *vars, t_ray ray);

#endif
