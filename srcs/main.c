/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: louise <lsoulier@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/18 14:36:08 by louise            #+#    #+#             */
/*   Updated: 2020/11/08 18:43:45 by louise           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"
#include "libft.h"

int	exit_hook(t_mlx_vars *vars)
{
	mlx_destroy_window(vars->mlx, vars->win);
	return (1);
}

int main(int argc, char **argv)
{
	t_game			*parsed_map;
	t_file			cubmap;
	t_mlx_vars		vars;
	t_point			start;
	t_point			end;

	set_point(&start, 50, 50);
	set_point(&end, 70, 20);
	if (argc >= 2 && argc <= 3)
	{
		if (!(open_game_file(&cubmap, argv[1])))
			return (0);
		if (ft_strncmp("cub", cubmap.ext, 3) != 0)
			return (destroy_file(cubmap));
		if (!(parsed_map = parse_file(cubmap)))
			return (destroy_file(cubmap));
		init_vars(&vars, parsed_map);
		draw_line(&vars, start, end, color_trgb(RED));
		//draw_angle(&vars, start, 40);
		//init_game(&vars);
		//mlx_key_hook(vars.win, &player_move, &vars);
		mlx_loop(vars.mlx);
		close_game_files(cubmap, parsed_map);
	}
	return (0);
}