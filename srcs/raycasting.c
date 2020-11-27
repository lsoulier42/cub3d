/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycasting.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: louise <lsoulier@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/11 20:03:06 by user42            #+#    #+#             */
/*   Updated: 2020/11/24 15:14:51 by user42           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

char	is_wall_raycasting(t_mlx_vars *vars, t_point next_touch)
{
	int			index_x;
	int			index_y;
	char		**map;
	t_dimension	map_res;

	map = vars->parsed_file.map;
	map_res = vars->parsed_file.map_res;
	index_x = floor(next_touch.x / vars->cell_size);
	index_y = floor(next_touch.y / vars->cell_size);
	if (index_x < 0 || index_y < 0
		|| index_x >= map_res.width || index_y >= map_res.height)
		return ('1');
	else
		return (map[index_y][index_x]);
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
	ray->was_hit_north = 0;
	ray->was_hit_south = 0;
	ray->was_hit_west = 0;
	ray->was_hit_east = 0;
	ray->wall_hit_content = '1';
	ray->was_hit_vertical = 0;
}

void	cast_all_rays(t_mlx_vars *vars)
{
	double	ray_angle;
	int		i;
	int		nb_column;

	i = -1;
	nb_column = vars->parsed_file.win_res.width;
	while (++i < nb_column)
	{
		ray_angle = vars->player.rotation_angle
			+ atan((i - (nb_column / 2)) / vars->distance_to_projection_plane);
		init_ray(&vars->rays[i], normalize_angle(ray_angle));
		find_horizontal_intercept(vars, &vars->rays[i]);
		find_vertical_intercept(vars, &vars->rays[i]);
	}
}
