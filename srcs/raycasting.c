/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycasting.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: louise <lsoulier@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/11 20:03:06 by user42            #+#    #+#             */
/*   Updated: 2020/11/14 00:27:43 by user42           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "cub3d.h"

void	cast_ray(t_mlx_vars *vars, t_ray *ray)
{
	t_point	horizontal_intercept;
	t_point	vertical_intercept;
	double	horizontal_distance;
	double	vertical_distance;

	horizontal_intercept = find_horizontal_intercept(vars, *ray);
	vertical_intercept = find_vertical_intercept(vars, *ray);
	horizontal_distance = distance_points(vars->player->current_pos,
		horizontal_intercept);
	vertical_distance = distance_points(vars->player->current_pos,
		vertical_intercept);
	if (vertical_distance >= horizontal_distance)
	{
		ray->distance = horizontal_distance;
		ray->wall_hit = horizontal_intercept;
	}
	else
	{
		ray->distance = vertical_distance;
		ray->wall_hit = vertical_intercept;
		ray->was_hit_vertical = 1;
	}
}

void	init_ray(t_ray *ray, double ray_angle)
{
	ray->angle = ray_angle;
	set_point(&ray->wall_hit, 0, 0);
	ray->distance = 0;
	ray->facing_down = 0;
	ray->facing_left = 0;
	if (ray_angle > 0 && ray_angle < M_PI)
		ray->facing_down = 1;
	if (ray_angle > (M_PI * 0.5) && ray_angle < (1.5 * M_PI))
		ray->facing_left = 1;
	ray->was_hit_vertical = 0;
}

t_ray	*cast_all_rays(t_mlx_vars *vars)
{
	double	ray_angle;
	int		i;
	t_ray	*rays;
	int		nb_column;

	i = -1;
	nb_column = vars->parsed_file->win_res.width;
	ray_angle = normalize_angle(vars->player->rotation_angle)
		- (degree_to_radian(FOV_ANGLE / 2));
	rays = (t_ray*)malloc(sizeof(t_ray) * nb_column);
	if (!rays)
		return (NULL);
	while (++i < nb_column)
	{
		init_ray(&rays[i], normalize_angle(ray_angle));
		cast_ray(vars, rays + i);
		ray_angle += degree_to_radian(FOV_ANGLE) / nb_column;
	}
	return (rays);
}
