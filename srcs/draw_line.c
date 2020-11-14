/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_segment.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: louise <lsoulier@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/07 15:03:30 by louise            #+#    #+#             */
/*   Updated: 2020/11/13 02:13:55 by user42           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "cub3d.h"

void	draw_line(t_image_data *map, t_point start, t_point end, int color)
{
	double dx;
	double dy;
	double absdx;
	double absdy;

	dx = end.x - start.x;
	dy = end.y - start.y;
	absdx = ft_abs(dx);
	absdy = ft_abs(dy);
	my_mlx_pixel_put(map, start.x, start.y, color);
	if (dx == 0)
		line_vertical(map, start, end, color);
	else if (dy == 0)
		line_horizontal(map, start, end, color);
	else if (absdx == absdy)
		line_diagonal(map, start, end, color);
	else if (absdx > absdy)
		line_low_angle(map, start, end, color);
	else
		line_big_angle(map, start, end, color);
}
