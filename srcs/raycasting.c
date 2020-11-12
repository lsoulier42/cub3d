/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycasting.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: louise <lsoulier@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/11 20:03:06 by user42            #+#    #+#             */
/*   Updated: 2020/11/12 03:18:33 by user42           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "cub3d.h"

t_point find_horizontal_intersection(t_mlx_vars *vars, t_ray ray)
{
	t_point first_intersection;
	t_point next_intersection;
	int xstep;
	int ystep;
	int offset_facing_up;

	offset_facing_up = 0;
	first_intersection.y = floor(vars->player.current_pos.y / vars->tile_size) * vars->tile_size;
	if (ray.facing_down)
		first_intersection.y += vars->tile_size;
	first_intersection.x = vars->player.current_pos.x + ((first_intersection.y - vars->player.current_pos.y) / tan(ray.ray_angle));
	ystep = vars->tile_size;
	if (!ray.facing_down)
		ystep *= -1;
	xstep = vars->tile_size / tan(ray.ray_angle);
	if ((ray.facing_left && xstep > 0) || (!ray.facing_left && xstep < 0))
		xstep *= -1;
	next_intersection = first_intersection;
	if (!ray.facing_down)
		offset_facing_up = 1;
	while (!is_wall(vars, next_intersection.x, next_intersection.y - offset_facing_up))
		set_point(&next_intersection, next_intersection.x + xstep, next_intersection.y + ystep);
	return(next_intersection);
}

t_point find_vertical_intersection(t_mlx_vars *vars, t_ray ray)
{
	t_point first_intersection;
	t_point next_intersection;
	int xstep;
	int ystep;
	int offset_facing_left;

	offset_facing_left = 0;
	first_intersection.x = floor(vars->player.current_pos.x / vars->tile_size) * vars->tile_size;
	if (!ray.facing_left)
		first_intersection.x += vars->tile_size;
	first_intersection.y = vars->player.current_pos.y + ((first_intersection.x - vars->player.current_pos.x) * tan(ray.ray_angle));
	xstep = vars->tile_size;
	if (ray.facing_left)
		xstep *= -1;
	ystep = vars->tile_size * tan(ray.ray_angle);
	if ((!ray.facing_down && ystep > 0) || (ray.facing_down && ystep < 0))
		ystep *= -1;
	next_intersection = first_intersection;
	if (ray.facing_left)
		offset_facing_left = 1;
	while (!is_wall(vars, next_intersection.x - offset_facing_left, next_intersection.y))
		set_point(&next_intersection, next_intersection.x + xstep, next_intersection.y + ystep);

	return(next_intersection);
}

void 	cast_ray(t_mlx_vars *vars, t_ray *ray)
{
	t_point horizontal_intersection;
	t_point vertical_intersection;
	int horizontal_distance;
	int vertical_distance;

	horizontal_intersection = find_horizontal_intersection(vars, *ray);
	vertical_intersection = find_vertical_intersection(vars, *ray);
	horizontal_distance = distance_points(vars->player.current_pos, horizontal_intersection);
	vertical_distance = distance_points(vars->player.current_pos, vertical_intersection);
	if (vertical_distance > horizontal_distance)
	{
		ray->distance = horizontal_distance;
		ray->wall_hit = horizontal_intersection;
	}
	else
	{
		ray->distance = vertical_distance;
		ray->wall_hit = vertical_intersection;
		ray->was_hit_vertical = 1;
	}
}

void 	init_ray(t_ray *ray, double ray_angle, int column_index)
{
	ray->ray_angle = ray_angle;
	set_point(&ray->wall_hit, 0, 0);
	ray->distance = 0;
	ray->facing_down = 0;
	ray->facing_left = 0;
	if (ray_angle > 0 && ray_angle < M_PI)
		ray->facing_down = 1;
	if (ray_angle >= (M_PI * 0.5) && ray_angle <= (1.5 * M_PI))
		ray->facing_left = 1;
	ray->was_hit_vertical = 0;
	ray->column_index = column_index;
}

t_ray    *cast_all_rays(t_mlx_vars *vars)
{
	int     column_index;
	double  ray_angle;
	int     i;
	t_ray   *rays;
	int		nb_column;

	nb_column = vars->win_res.width;
	column_index = 0;
	i = -1;
	ray_angle = vars->player.rotation_angle - (FOV_ANGLE / 2);
	rays = (t_ray*)malloc(sizeof(t_ray) * nb_column);
	if (!rays)
		return (NULL);
	while (++i < nb_column)
	{
		init_ray(&rays[i], normalize_angle(ray_angle), column_index);
		cast_ray(vars, rays + i);
		ray_angle += FOV_ANGLE / nb_column;
		column_index++;
	}
	return (rays);
}