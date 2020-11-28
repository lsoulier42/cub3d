/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   save_bmp_utils.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lsoulier <lsoulier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/28 23:38:37 by lsoulier          #+#    #+#             */
/*   Updated: 2020/11/28 23:42:30 by user42           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"
#include "save_bmp.h"

void			render_one_frame(t_mlx_vars *vars)
{
	cast_all_rays(vars);
	render_background(vars);
	render_wall(vars);
	process_sprites(vars);
	save_bmp(&vars->view, vars->parsed_file.win_res);
}

t_bmp_color		convert_trgb_to_bmp(t_image_data *img, int x, int y)
{
	t_bmp_color	pixel_color;
	int			color;
	char		*dst;

	dst = img->addr + (y * img->line_length + x * (img->bits_per_pixel / 8));
	color = *(unsigned int*)dst;
	pixel_color.r = (color & 0xFFFF00) >> 16;
	pixel_color.g = (color & 0xFF00) >> 8;
	pixel_color.b = color & 0xFF;
	return (pixel_color);
}

int				get_correction_byte(int image_width)
{
	char	correction_byte[4];

	correction_byte[0] = 0;
	correction_byte[1] = 3;
	correction_byte[2] = 2;
	correction_byte[3] = 1;
	return (correction_byte[(int)(3 * image_width) % 4]);
}
