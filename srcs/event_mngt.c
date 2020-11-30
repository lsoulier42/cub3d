/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   event_mngt.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: louise <lsoulier@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/10 01:57:58 by louise            #+#    #+#             */
/*   Updated: 2020/11/30 12:36:37 by user42           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int		key_press_hook(int keycode, t_mlx_vars *vars)
{
	t_player *player;

	player = &vars->player;
	if (keycode == ARROW_UP
		|| keycode == W_KEY || keycode == D_KEY)
		player->walk_direction = 1;
	else if (keycode == ARROW_DOWN
		|| keycode == S_KEY || keycode == A_KEY)
		player->walk_direction = -1;
	if (keycode == A_KEY || keycode == D_KEY)
		player->direction_angle = M_PI / 2;
	if (keycode == ARROW_RIGHT)
		player->turn_direction = 1;
	else if (keycode == ARROW_LEFT)
		player->turn_direction = -1;
	if (keycode == ESCAPE)
		mlx_loop_end(vars->mlx);
	return (1);
}

int		key_release_hook(int keycode, t_mlx_vars *vars)
{
	t_player *player;

	player = &vars->player;
	if (keycode == ARROW_UP || keycode == ARROW_DOWN
		|| keycode == W_KEY || keycode == S_KEY
		|| keycode == A_KEY || keycode == D_KEY)
		player->walk_direction = 0;
	if (keycode == A_KEY || keycode == D_KEY)
		player->direction_angle = 0;
	if (keycode == ARROW_LEFT || keycode == ARROW_RIGHT)
		player->turn_direction = 0;
	return (1);
}

int		update_hook(t_mlx_vars *vars)
{
	update_player_position(vars, &vars->player);
	cast_all_rays(vars);
	render_background(vars);
	render_wall(vars);
	process_sprites(vars);
	mlx_put_image_to_window(vars->mlx, vars->win, vars->view.img, 0, 0);
	return (1);
}

void	event_mngt(t_mlx_vars *vars)
{
	mlx_hook(vars->win, 33, 1L << 17, &mlx_loop_end, vars->mlx);
	mlx_hook(vars->win, 2, 1L << 0, &key_press_hook, vars);
	mlx_hook(vars->win, 3, 1L << 1, &key_release_hook, vars);
	mlx_loop_hook(vars->mlx, &update_hook, vars);
	mlx_loop(vars->mlx);
}
