/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pixel.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: louise <lsoulier@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/02 17:51:12 by louise            #+#    #+#             */
/*   Updated: 2020/11/12 14:12:20 by user42           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"
#include "libft.h"

void print_player(t_mlx_vars *vars, t_player player)
{
	t_point	direction;

	direction.x = player.current_pos.x
		+ cos(player.rotation_angle)* (player.size / 2);
	direction.y = player.current_pos.y
		+ sin(player.rotation_angle) * (player.size / 2);
	draw_circle(&vars->map_img, player.current_pos,
		player.size / 2, color_trgb(RED));
	draw_line(&vars->map_img, player.current_pos,
		direction, color_trgb(RED));
}

int is_wall(t_mlx_vars *vars, int x, int y)
{
	int index_x;
	int index_y;

	index_x = floor(x / vars->tile_size);
	index_y = floor(y / vars->tile_size);
	if (index_x < 0 || index_y < 0
		|| index_x >= vars->map_res.width || index_y >= vars->map_res.height)
		return (1);
	else
		return (vars->map[index_y][index_x] == '1');
}

void update_player_position(t_mlx_vars *vars)
{
	int				move_step;
	t_point			next_position;

	vars->player.rotation_angle += vars->player.turn_direction
		* vars->player.rotation_speed;
	move_step = vars->player.walk_direction * vars->player.move_speed;
	next_position.x = vars->player.current_pos.x
		+ (cos(vars->player.rotation_angle) * move_step);
	next_position.y = vars->player.current_pos.y
		+ (sin(vars->player.rotation_angle) * move_step);
	if (!is_wall(vars, next_position.x, next_position.y))
	{
		vars->player.current_pos.x = next_position.x;
		vars->player.current_pos.y = next_position.y;
	}
}