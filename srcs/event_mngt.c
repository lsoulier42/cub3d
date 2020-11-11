/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   event_mngt.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: louise <lsoulier@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/10 01:57:58 by louise            #+#    #+#             */
/*   Updated: 2020/11/10 02:45:46 by louise           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "cub3d.h"

int key_press_hook(int keycode, t_mlx_vars *vars)
{
	t_player	*player;

	player = &vars->player;
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

void	event_mngt(t_mlx_vars *vars)
{
	mlx_hook(vars->win, 2, 1L <<0, &key_press_hook, vars);
	mlx_hook(vars->win, 3, 1L<<1, &key_release_hook, vars);
	mlx_hook(vars->win, 17, 1L<<17, exit_game, vars);
	mlx_loop_hook(vars->mlx, &update_hook, vars);
	mlx_loop(vars->mlx);
}
