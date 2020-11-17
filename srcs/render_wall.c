/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render_wall.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lsoulier <lsoulier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/12 17:05:47 by lsoulier          #+#    #+#             */
/*   Updated: 2020/11/17 23:56:58 by user42           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "cub3d.h"

double	fishbowl_correct(t_mlx_vars *vars, t_ray ray,
	double projection_plane_distance)
{
	double correct_distance;
	double correct_angle;
	double wall_height;

	correct_angle = ray.angle - normalize_angle(vars->player->rotation_angle);
	correct_distance = ray.distance * cos(correct_angle);
	wall_height = projection_plane_distance
		* (vars->cell_size / correct_distance);
	return (wall_height);
}

void	render_wall(t_mlx_vars *vars)
{
	double		wall_height;
	double		distance_to_projection_plane;
	int			i;
	t_dimension	wall_dimension;

	i = -1;
	distance_to_projection_plane = (vars->parsed_file->win_res.width / 2)
		/ tan(degree_to_radian(FOV_ANGLE / 2));
	while (++i < vars->parsed_file->win_res.width)
	{
		wall_height = fishbowl_correct(vars, vars->rays[i],
			distance_to_projection_plane);
		set_dimension(&wall_dimension, 1,
			wall_height);
		map_texture(vars, wall_dimension, i);
	}
}
