/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pixel.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: louise <lsoulier@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/02 17:51:12 by louise            #+#    #+#             */
/*   Updated: 2020/11/12 22:24:10 by user42           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"
#include "libft.h"

void	print_player(t_mlx_vars *vars, t_player player)
{
	t_point minimap_pos;

	set_point(&minimap_pos, player.current_pos.x * MINIMAP_SCALE,
		player.current_pos.y * MINIMAP_SCALE);
	draw_circle(&vars->map_img, minimap_pos,
		MINIMAP_SCALE * (player.size / 2), color_trgb(RED));
}

void	update_player_position(t_mlx_vars *vars)
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
