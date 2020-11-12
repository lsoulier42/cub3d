/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycasting_intersection.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lsoulier <lsoulier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/12 16:00:41 by lsoulier          #+#    #+#             */
/*   Updated: 2020/11/12 22:30:55 by user42           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

t_point	first_horizontal_intercept(t_mlx_vars *vars, t_ray ray)
{
	t_point	horizontal;

	horizontal.y = floor(vars->player.current_pos.y / vars->tile_size)
		* vars->tile_size;
	if (ray.facing_down)
		horizontal.y += vars->tile_size;
	horizontal.x = vars->player.current_pos.x
		+ ((horizontal.y - vars->player.current_pos.y) / tan(ray.ray_angle));
	return (horizontal);
}

t_point	find_horizontal_intercept(t_mlx_vars *vars, t_ray ray)
{
	t_point	next;
	double	xstep;
	double	ystep;
	int		offset_facing_up;

	offset_facing_up = 0;
	next = first_horizontal_intercept(vars, ray);
	ystep = vars->tile_size;
	if (!ray.facing_down)
		ystep *= -1;
	xstep = vars->tile_size / tan(ray.ray_angle);
	if ((ray.facing_left && xstep > 0) || (!ray.facing_left && xstep < 0))
		xstep *= -1;
	if (!ray.facing_down)
		offset_facing_up = 1;
	while (!is_wall(vars, next.x, next.y - offset_facing_up))
	{
		next.x += xstep;
		next.y += ystep;
	}
	return (next);
}

t_point	first_vertical_intercept(t_mlx_vars *vars, t_ray ray)
{
	t_point	vertical;

	vertical.x = floor(vars->player.current_pos.x / vars->tile_size)
		* vars->tile_size;
	if (!ray.facing_left)
		vertical.x += vars->tile_size;
	vertical.y = vars->player.current_pos.y
		+ ((vertical.x - vars->player.current_pos.x) * tan(ray.ray_angle));
	return (vertical);
}

t_point	find_vertical_intercept(t_mlx_vars *vars, t_ray ray)
{
	t_point	next;
	double	xstep;
	double	ystep;
	int		offset_facing_left;

	offset_facing_left = 0;
	next = first_vertical_intercept(vars, ray);
	xstep = vars->tile_size;
	if (ray.facing_left)
		xstep *= -1;
	ystep = vars->tile_size * tan(ray.ray_angle);
	if ((!ray.facing_down && ystep > 0) || (ray.facing_down && ystep < 0))
		ystep *= -1;
	if (ray.facing_left)
		offset_facing_left = 1;
	while (!is_wall(vars, next.x - offset_facing_left, next.y))
	{
		next.x += xstep;
		next.y += ystep;
	}
	return (next);
}
