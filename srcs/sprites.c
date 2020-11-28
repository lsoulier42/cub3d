/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sprites.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lsoulier <lsoulier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/23 15:50:11 by lsoulier          #+#    #+#             */
/*   Updated: 2020/11/29 00:18:03 by user42           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	init_sprite(t_mlx_vars *vars)
{
	int		y;
	int		x;
	int		sprite_id;

	y = -1;
	sprite_id = 0;
	while (vars->parsed_file.map[++y])
	{
		x = -1;
		while (vars->parsed_file.map[y][++x])
		{
			if (vars->parsed_file.map[y][x] == '2')
			{
				set_point(&vars->sprites[sprite_id].position,
					x + 0.5, y + 0.5);
				vars->sprites[sprite_id].distance = 0;
				vars->sprites[sprite_id].angle = 0;
				vars->sprites[sprite_id].is_visible = 0;
				sprite_id++;
			}
		}
	}
}

int		init_sprites(t_mlx_vars *vars)
{
	int y;
	int x;

	y = -1;
	vars->nb_sprites = 0;
	while (vars->parsed_file.map[++y])
	{
		x = -1;
		while (vars->parsed_file.map[y][++x])
		{
			if (vars->parsed_file.map[y][x] == '2')
				vars->nb_sprites++;
		}
	}
	vars->sprites = (t_sprite*)malloc(sizeof(t_sprite) * vars->nb_sprites);
	if (!vars->sprites)
	{
		error_msg(ALLOCATION_ERROR);
		return (0);
	}
	init_sprite(vars);
	return (1);
}

float	calculate_sprite_angle(t_point sprite_position,
	t_point player_position, float player_rotation_angle)
{
	t_point	position_to_player;
	float	angle_to_orthogonal_plane;
	float	sprite_angle;

	set_point(&position_to_player,
		sprite_position.x - player_position.x,
		sprite_position.y - player_position.y);
	angle_to_orthogonal_plane = atan2(position_to_player.y,
		position_to_player.x);
	sprite_angle = angle_to_orthogonal_plane - player_rotation_angle;
	return (sprite_angle);
}

int		sprite_is_visible(float sprite_angle)
{
	if (sprite_angle < -M_PI)
		sprite_angle += 2 * M_PI;
	if (sprite_angle >= M_PI)
		sprite_angle -= 2 * M_PI;
	return (ft_abs(sprite_angle) < degree_to_radian(FOV_ANGLE / 2.0));
}

void	process_sprites(t_mlx_vars *vars)
{
	int		i;
	float	distance;
	float	angle;

	i = -1;
	while (++i < vars->nb_sprites)
	{
		distance = distance_points(vars->sprites[i].position,
			vars->player.current_pos);
		vars->sprites[i].distance = distance;
		angle = calculate_sprite_angle(vars->sprites[i].position,
			vars->player.current_pos, vars->player.rotation_angle);
		vars->sprites[i].angle = angle;
		vars->sprites[i].is_visible = sprite_is_visible(vars->sprites[i].angle);
	}
	sort_sprites(vars->sprites, vars->nb_sprites);
	get_sprites_positions(vars);
}
