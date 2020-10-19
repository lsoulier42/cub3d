/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: louise <lsoulier@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/18 14:53:16 by louise            #+#    #+#             */
/*   Updated: 2020/10/19 22:50:19 by louise           ###   ########.fr       */
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
//# include "mlx.h"
# define OUTSIDE ' '
# define EMPTY '0'
# define WALL '1'
# define OBJECT '2'
# define CARD_CHARSET "NSEW"

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

int				check_file(char *filestr, t_file *file);
char 			*get_filepath(char *file);
char 			*get_filename(char *file);
char 			*get_extension(char *file);

int 			destroy_filevar(char *ext, char *filename, char *path);
int 			destroy_file(t_file file);

t_game			*parse_file(t_file cubmap);
t_game			*init_map(void);

void			init_point(t_point *point);
void			init_dimension(t_dimension *dimension);
void			init_file(t_file *file);
void			init_color(t_color *color);

void			set_window_res(char *line,t_dimension *window_res);
void			set_map_texture(char *line, t_file *text_file);
void			set_map_color(char *line, t_color *color);
void 			set_map(t_game *parsed_map, char **line, int fd);
char 			**complete_map(char **map, char *line, int nb_lines);
void 			set_dimension(t_dimension *dimension, int width, int height);
#endif
