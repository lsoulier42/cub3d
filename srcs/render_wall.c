/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render_wall.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lsoulier <lsoulier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/12 17:05:47 by lsoulier          #+#    #+#             */
/*   Updated: 2020/11/13 00:56:24 by user42           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "cub3d.h"

double	fishbowl_correction(double ray_distance,
	double ray_angle, double player_angle)
{
	double correct_distance;
	double correct_angle;

	correct_angle = ray_angle - player_angle;
	correct_distance = ray_distance
		* cos(degree_to_radian(correct_angle));
	return (correct_distance);
}

double 	wall_height_correction(double calculated_wall_height,
	double win_height)
{
	double correct_wall_height;

	if (calculated_wall_height > win_height)
		correct_wall_height = win_height;
	else
		correct_wall_height = calculated_wall_height;
	return (correct_wall_height);
}

void	render_wall(t_mlx_vars *vars, t_image_data *view, t_ray *rays)
{
	double		wall_height;
	double		distance_to_projection_plane;
	int			i;
	t_point		location;
	t_dimension	wall_dimension;

	i = -1;
	distance_to_projection_plane = (vars->win_res.width / 2)
		/ tan(degree_to_radian(FOV_ANGLE / 2));
	while (++i < vars->win_res.width)
	{
		wall_height = distance_to_projection_plane
			* (vars->tile_size
			/ fishbowl_correction(rays[i].distance,
			rays[i].ray_angle, vars->player.rotation_angle));
		set_point(&location, i,
			(vars->win_res.height / 2) - (wall_height / 2));
		if (location.y < 0)
			location.y = 0;
		set_dimension(&wall_dimension, 1,
			wall_height_correction(wall_height, vars->win_res.height));
		draw_rect(view, location, wall_dimension, color_trgb(WHITE));
	}
}
