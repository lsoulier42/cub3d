/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pixel.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: louise <lsoulier@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/02 17:51:12 by louise            #+#    #+#             */
/*   Updated: 2020/11/10 02:40:15 by louise           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"
#include "libft.h"

void print_player(t_mlx_vars *vars, t_player player)
{
	t_image_data player_img;
	t_point	direction;

	direction.x = player.current_pos.x + cos(player.rotation_angle) * (player.size / 2);
	direction.y = player.current_pos.y + sin(player.rotation_angle) * (player.size / 2);
	my_mlx_new_image(vars->mlx, &player_img, player.size, player.size);
	draw_circle(vars, player.current_pos, player.size / 2, color_trgb(RED));
	draw_line(vars, player.current_pos, direction, color_trgb(RED));
}

int is_wall(char **map, int x, int y, int tile_size)
{
	int index_x;
	int index_y;

	index_x = x / tile_size;
	index_y = y / tile_size;
	printf("x:%d, y:%d, %p", index_x, index_y, map);
	return (map[index_y][index_x] == '1');
}

int update_hook(t_mlx_vars *vars)
{
	int 		move_step;
	int 		next_x;
	int 		next_y;

	vars->player.rotation_angle += vars->player.turn_direction * vars->player.rotation_speed;
	move_step = vars->player.walk_direction * vars->player.move_speed;
	next_x = vars->player.current_pos.x + cos(vars->player.rotation_angle) * move_step;
	next_y = vars->player.current_pos.y + sin(vars->player.rotation_angle) * move_step;
	vars->player.current_pos.x = next_x;
	vars->player.current_pos.y = next_y;
	mlx_put_image_to_window(vars->mlx, vars->win, vars->map_img.img, 0, 0);
	print_player(vars, vars->player);
	return (1);
}