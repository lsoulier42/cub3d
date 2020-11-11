/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_line_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: louise <lsoulier@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/08 19:55:26 by louise            #+#    #+#             */
/*   Updated: 2020/11/08 19:57:33 by louise           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "cub3d.h"

void 	line_big_angle(t_image_data *map, t_point start, t_point end, int color)
{
	t_point coord;
	t_point pas;
	t_point abs;
	int reste;
	int i;

	reste = 0;
	set_point(&coord, start.x, start.y);
	end.x > start.x ? set_point(&pas, 1, 0) : set_point(&pas, -1, 0);
	end.y > start.y ? set_point(&pas, pas.x, 1) : set_point(&pas, pas.x, -1);
	set_point(&abs, ft_abs(end.x - start.x), ft_abs(end.y - start.y));
	i = -1;
	while (++i < abs.y)
	{
		coord.y += pas.y;
		reste += abs.x;
		if (reste >= abs.y)
		{
			reste -= abs.y;
			coord.x += pas.x;
		}
		my_mlx_pixel_put(map, coord.x, coord.y, color);
	}
}

void 	line_low_angle(t_image_data *map, t_point start, t_point end, int color)
{
	t_point coord;
	t_point pas;
	t_point abs;
	int reste;
	int i;

	reste = 0;
	set_point(&coord, start.x, start.y);
	end.x > start.x ? set_point(&pas, 1, 0) : set_point(&pas, -1, 0);
	end.y > start.y ? set_point(&pas, pas.x, 1) : set_point(&pas, pas.x, -1);
	set_point(&abs, ft_abs(end.x - start.x), ft_abs(end.y - start.y));
	i = -1;
	while (++i < abs.x)
	{
		coord.x += pas.x;
		reste += abs.y;
		if (reste >= abs.x)
		{
			reste -= abs.x;
			coord.y += pas.y;
		}
        my_mlx_pixel_put(map, coord.x, coord.y, color);
	}
}

void 	line_diagonal(t_image_data *map, t_point start, t_point end, int color)
{
	t_point	coord;
	int diff;
	int pasx;
	int pasy;
	int i;

	set_point(&coord, start.x, start.y);
	pasx = -1;
	pasy = -1;
	if (end.x - start.x > 0)
		pasx = 1;
	if (end.y - start.y > 0)
		pasy = 1;
	diff = ft_abs(end.x - start.x);
	i = -1;
	while (++i < diff)
	{
		coord.x += pasx;
		coord.y += pasy;
        my_mlx_pixel_put(map, coord.x, coord.y, color);
	}
}

void	line_horizontal(t_image_data *map, t_point start, t_point end, int color)
{
	int x;
	int y;
	int absdx;
	int pasx;
	int i;

	x = start.x;
	y = start.y;
	if (end.x - start.x > 0)
		pasx = 1;
	else
		pasx = -1;
	absdx = ft_abs(end.x - start.x);
	i = -1;
	while (++i < absdx)
	{
		x += pasx;
        my_mlx_pixel_put(map, x, y, color);
	}
}

void	line_vertical(t_image_data *map, t_point start, t_point end, int color)
{
	int x;
	int y;
	int pasy;
	int i;
	int absdy;

	x = start.x;
	y = start.y;
	if (end.y - start.y > 0)
		pasy = 1;
	else
		pasy = -1;
	absdy = ft_abs(end.y - start.y);
	i = -1;
	while (++i < absdy)
	{
		y += pasy;
        my_mlx_pixel_put(map, x, y, color);
	}
}