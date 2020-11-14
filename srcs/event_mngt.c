/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   event_mngt.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: louise <lsoulier@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/10 01:57:58 by louise            #+#    #+#             */
/*   Updated: 2020/11/14 03:53:57 by user42           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "cub3d.h"

int		key_press_hook(int keycode, t_mlx_vars *vars)
{
	if (keycode == ARROW_UP)
		vars->player->walk_direction = FORWARD;
	else if (keycode == ARROW_DOWN)
		vars->player->walk_direction = BACKWARD;
	else if (keycode == ARROW_LEFT)
		vars->player->turn_direction = ROT_LEFT;
	else if (keycode == ARROW_RIGHT)
		vars->player->turn_direction = ROT_RIGHT;
	else if (keycode == ESCAPE)
		exit_game(vars);
	return (1);
}

int		key_release_hook(int keycode, t_mlx_vars *vars)
{
	if (keycode == ARROW_UP)
		vars->player->walk_direction = 0;
	else if (keycode == ARROW_DOWN)
		vars->player->walk_direction = 0;
	else if (keycode == ARROW_LEFT)
		vars->player->turn_direction = 0;
	else if (keycode == ARROW_RIGHT)
		vars->player->turn_direction = 0;
	return (1);
}

int		update_hook(t_mlx_vars *vars)
{
	t_image_data	view;
	t_image_data	minimap;
	t_ray			*rays;
	t_dimension		win_res;

	win_res = vars->parsed_file->win_res;
	my_mlx_new_image(vars->mlx, &view, win_res.width, win_res.height);
	my_mlx_new_image(vars->mlx, &minimap,
		win_res.width * MINIMAP_SCALE, win_res.height * MINIMAP_SCALE);
	update_player_position(vars);
	rays = cast_all_rays(vars);
	if (rays == NULL)
	{
		error_msg_alloc(RAYS_ALLOC_ERROR);
		return (0);
	}
	render_wall(vars, &view, rays);
	render_minimap(vars, &minimap, rays);
	mlx_put_image_to_window(vars->mlx, vars->win, view.img, 0, 0);
	mlx_put_image_to_window(vars->mlx, vars->win, minimap.img, 0, 0);
	mlx_destroy_image(vars->mlx, view.img);
	mlx_destroy_image(vars->mlx, minimap.img);
	free(rays);
	return (1);
}

void	event_mngt(t_mlx_vars *vars)
{
	mlx_hook(vars->win, 2, 1L << 0, &key_press_hook, vars);
	mlx_hook(vars->win, 3, 1L << 1, &key_release_hook, vars);
	mlx_hook(vars->win, 17, 1L << 17, exit_game, vars);
	mlx_loop_hook(vars->mlx, &update_hook, vars);
	mlx_loop(vars->mlx);
}
