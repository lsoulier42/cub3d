/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render_wall.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lsoulier <lsoulier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/12 17:05:47 by lsoulier          #+#    #+#             */
/*   Updated: 2020/11/28 22:08:06 by user42           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

float	fishbowl_correct(t_mlx_vars *vars, t_ray ray)
{
	float correct_distance;
	float correct_angle;
	float wall_height;

	correct_angle = ray.angle - normalize_angle(vars->player.rotation_angle);
	correct_distance = ray.distance * cos(correct_angle);
	wall_height = vars->distance_to_projection_plane / correct_distance;
	return (wall_height);
}

void	render_wall(t_mlx_vars *vars)
{
	float		wall_height;
	int			i;

	i = -1;
	while (++i < vars->parsed_file.win_res.width)
	{
		wall_height = fishbowl_correct(vars, vars->rays[i]);
		map_texture(vars, wall_height, i);
	}
}
