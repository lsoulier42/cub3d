/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycasting_intersection.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: louise <lsoulier@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/12 13:48:00 by louise		       #+#    #+#             */
/*   Updated: 2020/11/12 13:58:38 by user42           ###   ########.fr       */
/* ************************************************************************** */

#include "cub3d.h"

t_point	first_intersection_horizontal(t_mlx_vars *vars, t_ray ray)
{
	t_point	first_intersection;

	first_intersection.y = floor(vars->player.current_pos.y / vars->tile_size)
		* vars->tile_size;
	if (ray.facing_down)
		first_intersection.y += vars->tile_size;
	first_intersection.x = vars->player.current_pos.x
		+ ((first_intersection.y - vars->player.current_pos.y)
		/ tan(ray.ray_angle));
	return (first_intersection);
}

t_point	find_horizontal_intersection(t_mlx_vars *vars, t_ray ray)
{
	t_point	next_intersection;
	int		xstep;
	int		ystep;
	int		offset_facing_up;

	offset_facing_up = 0;
	next_intersection = first_intersection_horizontal(vars, ray);
	ystep = vars->tile_size;
	if (!ray.facing_down)
		ystep *= -1;
	xstep = vars->tile_size / tan(ray.ray_angle);
	if ((ray.facing_left && xstep > 0) || (!ray.facing_left && xstep < 0))
		xstep *= -1;
	if (!ray.facing_down)
		offset_facing_up = 1;
	while (!is_wall(vars, next_intersection.x,
		next_intersection.y - offset_facing_up))
		set_point(&next_intersection,
			next_intersection.x + xstep, next_intersection.y + ystep);
	return(next_intersection);
}

t_point	first_intersection_vertical(t_mlx_vars *vars, t_ray ray)
{
	t_point	first_intersection;

	first_intersection.x = floor(vars->player.current_pos.x / vars->tile_size)
		* vars->tile_size;
	if (!ray.facing_left)
		first_intersection.x += vars->tile_size;
	first_intersection.y = vars->player.current_pos.y
		+ ((first_intersection.x - vars->player.current_pos.x)
		* tan(ray.ray_angle));
	return (first_intersection);
}

t_point	find_vertical_intersection(t_mlx_vars *vars, t_ray ray)
{
	t_point	next_intersection;
	int		xstep;
	int		ystep;
	int		offset_facing_left;

	offset_facing_left = 0;
	next_intersection = first_intersection_vertical(vars, ray);
	xstep = vars->tile_size;
	if (ray.facing_left)
		xstep *= -1;
	ystep = vars->tile_size * tan(ray.ray_angle);
	if ((!ray.facing_down && ystep > 0) || (ray.facing_down && ystep < 0))
		ystep *= -1;
	if (ray.facing_left)
		offset_facing_left = 1;
	while (!is_wall(vars, next_intersection.x - offset_facing_left,
		next_intersection.y))
		set_point(&next_intersection,
			next_intersection.x + xstep, next_intersection.y + ystep);
	return(next_intersection);
}