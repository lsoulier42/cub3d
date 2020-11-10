/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_circle.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: louise <lsoulier@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/08 22:28:40 by louise            #+#    #+#             */
/*   Updated: 2020/11/09 17:49:37 by louise           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "cub3d.h"

void circle_pixelset(t_mlx_vars *vars, t_image_data pixel, t_point center, t_point coord)
{
	mlx_put_image_to_window(vars->mlx, vars->win, pixel.img, center.x + coord.x, center.y + coord.y);
	mlx_put_image_to_window(vars->mlx, vars->win, pixel.img, center.x + coord.y, center.y + coord.x);
	mlx_put_image_to_window(vars->mlx, vars->win, pixel.img, center.x - coord.x, center.y + coord.y);
	mlx_put_image_to_window(vars->mlx, vars->win, pixel.img, center.x - coord.y, center.y + coord.x);
	mlx_put_image_to_window(vars->mlx, vars->win, pixel.img, center.x + coord.x, center.y - coord.y);
	mlx_put_image_to_window(vars->mlx, vars->win, pixel.img, center.x + coord.y, center.y - coord.x);
	mlx_put_image_to_window(vars->mlx, vars->win, pixel.img, center.x - coord.x, center.y - coord.y);
	mlx_put_image_to_window(vars->mlx, vars->win, pixel.img, center.x - coord.y, center.y - coord.x);
}

void draw_circle(t_mlx_vars *vars, t_point center, int ray, int color)
{
	t_image_data pixel;
	t_point coord;
	int d;

	my_mlx_new_image(vars, &pixel, 1, 1);
	my_mlx_pixel_put(&pixel, 0, 0, color);
	d = 3 - (2 * ray);
	set_point(&coord, 0, ray);
	while (coord.y >= coord.x) {
		circle_pixelset(vars, pixel, center, coord);
		if (d < 0)
			d += coord.x * 4 + 6;
		else {
			d += (coord.x - coord.y) * 4 + 10;
			coord.y--;
		}
		coord.x++;
	}
}