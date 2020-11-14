/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   collisions.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lsoulier <lsoulier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/14 03:26:35 by lsoulier          #+#    #+#             */
/*   Updated: 2020/11/14 04:17:41 by user42           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "cub3d.h"

int		is_wall(t_mlx_vars *vars, double x, double y)
{
	int			index_x;
	int			index_y;
	char		**map;
	int			tile_size;
	t_dimension	map_res;

	map = vars->parsed_file->map;
	tile_size = vars->parsed_file->tile_size;
	map_res = vars->parsed_file->map_res;
	index_x = floor(x / tile_size);
	index_y = floor(y / tile_size);
	if (index_x < 0 || index_y < 0
		|| index_x >= map_res.width || index_y >= map_res.height)
		return (1);
	else
		return (map[index_y][index_x] == '1');
}

void	update_player_position(t_mlx_vars *vars)
{
	double			move_step;
	t_point			next_position;

	vars->player->rotation_angle += vars->player->turn_direction
									* vars->player->rotation_speed;
	move_step = vars->player->walk_direction * vars->player->move_speed;
	next_position.x = vars->player->current_pos.x
		+ (cos(vars->player->rotation_angle) * move_step);
	next_position.y = vars->player->current_pos.y
		+ (sin(vars->player->rotation_angle) * move_step);
	if (!is_wall(vars, next_position.x, next_position.y))
	{
		vars->player->current_pos.x = next_position.x;
		vars->player->current_pos.y = next_position.y;
	}
}
