/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_line_angle_utils.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lsoulier <lsoulier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/12 14:39:38 by lsoulier          #+#    #+#             */
/*   Updated: 2020/11/12 14:57:28 by user42           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "cub3d.h"

void	line_big_angle_loop(t_image_data *map, t_line_drawing big, int color)
{
	int		i;
	double	rest;
	t_point	coord;
	t_point	step;
	t_point	abs;

	i = -1;
	rest = 0;
	coord = big.coord;
	step = big.step;
	abs = big.abs;
	while (++i < abs.y)
	{
		coord.y += step.y;
		rest += abs.x;
		if (rest >= abs.y)
		{
			rest -= abs.y;
			coord.x += step.x;
		}
		my_mlx_pixel_put(map, coord.x, coord.y, color);
	}
}

void	line_big_angle(t_image_data *map,
	t_point start, t_point end, int color)
{
	t_point			coord;
	t_point			step;
	t_point			abs;
	t_line_drawing	big;

	set_point(&coord, start.x, start.y);
	set_point(&step, -1, 0);
	if (end.x > start.x)
		set_point(&step, 1, 0);
	set_point(&step, step.x, -1);
	if (end.y > start.y)
		set_point(&step, step.x, 1);
	set_point(&abs, ft_abs(end.x - start.x), ft_abs(end.y - start.y));
	big.step = step;
	big.abs = abs;
	big.coord = coord;
	line_big_angle_loop(map, big, color);
}

void	line_low_angle_loop(t_image_data *map, t_line_drawing low, int color)
{
	double	rest;
	int		i;
	t_point	coord;
	t_point	step;
	t_point	abs;

	rest = 0;
	i = -1;
	coord = low.coord;
	step = low.step;
	abs = low.abs;
	while (++i < abs.x)
	{
		coord.x += step.x;
		rest += abs.y;
		if (rest >= abs.x)
		{
			rest -= abs.x;
			coord.y += step.y;
		}
		my_mlx_pixel_put(map, coord.x, coord.y, color);
	}
}

void	line_low_angle(t_image_data *map,
	t_point start, t_point end, int color)
{
	t_point			coord;
	t_point			step;
	t_point			abs;
	t_line_drawing	low;

	set_point(&coord, start.x, start.y);
	set_point(&step, -1, 0);
	if (end.x > start.x)
		set_point(&step, 1, 0);
	set_point(&step, step.x, -1);
	if (end.y > start.y)
		set_point(&step, step.x, 1);
	set_point(&abs, ft_abs(end.x - start.x), ft_abs(end.y - start.y));
	low.coord = coord;
	low.step = step;
	low.abs = abs;
	line_low_angle_loop(map, low, color);
}
