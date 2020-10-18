/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: louise <lsoulier@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/18 14:53:16 by louise            #+#    #+#             */
/*   Updated: 2020/10/18 21:05:50 by louise           ###   ########.fr       */
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
//# include "mlx.h"

typedef enum	e_settings
{
	NORTH,
	SOUTH,
	WEST,
	EAST,
	SPRITE,
	FLOOR,
	CEILING

}				t_settings;

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
	t_point		*player_start;
	t_dimension *map_res;

	t_dimension *window_res;

	t_file		*no_text;
	t_file		*so_text;
	t_file		*we_text;
	t_file		*ea_text;
	t_file		*sprite_text;

	t_color		*floor_color;
	t_color		*ceiling_color;
}				t_game;

t_file	*check_file(char *filestr);
char 	*get_filepath(char *file);
char 	*get_filename(char *file);
char 	*get_extension(char *file);
void 	*destroy_filevar(char *ext, char *filename, char *path);
void	*destroy_file(t_file *file);

t_game	*parse_file(t_file *cubmap);
#endif
