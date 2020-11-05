/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_vars.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: louise <lsoulier@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/05 18:27:36 by louise            #+#    #+#             */
/*   Updated: 2020/11/05 18:34:47 by louise           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"
#include "libft.h"

void 	init_vars(t_mlx_vars *vars, t_game *parsed_map)
{
	vars->mlx = mlx_init();
	vars->win_res = parsed_map->window_res;
	vars->win = mlx_new_window(vars->mlx, vars->win_res.width, vars->win_res.height, "Cub3d");
	vars->map = parsed_map->map;
	vars->player_img.img = mlx_new_image(vars->mlx, WALL_SIZE, WALL_SIZE);
	vars->current_card = parsed_map->player_start_card;
	draw_square(&(vars->player_img), create_trgb(0, 255, 0, 0));
	vars->current_pos = parsed_map->player_start;
}

void	init_game(t_mlx_vars *vars)
{
	print_map(vars, vars->map);
	print_player(vars, vars->current_pos);
	vars->wall_touched = print_ray(vars, vars->current_pos);
}
