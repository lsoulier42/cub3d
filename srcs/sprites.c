/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sprites.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lsoulier <lsoulier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/23 15:50:11 by lsoulier          #+#    #+#             */
/*   Updated: 2020/11/25 18:47:20 by user42           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void init_sprite(t_mlx_vars *vars)
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
			  		(x * vars->cell_size),
					(y * vars->cell_size));
				vars->sprites[sprite_id].distance = 0;
				vars->sprites[sprite_id].angle = 0;
				vars->sprites[sprite_id].is_visible = 0;
				sprite_id++;
			}
		}
	}
}

int init_sprites(t_mlx_vars *vars)
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

double calculate_sprite_angle(t_point sprite_position, t_point player_position, double player_rotation_angle)
{
	t_point position_to_player;
	double angle_to_orthogonal_plane;
	double sprite_angle;

	set_point(&position_to_player, sprite_position.x - player_position.x,
			  sprite_position.y - player_position.y);
	angle_to_orthogonal_plane = atan2(position_to_player.y, position_to_player.x);
	sprite_angle = angle_to_orthogonal_plane - player_rotation_angle;
	return (sprite_angle);
}

int sprite_is_visible(double sprite_angle)
{
	if (sprite_angle < -M_PI)
		sprite_angle += 2 * M_PI;
	if (sprite_angle >= M_PI)
		sprite_angle -= 2 * M_PI;
	return (ft_abs(sprite_angle) < degree_to_radian(FOV_ANGLE / 2.0));
}

void render_sprites(t_mlx_vars *vars)
{
	int i;
	double sprite_height;
	int sprite_top_pixel;
	int sprite_bottom_pixel;
	double first_x_position;
	double sprite_width;
	double sprite_width_end;
	t_point	sprite_texture_offset;
	int color;
	int transparency_color;
	int x;
	int y;

	i = -1;
	transparency_color = get_texture_color(&vars->sprites_text, 0, 0);
	while (++i < vars->nb_sprites)
	{
		vars->sprites[i].distance = distance_points(vars->sprites[i].position, vars->player.current_pos);
		vars->sprites[i].angle = calculate_sprite_angle(vars->sprites[i].position,
			vars->player.current_pos, vars->player.rotation_angle);
		if (sprite_is_visible(vars->sprites[i].angle))
		{
			sprite_height = vars->distance_to_projection_plane *
					(vars->cell_size / vars->sprites[i].distance);
			sprite_top_pixel = (vars->parsed_file.win_res.height / 2.0) - (sprite_height / 2.0);
			sprite_bottom_pixel = (vars->parsed_file.win_res.height / 2.0) + (sprite_height / 2.0);
			sprite_width = vars->distance_to_projection_plane / ((cos(vars->sprites[i].angle) * vars->sprites[i].distance));
			first_x_position = vars->distance_to_projection_plane * tan(vars->sprites[i].angle)
							   + (vars->parsed_file.win_res.width / 2.0) - (sprite_width / 2);
			sprite_width_end = sprite_height;
			x = - 1;
			while (++x < sprite_width_end)
			{
				if (vars->rays[(int)(first_x_position + x)].distance > vars->sprites[i].distance)
				{
					sprite_texture_offset.x = x * vars->sprites_text.width / sprite_height;
					y = sprite_top_pixel - 1;
					while (++y < sprite_bottom_pixel)
					{
						sprite_texture_offset.y = get_texture_offset_y(y, sprite_height, vars->parsed_file.win_res.height,vars->sprites_text.height);
						color = get_texture_color(&vars->sprites_text,
							sprite_texture_offset.x,
							sprite_texture_offset.y);
						if (color != transparency_color)
							my_mlx_pixel_put(&vars->view,
					   			first_x_position + x, y, color);
					}
				}
			}
		}
	}
}

void sprites_sort();