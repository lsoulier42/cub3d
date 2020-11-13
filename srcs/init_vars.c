/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_vars.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: louise <lsoulier@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/05 18:27:36 by louise            #+#    #+#             */
/*   Updated: 2020/11/13 00:42:45 by user42           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"
#include "libft.h"

void	init_vars(t_mlx_vars *vars, t_game *parsed_map)
{
	vars->map = parsed_map->map;
	vars->mlx = mlx_init();
	vars->win_res = parsed_map->window_res;
	vars->map_res = parsed_map->map_res;
	vars->win = mlx_new_window(vars->mlx,
		vars->win_res.width, vars->win_res.height, "Cub3d");
	vars->tile_size = parsed_map->window_res.width
		/ parsed_map->map_res.width;
	my_mlx_new_image(vars->mlx, &vars->map_img,
		parsed_map->window_res.width * MINIMAP_SCALE,
		parsed_map->window_res.height * MINIMAP_SCALE);
	init_player(&vars->player, parsed_map->player_start,
		parsed_map->player_start_card, vars->tile_size);
}

void	init_player(t_player *player, t_point start, char card, int tile_size)
{
	double	rad_angle;

	set_point(&player->current_pos, start.x * tile_size, start.y * tile_size);
	player->size = tile_size / 2;
	player->turn_direction = 0;
	player->walk_direction = 0;
	if (card == 'S')
		rad_angle = M_PI / 2;
	else if (card == 'N')
		rad_angle = 3 * M_PI / 2;
	else if (card == 'E')
		rad_angle = 0;
	else
		rad_angle = M_PI;
	player->rotation_angle = rad_angle;
	player->move_speed = 2;
	player->rotation_speed = 2 * (M_PI / 180);
}
