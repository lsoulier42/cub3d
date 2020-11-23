/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycasting_intersection.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lsoulier <lsoulier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/12 16:00:41 by lsoulier          #+#    #+#             */
/*   Updated: 2020/11/22 19:12:11 by user42           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	find_horizontal_intercept_loop(t_mlx_vars *vars,
	t_ray *ray, t_point next, t_point step)
{
	t_point	next_touch;
	int		offset_facing_up;
	char	wall_hit_content;

	offset_facing_up = 0;
	if (!ray->facing_down)
		offset_facing_up = 1;
	while (next.x >= 0 && next.x < vars->parsed_file.win_res.width
		&& next.y >= 0 && next.y < vars->parsed_file.win_res.height)
	{
		set_point(&next_touch, next.x, next.y - offset_facing_up);
		wall_hit_content = is_wall_raycasting(vars, next_touch);
		if (wall_hit_content != '0')
		{
			set_point(&ray->wall_hit, next.x, next.y);
			ray->distance = distance_points(vars->player.current_pos,
				ray->wall_hit);
			ray->wall_hit_content = wall_hit_content;
			ray->was_hit_north = !offset_facing_up;
			ray->was_hit_south = !ray->was_hit_north;
			break ;
		}
		else
			set_point(&next, next.x + step.x, next.y + step.y);
	}
}

void	find_horizontal_intercept(t_mlx_vars *vars, t_ray *ray)
{
	t_point	first;
	t_point	step;

	first.y = floor(vars->player.current_pos.y / CELL_SIZE) * CELL_SIZE;
	if (ray->facing_down)
		first.y += CELL_SIZE;
	first.x = vars->player.current_pos.x
		+ ((first.y - vars->player.current_pos.y) / tan(ray->angle));
	step.y = CELL_SIZE;
	if (!ray->facing_down)
		step.y *= -1;
	step.x = CELL_SIZE / tan(ray->angle);
	if ((ray->facing_left && step.x > 0) || (!ray->facing_left && step.x < 0))
		step.x *= -1;
	find_horizontal_intercept_loop(vars, ray, first, step);
}

void	reset_ray_setting(t_ray *ray, double vertical_len, t_point wall_found,
	char hit_content)
{
	ray->distance = vertical_len;
	set_point(&ray->wall_hit, wall_found.x, wall_found.y);
	ray->wall_hit_content = hit_content;
	ray->was_hit_north = 0;
	ray->was_hit_south = 0;
	ray->was_hit_west = !ray->facing_left;
	ray->was_hit_east = !ray->was_hit_west;
	ray->was_hit_vertical = 1;
}

void	find_vertical_intercept_loop(t_mlx_vars *vars, t_ray *ray,
	t_point next, t_point step)
{
	t_point	next_touch;
	int		offset_facing_left;
	char	wall_hit_content;
	double	vertical_len;

	offset_facing_left = 0;
	if (ray->facing_left)
		offset_facing_left = 1;
	while (next.x >= 0 && next.x < vars->parsed_file.win_res.width
		&& next.y >= 0 && next.y < vars->parsed_file.win_res.height)
	{
		set_point(&next_touch, next.x - offset_facing_left, next.y);
		wall_hit_content = is_wall_raycasting(vars, next_touch);
		if (wall_hit_content != '0')
		{
			vertical_len = distance_points(vars->player.current_pos, next);
			if (vertical_len < ray->distance || ray->distance == 0)
				reset_ray_setting(ray, vertical_len, next, wall_hit_content);
			break ;
		}
		else
			set_point(&next, next.x + step.x, next.y + step.y);
	}
}

void	find_vertical_intercept(t_mlx_vars *vars, t_ray *ray)
{
	t_point	first;
	t_point step;

	first.x = floor(vars->player.current_pos.x / CELL_SIZE) * CELL_SIZE;
	if (!ray->facing_left)
		first.x += CELL_SIZE;
	first.y = vars->player.current_pos.y
		+ ((first.x - vars->player.current_pos.x) * tan(ray->angle));
	step.x = CELL_SIZE;
	if (ray->facing_left)
		step.x *= -1;
	step.y = CELL_SIZE * tan(ray->angle);
	if ((!ray->facing_down && step.y > 0) || (ray->facing_down && step.y < 0))
		step.y *= -1;
	find_vertical_intercept_loop(vars, ray, first, step);
}
