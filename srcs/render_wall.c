/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render_wall.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lsoulier <lsoulier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/12 17:05:47 by lsoulier          #+#    #+#             */
/*   Updated: 2020/11/13 02:07:35 by user42           ###   ########.fr       */
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

	correct_angle = ray.ray_angle - vars->player.rotation_angle;
	correct_distance = ray.distance * cos(degree_to_radian(correct_angle));
	wall_height = projection_plane_distance
		* (vars->tile_size / correct_distance);
	return (wall_height);
}

double	max_height_correct(double calculated_wall_height,
	double win_height)
{
	double correct_wall_height;

	if (calculated_wall_height > win_height)
		correct_wall_height = win_height;
	else
		correct_wall_height = calculated_wall_height;
	return (correct_wall_height);
}

t_point	ylocation_correct(double win_height, double wall_height, int i)
{
	t_point new_location;
	int		ylocation;

	ylocation = (win_height / 2) - (wall_height / 2);
	if (ylocation < 0)
		ylocation = 0;
	set_point(&new_location, i, ylocation);
	return (new_location);
}

int		wall_color(double wall_height, double win_height)
{
	int shade;

	shade = 255 - (25 * win_height / wall_height);
	return (create_trgb(0, shade, shade, shade));
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
		wall_height = fishbowl_correct(vars, rays[i],
			distance_to_projection_plane);
		location = ylocation_correct(vars->win_res.height, wall_height, i);
		set_dimension(&wall_dimension, 1,
			max_height_correct(wall_height, vars->win_res.height));
		draw_rect(view, location, wall_dimension,
			wall_color(wall_height, vars->win_res.height));
	}
}
