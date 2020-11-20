/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: louise <lsoulier@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/18 14:53:16 by louise            #+#    #+#             */
/*   Updated: 2020/11/20 20:36:09 by user42           ###   ########.fr       */
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
# include "constants.h"

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

typedef struct	s_game_file
{
	char		**map;
	t_point		player_start;
	char		player_start_card;
	t_dimension	map_res;
	t_dimension	win_res;
	char		*no_text;
	char		*so_text;
	char		*we_text;
	char		*ea_text;
	char		*sprite_text;
	int 		floor_color;
	int 		ceiling_color;
}				t_game_file;

typedef struct	s_image_data
{
	void		*img;
	char		*addr;
	int			bits_per_pixel;
	int			line_length;
	int			endian;
}				t_image_data;

typedef struct	s_texture_data
{
	void		*img;
	char		*addr;
	int			bits_per_pixel;
	int			line_length;
	int			endian;
	int 		width;
	int 		height;
}				t_texture_data;

typedef struct	s_player
{
	t_point			current_pos;
	double			size;
	int				turn_direction;
	int				walk_direction;
	double 			direction_angle;
	double			rotation_angle;
	double			move_speed;
	double			rotation_speed;
}				t_player;

typedef struct	s_ray
{
	double	distance;
	double	angle;
	t_point	wall_hit;
	int		facing_down;
	int		facing_left;
	char 	wall_hit_content;
	int 	was_hit_vertical;
	int 	was_hit_north;
	int 	was_hit_south;
	int 	was_hit_west;
	int 	was_hit_east;
}				t_ray;

typedef struct	s_mlx_vars
{
	void			*mlx;
	void			*win;
	t_game_file		*parsed_file;
	t_player		*player;
	t_ray			*rays;
	int 			cell_size;
	t_image_data 	*minimap;
	t_image_data 	*view;
	t_texture_data	*south_text;
	t_texture_data	*north_text;
	t_texture_data	*west_text;
	t_texture_data	*east_text;
}				t_mlx_vars;

typedef struct	s_line_drawing
{
	t_point	coord;
	t_point	step;
	t_point	abs;
}				t_line_drawing;

char			**realloc_map(char **data, int prev_size, int new_size);

//error fct
void			error_msg(int error_type);
void			error_msg_alloc(int error_type);
void 			error_msg_texture(char *filepath);
void 			error_msg_parsing(int error_type);

//basic struct fct
void			set_point(t_point *point, double x, double y);
void			set_dimension(t_dimension *dimension, double width, double height);

//parsing functions
int				check_cub_file(char *path);
int 			check_extension_file(char *path, char *ext);
t_game_file		*parse_file(char *path);
t_game_file		*init_parsed_file(void);
int				read_cub_file(t_game_file *parsed_file, int fd);
int				set_window_res(char *line, t_dimension *win_res);
int				set_map_texture(char *line, char **text_path);
int 			set_map_color(char *line, int *color);
int 			check_color_format(char *line);
int 			set_map(t_game_file *parsed_file, char **line, int fd);
char			**create_map(char **line, int fd);
int 			set_player_start(t_game_file *parsed_file);
int				check_map(char **map);
int				check_config(t_game_file *parsed_file, char *line);
int				check_texture_config(t_game_file *parsed_file, char *line);
int				check_color_config(t_game_file *parsed_file, char *line);
int 			check_resolution_config(t_game_file *parsed_file, char *line);

//initialize mlx game vars
int 			load_game(t_mlx_vars **vars, t_game_file *parsed_file);
t_mlx_vars		*create_vars_struct(t_game_file *parsed_file);
int				create_window(t_mlx_vars *vars);
t_player		*init_player(t_game_file *parsed_file, int cell_size);
double			set_rotation_angle(char card);
void			free_game_struct(t_mlx_vars *vars);
void 			free_parsed_file(t_game_file *parsed_file);
void			free_text_path(t_game_file *parsed_file);
int				exit_game(t_mlx_vars *vars);
int 			create_images(t_mlx_vars *vars);

//render fct
void			render_minimap(t_mlx_vars *vars);
void			fill_map(t_mlx_vars *vars, t_image_data *minimap);
void			fill_ray(t_mlx_vars *vars, t_image_data *minimap, t_ray *rays);
void			fill_player(t_mlx_vars *vars, t_image_data *minimap);
int				minimap_colors(char map_elem);
int				is_wall(t_mlx_vars *vars, double x, double y);
void			update_player_position(t_mlx_vars *vars);
void			render_wall(t_mlx_vars *vars);
double			fishbowl_correct(t_mlx_vars *vars, t_ray ray,
					double projection_plane_distance);
void			render_background(t_mlx_vars *vars);

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
void			cast_all_rays(t_mlx_vars *vars);
void			init_ray(t_ray *ray, double ray_angle);
void			find_horizontal_intercept(t_mlx_vars *vars, t_ray *ray);
void 			find_horizontal_intercept_loop(t_mlx_vars *vars, t_ray *ray, t_point next, t_point step);
char			is_wall_raycasting(t_mlx_vars *vars, t_point next_touch);
void			find_vertical_intercept(t_mlx_vars *vars, t_ray *ray);
void 			find_vertical_intercept_loop(t_mlx_vars *vars, t_ray *ray, t_point next, t_point step);
void			reset_ray_setting(t_ray *ray, double vertical_len, t_point wall_found,
						  char hit_content);

//textures fct
int 			init_texture_files(t_mlx_vars *vars);
int 			get_texture_color(t_texture_data *img, int x, int y);
void 			map_texture(t_mlx_vars *vars, t_dimension elem_dimension, int ray_index);
void			set_line_texture(t_mlx_vars *vars, t_texture_data *text, t_dimension elem_dimension, int ray_index);
int				get_texture_offset_x(t_point wall_hit, int was_hit_vertical,
							int cell_size, int text_width);
#endif