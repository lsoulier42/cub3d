/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycasting.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: louise <lsoulier@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/11 20:03:06 by user42            #+#    #+#             */
/*   Updated: 2020/11/12 13:46:26 by user42           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "cub3d.h"

void 	cast_ray(t_mlx_vars *vars, t_ray *ray)
{
	t_point	horizontal_intersection;
	t_point	vertical_intersection;
	int		horizontal_distance;
	int		vertical_distance;

	horizontal_intersection = find_horizontal_intersection(vars, *ray);
	vertical_intersection = find_vertical_intersection(vars, *ray);
	horizontal_distance = distance_points(vars->player.current_pos,
		horizontal_intersection);
	vertical_distance = distance_points(vars->player.current_pos,
		vertical_intersection);
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
	int		column_index;
	double	ray_angle;
	int		i;
	t_ray	*rays;
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