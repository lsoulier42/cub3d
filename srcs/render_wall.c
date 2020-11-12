/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render_wall.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lsoulier <lsoulier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/12 17:05:47 by lsoulier          #+#    #+#             */
/*   Updated: 2020/11/12 22:31:39 by user42           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "cub3d.h"

double	fishbowl_correct(double ray_distance,
	double ray_angle, double player_angle)
{
	double correct_distance;
	double correct_angle;

	correct_angle = ray_angle - player_angle;
	correct_distance = ray_distance
		* cos(degree_to_radian(correct_angle));
	return (correct_distance);
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
			/ fishbowl_correct(rays[i].distance,
			rays[i].ray_angle, vars->player.rotation_angle));
		set_point(&location, i,
			(vars->win_res.height / 2) - (wall_height / 2));
		if (location.y < 0)
			location.y = 0;
		set_dimension(&wall_dimension, 1, wall_height);
		draw_rect(view, location, wall_dimension, color_trgb(WHITE));
	}
}
