/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_segment.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: louise <lsoulier@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/07 15:03:30 by louise            #+#    #+#             */
/*   Updated: 2020/11/07 15:17:51 by louise           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "cub3d.h"

void draw_segment_dx(t_image_data *segment, t_point start, t_point end, int color)
{
	int i;
	int dx;
	int dy;

	i = 0;
	dx = ft_abs(end.x - start.x);
	dy = ft_abs(end.y - start.y);
	while (++i < dx)
	{
		if (end.x - start.x >= 0)
			my_mlx_pixel_put(segment, i, i * dy / dx, color);
		else
			my_mlx_pixel_put(segment, dx - i, dy - (i * dy / dx), color);
	}
}

void draw_segment_dy(t_image_data *segment, t_point start, t_point end, int color)
{
	int i;
	int dx;
	int dy;

	i = 0;
	dx = ft_abs(end.x - start.x);
	dy = ft_abs(end.y - start.y);
	while (++i < dy)
	{
		if (end.y - start.y >= 0)
			my_mlx_pixel_put(segment, i * dx / dy, i, color);
		else
			my_mlx_pixel_put(segment, dx - (i * dx / dy), dy - i, color);
	}
}

void draw_segment(t_mlx_vars *vars, t_point start, t_point end, int color)
{
	t_image_data segment;
	int dx;
	int dy;

	dx = ft_abs(end.x - start.x);
	dy = ft_abs(end.y - start.y);
	my_mlx_new_image(vars->mlx, &segment, dx, dy);
	if (dx >= dy)
		draw_segment_dx(&segment, start, end, color);
	else
		draw_segment_dy(&segment, start, end, color);
	mlx_put_image_to_window(vars->mlx, vars->win,
		segment.img, start.x, start.y);
}