/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_square.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: louise <louise@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/09 14:19:30 by louise            #+#    #+#             */
/*   Updated: 2020/11/09 14:19:42 by louise           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "cub3d.h"

void	draw_square(t_image_data *img, int color, int tile_size)
{
	int i;
	int j;

	i = -1;
	while (++i < tile_size)
	{
		j = -1;
		my_mlx_pixel_put(img, i, 0, color);
		while (++j < tile_size)
			my_mlx_pixel_put(img, i, j, color);
	}
}