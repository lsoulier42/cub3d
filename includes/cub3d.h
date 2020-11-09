/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: louise <lsoulier@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/18 14:53:16 by louise            #+#    #+#             */
/*   Updated: 2020/11/09 14:25:01 by louise           ###   ########.fr       */
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

typedef enum 	e_map_elem
{
	EMPTY,
	WALL,
	SPRITE,
	ELEM_TOTAL
}				t_map_elem;

typedef enum	e_arrow
{
	ARROW_LEFT = 123,
	ARROW_RIGHT,
	ARROW_DOWN,
	ARROW_UP
}				t_arrow;

typedef enum 	e_const_color
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

typedef struct 	s_point
{
	int x;
	int y;
}				t_point;

typedef struct 	s_dimension
{
	int width;
	int height;
}				t_dimension;

typedef struct 	s_file
{
	char	*fullname;
	char	*ext;
	char	*filename;
	char 	*path;
	int		fd;
}				t_file;

typedef struct 	s_color
{
	unsigned char r;
	unsigned char g;
	unsigned char b;
}				t_color;

typedef struct	s_game
{
	char		**map;
	t_point		player_start;
	char 		player_start_card;
	t_dimension map_res;
	t_dimension window_res;

	t_file		no_text;
	t_file		so_text;
	t_file		we_text;
	t_file		ea_text;
	t_file		sprite_text;

	t_color		floor_color;
	t_color		ceiling_color;
}				t_game;

typedef struct  s_image_data
{
	void		*img;
	char		*addr;
	int			bits_per_pixel;
	int			line_length;
	int			endian;
}               t_image_data;

typedef struct  s_mlx_vars
{
	void			*mlx;
	void			*win;
	t_dimension		win_res;
	t_image_data	player_img;
	t_point			current_pos;
	t_point			wall_touched;
	/*t_image_data 	player_up;
	t_image_data 	player_down;
	t_image_data 	player_west;
	t_image_data 	player_est;*/
	char 			current_card;
	char			**map;
	int 			tile_size;
}               t_mlx_vars;

int				open_game_file(t_file *file, char *fullname);
void 			init_file(t_file *file);
int				set_file(t_file *file, char *fullname, int fd);
int 			destroy_file(t_file file);
void 			close_game_files(t_file cubmap, t_game *parsed_map);

void 			set_point(t_point *point, int x, int y);
void 			set_dimension(t_dimension *dimension, int width, int height);
void 			set_color(t_color *color, unsigned char r, unsigned char g,
						  unsigned char b);

t_game			*parse_file(t_file cubmap);
t_game			*init_parsed_map(void);

void			set_window_res(char *line,t_dimension *window_res);
void			set_map_texture(char *line, t_file *text_file);
void			set_map_color(char *line, t_color *color);

void 			set_map(t_game *parsed_map, char **line, int fd);
char 			**create_map(char **map, char *line, int nb_lines);
void 			set_player_start(t_game *parsed_map);
int 			check_map(char **map, int map_height);

int				create_trgb(int t, int r, int g, int b);
void			my_mlx_pixel_put(t_image_data *img, int x, int y, int color);
void			draw_square(t_image_data *img, int color, int tile_size);
void			print_map(t_mlx_vars *vars, char **map);
int 			player_move(int keycode, t_mlx_vars *vars);
void			print_player(t_mlx_vars *vars, t_point player_pos);
void 			erase_previous_pos(t_mlx_vars *vars, t_point player_pos);
t_image_data 	create_vertical_ray(t_mlx_vars *vars);
t_image_data 	create_horizontal_ray(t_mlx_vars *vars);
t_point 		print_ray(t_mlx_vars *vars, t_point current_pos);
char 			change_card(int keycode);
void			erase_previous_ray(t_mlx_vars *vars, t_point previous_pos, char previous_card);
void 			set_map_elem(t_mlx_vars *vars, t_image_data elem[ELEM_TOTAL]);
void			init_vars(t_mlx_vars *vars, t_game *parsed_map);
void			init_game(t_mlx_vars *vars);
void			get_sprite(t_image_data sprite_sheet, t_image_data *sprite, t_point sprite_location, int size);
void			init_player_sprites(t_mlx_vars *vars);
void 			change_player_img(t_mlx_vars *vars);
void			my_mlx_new_image(void *mlx_ptr, t_image_data *img, int width, int height);
void			draw_line(t_mlx_vars *vars, t_point start, t_point end, int color);
void			line_vertical(t_mlx_vars *vars, t_point start, t_point end,	t_image_data pixel);
void			line_horizontal(t_mlx_vars *vars, t_point start, t_point end, t_image_data pixel);
void 			line_diagonal(t_mlx_vars *vars, t_point start, t_point end, t_image_data pixel);
void 			line_low_angle(t_mlx_vars *vars, t_point start, t_point end, t_image_data pixel);
void 			line_big_angle(t_mlx_vars *vars, t_point start, t_point end, t_image_data pixel);
int 			color_trgb(int const_color);
void 			draw_circle(t_mlx_vars *vars, t_point center, int ray, int color);
void 			circle_pixelset(t_mlx_vars *vars, t_image_data pixel, t_point center, t_point coord);
int 			distance_points(t_point start, t_point end);
double 			radian_to_degree(double angle);
double 			degree_to_radian(double angle);

//test functions
void 			test_parsed_map(t_game *parsed_map);
void 			test_opened_file(t_file file);
void			debug_point(t_mlx_vars *vars, t_point point);
#endif
