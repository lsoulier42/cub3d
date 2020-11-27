/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   collisions.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lsoulier <lsoulier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/14 03:26:35 by lsoulier          #+#    #+#             */
/*   Updated: 2020/11/27 02:40:42 by user42           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int		is_wall(t_mlx_vars *vars, double x, double y)
{
	int			index_x;
	int			index_y;
	char		**map;
	t_dimension	map_res;

	map = vars->parsed_file.map;
	map_res = vars->parsed_file.map_res;
	index_x = floor(x / vars->cell_size);
	index_y = floor(y / vars->cell_size);
	if (index_x < 0 || index_y < 0
		|| index_x >= map_res.width || index_y >= map_res.height)
		return (1);
	return (map[index_y][index_x] != '0');
}

void	update_player_position(t_mlx_vars *vars, t_player *player)
{
	double			move_step;
	t_point			next_position;
	double			xstep;
	double			ystep;

	player->rotation_angle += player->turn_direction
									* player->rotation_speed;
	move_step = player->walk_direction * player->move_speed;
	xstep = cos(player->rotation_angle + player->direction_angle);
	ystep = sin(player->rotation_angle + player->direction_angle);
	next_position.x = player->current_pos.x
		+ (xstep * move_step);
	next_position.y = player->current_pos.y
		+ (ystep * move_step);
	if (!is_wall(vars, next_position.x, next_position.y))
	{
		player->current_pos.x = next_position.x;
		player->current_pos.y = next_position.y;
	}
	player->rotation_angle = normalize_angle(player->rotation_angle);
}
