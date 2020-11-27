/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   save_bmp.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lsoulier <lsoulier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/21 13:35:49 by lsoulier          #+#    #+#             */
/*   Updated: 2020/11/27 03:17:52 by user42           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SAVE_BMP_H
# define SAVE_BMP_H
# include <sys/types.h>
# include <sys/stat.h>
# include <fcntl.h>
# include <unistd.h>
# include "cub3d.h"
# include "libft.h"
# define BYTES_FORMAT 24
# define BMP_FILE_NAME "save.bmp"

typedef struct	s_bmp_color
{
	unsigned char r;
	unsigned char g;
	unsigned char b;
}				t_bmp_color;

typedef struct	s_image_header
{
	int		size_img_header;
	int		width;
	int		height;
	short	nb_planes;
	short	bpp;
	int		compression;
	int		size_img;
	int		horizontal_resolution;
	int		vertical_resolution;
	int		color_array;
	int		color_img_array;
}				t_image_header;

typedef struct	s_file_header
{
	char				signature[2];
	int					size;
	int					reserved;
	int					offset_img;
	t_image_header		img_header;
}				t_file_header;

t_bmp_color		convert_trgb_to_bmp(t_image_data *img, int x, int y);
t_file_header	fill_bmp_header(t_dimension img_res);
void			fill_bmp(t_image_data *frame, t_file_header header, int fd);
int				get_correction_byte(int image_width);
#endif
