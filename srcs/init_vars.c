/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_vars.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: louise <lsoulier@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/05 18:27:36 by louise            #+#    #+#             */
/*   Updated: 2020/11/07 11:24:07 by louise           ###   ########.fr       */
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
	vars->current_card = parsed_map->player_start_card;
	vars->current_pos = parsed_map->player_start;
	init_player_sprites(vars);

}

void	init_game(t_mlx_vars *vars)
{
	print_map(vars, vars->map);
	print_player(vars, vars->current_pos);
	vars->wall_touched = print_ray(vars, vars->current_pos);
}

void	init_player_sprites(t_mlx_vars *vars)
{
	t_dimension up;
	t_dimension down;
	t_dimension west;
	t_dimension est;

	vars->player_up.img = mlx_xpm_file_to_image(vars->mlx, "./img/player_up.xpm", &up.width, &up.height);
	vars->player_down.img = mlx_xpm_file_to_image(vars->mlx, "./img/player_down.xpm", &down.width, &down.height);
	vars->player_west.img = mlx_xpm_file_to_image(vars->mlx, "./img/player_west.xpm", &west.width, &west.height);
	vars->player_est.img = mlx_xpm_file_to_image(vars->mlx, "./img/player_est.xpm", &est.width, &est.height);
	change_player_img(vars);
}

void change_player_img(t_mlx_vars *vars)
{
	if (vars->current_card == 'N')
		vars->player_img = vars->player_up;
	else if (vars->current_card == 'S')
		vars->player_img = vars->player_down;
	else if (vars->current_card == 'W')
		vars->player_img = vars->player_west;
	else if (vars->current_card == 'E')
		vars->player_img = vars->player_est;
}
