/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: louise <lsoulier@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/18 14:53:16 by louise            #+#    #+#             */
/*   Updated: 2020/11/27 03:16:52 by user42           ###   ########.fr       */
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
# include "libft.h"

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

typedef struct	s_sprite
{
	t_point	position;
	double	distance;
	double	angle;
	int		is_visible;

}				t_sprite;

typedef struct	s_sprite_positions
{
	int		sprite_index;
	int		sprite_top_pixel;
	double	sprite_height;
	int		sprite_bottom_pixel;
	int		first_x_position;
}				t_sprite_positions;

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
	int			floor_color;
	int			ceiling_color;
	int			settings_complete;
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
	int			width;
	int			height;
}				t_texture_data;

typedef struct	s_player
{
	t_point			current_pos;
	int				turn_direction;
	int				walk_direction;
	double			direction_angle;
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
	char	wall_hit_content;
	int		was_hit_vertical;
	int		was_hit_north;
	int		was_hit_south;
	int		was_hit_west;
	int		was_hit_east;
}				t_ray;

typedef struct	s_mlx_vars
{
	void			*mlx;
	void			*win;
	t_game_file		parsed_file;
	t_player		player;
	t_ray			*rays;
	int				save;
	t_image_data	minimap;
	t_image_data	view;
	t_texture_data	south_text;
	t_texture_data	north_text;
	t_texture_data	west_text;
	t_texture_data	east_text;
	t_texture_data	sprites_text;
	int				cell_size;
	double			distance_to_projection_plane;
	int				nb_sprites;
	t_sprite		*sprites;
}				t_mlx_vars;

void			error_msg(int error_type);
void			error_msg_texture(char *filepath);
void			error_msg_parsing(int error_type);
void			set_point(t_point *point, double x, double y);
void			set_dimension(t_dimension *dimension, double width,
					double height);
int				create_game_struct(t_mlx_vars *vars, int save_opt);
int				create_window(t_mlx_vars *vars);
void			init_player(t_player *player, t_game_file parsed_file,
					int cell_size);
int				create_images(t_mlx_vars *vars);
int				load_texture(t_mlx_vars *vars, t_texture_data *text,
					char *filepath);
int				check_filepath_text(char *filepath);
int				is_wall(t_mlx_vars *vars, double x, double y);
void			update_player_position(t_mlx_vars *vars, t_player *player);
void			render_wall(t_mlx_vars *vars);
double			fishbowl_correct(t_mlx_vars *vars, t_ray ray);
void			render_background(t_mlx_vars *vars);
int				key_press_hook(int keycode, t_mlx_vars *vars);
int				key_release_hook(int keycode, t_mlx_vars *vars);
int				update_hook(t_mlx_vars *vars);
void			event_mngt(t_mlx_vars *vars);
int				my_mlx_new_image(void *mlx_ptr, t_image_data *img,
						int width, int height);
void			my_mlx_pixel_put(t_image_data *img, int x, int y, int color);
int				create_trgb(int t, int r, int g, int b);
void			draw_rect(t_image_data *img, t_point location,
					t_dimension dimension, int color);
double			distance_points(t_point start, t_point end);
double			degree_to_radian(double angle);
double			normalize_angle(double angle);
void			cast_all_rays(t_mlx_vars *vars);
void			init_ray(t_ray *ray, double ray_angle);
void			find_horizontal_intercept(t_mlx_vars *vars, t_ray *ray);
void			find_horizontal_intercept_loop(t_mlx_vars *vars,
					t_ray *ray, t_point next, t_point step);
char			is_wall_raycasting(t_mlx_vars *vars, t_point next_touch);
void			find_vertical_intercept(t_mlx_vars *vars, t_ray *ray);
void			find_vertical_intercept_loop(t_mlx_vars *vars,
					t_ray *ray, t_point next, t_point step);
void			reset_ray_setting(t_ray *ray, double vertical_len,
					t_point wall_found, char hit_content);
int				get_texture_color(t_texture_data *img, int x, int y);
void			map_texture(t_mlx_vars *vars, double wall_height,
					int ray_index);
void			set_line_texture(t_mlx_vars *vars, t_texture_data *text,
					double wall_height, int ray_index);
void			set_wall_limits(t_dimension win_res, double wall_height,
					int *wall_top_pixel, int *wall_bottom_pixel);
int				get_texture_offset_x(t_point wall_hit, int was_hit_vertical,
					int text_width, int cell_size);
int				get_texture_offset_y(double current_y,
					double wall_height, int win_height, int text_height);
int				save_bmp(t_image_data *first_frame, t_dimension img_res);
int				init_sprites(t_mlx_vars *vars);
void			init_sprite(t_mlx_vars *vars);
void			process_sprites(t_mlx_vars *vars);
double			calculate_sprite_angle(t_point sprite_position,
					t_point player_position, double player_rotation_angle);
int				sprite_is_visible(double sprite_angle);
void			sort_sprites(t_sprite *sprites, int nb_sprites);
void			get_sprites_positions(t_mlx_vars *vars);
void			render_sprite(t_mlx_vars *vars, t_sprite_positions data);
void			draw_sprite(t_mlx_vars *vars, t_sprite_positions data,
					t_point drawing, t_point sprite_texture_offset);
void			free_mlx_struct(t_mlx_vars *vars);
void			free_parsed_file(t_game_file parsed_file);
int				exit_game(t_mlx_vars *vars);
void			exit_game_red_cross(t_mlx_vars *vars);
#endif
