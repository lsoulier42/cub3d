/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pixel.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: louise <lsoulier@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/02 17:51:12 by louise            #+#    #+#             */
/*   Updated: 2020/11/10 00:16:12 by louise           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"
#include "libft.h"

int key_press_hook(int keycode, t_mlx_vars *vars)
{
	t_player	*player;
	t_point		*position;

	player = &vars->player;
	position = &player->current_pos;
	if (keycode == ARROW_UP)
		player->walk_direction = FORWARD;
	else if (keycode == ARROW_DOWN)
		player->walk_direction = BACKWARD;
	else if (keycode == ARROW_LEFT)
		player->turn_direction = ROT_LEFT;
	else if (keycode == ARROW_RIGHT)
		player->turn_direction = ROT_RIGHT;
	else if (keycode == ESCAPE)
		exit_game(vars);
	return (1);
}

int key_release_hook(int keycode, t_mlx_vars *vars)
{
	t_player	*player;

	player = &vars->player;
	if (keycode == ARROW_UP)
		player->walk_direction = 0;
	else if (keycode == ARROW_DOWN)
		player->walk_direction = 0;
	else if (keycode == ARROW_LEFT)
		player->turn_direction = 0;
	else if (keycode == ARROW_RIGHT)
		player->turn_direction = 0;
	return (1);
}

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

int update_hook(t_mlx_vars *vars)
{
	t_player	*player;
	t_point		*current_pos;
	int 		move_step;

	player = &vars->player;
	current_pos = &player->current_pos;
	player->rotation_angle += player->turn_direction * player->rotation_speed;
	move_step = player->walk_direction * player->move_speed;
	current_pos->x += cos(player->rotation_angle) * move_step;
	current_pos->y += sin(player->rotation_angle) * move_step;
	mlx_put_image_to_window(vars->mlx, vars->win, vars->map_img.img, 0, 0);
	print_player(vars, vars->player);
	return (1);
}