/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_segment.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: louise <lsoulier@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/07 15:03:30 by louise            #+#    #+#             */
/*   Updated: 2020/11/08 19:58:15 by louise           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "cub3d.h"

void	draw_line(t_mlx_vars *vars, t_point start, t_point end, int color)
{
	t_image_data pixel;
	int dx;
	int dy;
	int absdx;
	int absdy;

	dx = end.x - start.x;
	dy = end.y - start.y;
	absdx = ft_abs(dx);
	absdy = ft_abs(dy);
	my_mlx_new_image(vars, &pixel, 1, 1);
	my_mlx_pixel_put(&pixel, 0, 0, color);
	mlx_put_image_to_window(vars->mlx, vars->win, pixel.img, start.x, start.y);
	if (dx == 0)
		line_vertical(vars, start, end, pixel);
	else if (dy == 0)
		line_horizontal(vars, start, end, pixel);
	else if (absdx == absdy)
		line_diagonal(vars, start, end, pixel);
	else if (absdx > absdy)
		line_low_angle(vars, start, end, pixel);
	else
		line_big_angle(vars, start, end, pixel);
}