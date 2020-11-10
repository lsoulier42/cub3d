/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_square.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: louise <louise@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/09 14:19:30 by louise            #+#    #+#             */
/*   Updated: 2020/11/09 23:50:12 by louise           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "cub3d.h"

void 	draw_rect(t_image_data *map, t_point location, t_dimension dimension, int color)
{
	int x;
	int y;

	x = -1;
	while (++x < dimension.width)
	{
		y = -1;
		while (++y < dimension.height)
			my_mlx_pixel_put(map, location.x + x, location.y + y, color);
	}
}