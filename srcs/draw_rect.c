/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_square.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: louise <louise@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/09 14:19:30 by louise            #+#    #+#             */
/*   Updated: 2020/11/14 17:20:20 by user42           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	draw_rect(t_image_data *map, t_point location,
	t_dimension dimension, int color)
{
	double x;
	double y;

	x = -1;
	while (++x < dimension.width)
	{
		y = -1;
		while (++y < dimension.height)
			my_mlx_pixel_put(map, location.x + x, location.y + y, color);
	}
}
