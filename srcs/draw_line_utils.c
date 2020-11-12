/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_line_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: louise <lsoulier@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/08 19:55:26 by louise            #+#    #+#             */
/*   Updated: 2020/11/12 14:42:15 by user42           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "cub3d.h"

void	line_diagonal(t_image_data *map,
	t_point start, t_point end, int color)
{
	t_point	coord;
	int		diff;
	int		xstep;
	int		ystep;
	int		i;

	set_point(&coord, start.x, start.y);
	xstep = -1;
	ystep = -1;
	if (end.x - start.x > 0)
		xstep = 1;
	if (end.y - start.y > 0)
		ystep = 1;
	diff = ft_abs(end.x - start.x);
	i = -1;
	while (++i < diff)
	{
		coord.x += xstep;
		coord.y += ystep;
		my_mlx_pixel_put(map, coord.x, coord.y, color);
	}
}

void	line_horizontal(t_image_data *map,
	t_point start, t_point end, int color)
{
	int	x;
	int	y;
	int	absdx;
	int	xstep;
	int	i;

	x = start.x;
	y = start.y;
	if (end.x - start.x > 0)
		xstep = 1;
	else
		xstep = -1;
	absdx = ft_abs(end.x - start.x);
	i = -1;
	while (++i < absdx)
	{
		x += xstep;
		my_mlx_pixel_put(map, x, y, color);
	}
}

void	line_vertical(t_image_data *map,
	t_point start, t_point end, int color)
{
	int x;
	int y;
	int ystep;
	int i;
	int absdy;

	x = start.x;
	y = start.y;
	if (end.y - start.y > 0)
		ystep = 1;
	else
		ystep = -1;
	absdy = ft_abs(end.y - start.y);
	i = -1;
	while (++i < absdy)
	{
		y += ystep;
		my_mlx_pixel_put(map, x, y, color);
	}
}
