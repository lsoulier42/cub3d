/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mlx_utils.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: louise <lsoulier@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/05 17:46:02 by louise            #+#    #+#             */
/*   Updated: 2020/11/05 17:46:28 by louise           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "cub3d.h"

int		create_trgb(int t, int r, int g, int b)
{
	return(t << 24 | r << 16 | g << 8 | b);
}

void	my_mlx_pixel_put(t_image_data *img, int x, int y, int color)
{
	char    *dst;

	dst = img->addr + (y * img->line_length + x * (img->bits_per_pixel / 8));
	*(unsigned int*)dst = color;
}

void draw_square(t_image_data *img, int color)
{
	int i;
	int j;

	img->addr = mlx_get_data_addr(img->img, &(img->bits_per_pixel), &(img->line_length), &(img->endian));
	i = -1;
	while (++i < WALL_SIZE)
	{
		j = -1;
		my_mlx_pixel_put(img, i, 0, color);
		while (++j < WALL_SIZE)
			my_mlx_pixel_put(img, i, j, color);
	}
}