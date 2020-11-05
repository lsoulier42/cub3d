/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: louise <lsoulier@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/18 14:53:16 by louise            #+#    #+#             */
/*   Updated: 2020/11/05 17:21:29 by louise           ###   ########.fr       */
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
# define OUTSIDE ' '
# define EMPTY '0'
# define WALL '1'
# define OBJECT '2'
# define CARD_CHARSET "NSEW"
# define WALL_SIZE 30
# define ARROW_LEFT 123
# define ARROW_RIGHT 124
# define ARROW_DOWN 125
# define ARROW_UP 126


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
	char 			current_card;
	char			**map;
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
void 			draw_square(t_image_data *img, int color);
void			print_map(t_mlx_vars *vars, char **map);
int 			player_move(int keycode, t_mlx_vars *vars);
void			print_player(t_mlx_vars *vars, t_point player_pos);
void 			erase_previous_pos(t_mlx_vars *vars, t_point player_pos);
t_image_data 	create_vertical_ray(t_mlx_vars *vars);
t_image_data 	create_horizontal_ray(t_mlx_vars *vars);
t_point 		print_ray(t_mlx_vars *vars, t_point current_pos);
char 			change_card(int keycode);
void			erase_previous_ray(t_mlx_vars *vars, t_point previous_pos, char previous_card);

//test functions
void 			test_parsed_map(t_game *parsed_map);
void 			test_opened_file(t_file file);
void			debug_point(t_mlx_vars *vars, t_point point);
#endif
