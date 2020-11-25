/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mlx_utils2.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lsoulier <lsoulier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/23 14:29:21 by lsoulier          #+#    #+#             */
/*   Updated: 2020/11/23 15:19:24 by user42           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int		load_texture(t_mlx_vars *vars, t_texture_data *text, char *filepath)
{
	text->img = mlx_xpm_file_to_image(vars->mlx,
									  filepath, &text->width, &text->height);
	if (!text->img)
	{
		error_msg(TEXTURE_ERROR);
		error_msg_texture(filepath);
		return (0);
	}
	text->addr = mlx_get_data_addr(text->img,
		&text->bits_per_pixel, &text->line_length, &text->endian);
	return (1);
}

int		change_color_intensity(int color, double factor)
{
	int	t;
	int r;
	int g;
	int b;

	t = (color & 0xFFFFFF00) >> 24;
	r = ((color & 0xFFFF00) >> 16) * factor;
	g = ((color & 0xFF00) >> 8) * factor;
	b = (color & 0xFF) * factor;
	return (t << 24 | r << 16 | g << 8 | b);
}

int		get_texture_color(t_texture_data *img, int x, int y)
{
	char	*dst;

	if (y < 0)
		y = 0;
	if (x < 0)
		x = 0;
	if (y > img->height)
		y = img->height;
	if (x > img->width)
		x = img->width;
	dst = img->addr + (y * img->line_length + x * img->bits_per_pixel / 8);
	return (*(unsigned int*)dst);
}