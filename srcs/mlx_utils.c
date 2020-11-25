/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mlx_utils.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: louise <lsoulier@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/05 17:46:02 by louise            #+#    #+#             */
/*   Updated: 2020/11/22 23:02:25 by user42           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	create_trgb(int t, int r, int g, int b)
{
	int color;

	color = t << 24;
	color |= r << 16;
	color |= g << 8;
	color |= b;
	return (color);
}

void my_mlx_pixel_put(t_image_data *img, int x, int y, int color)
{
	char	*dst;

	dst = img->addr + (y * img->line_length + x * (img->bits_per_pixel / 8));
	*(unsigned int*)dst = color;
}

int	my_mlx_new_image(void *mlx_ptr, t_image_data *img,
	int width, int height)
{
	img->img = mlx_new_image(mlx_ptr, width, height);
	if (!img->img)
	{
		error_msg(IMAGE_ERROR);
		return (0);
	}
	img->addr = mlx_get_data_addr(img->img,
		&(img->bits_per_pixel), &(img->line_length), &(img->endian));
	return (1);
}

void	draw_rect(t_image_data *img, t_point location,
				  t_dimension dimension, int color)
{
	double x;
	double y;

	x = -1;
	while (++x < dimension.width)
	{
		y = -1;
		while (++y < dimension.height)
			my_mlx_pixel_put(img, location.x + x, location.y + y, color);
	}
}
