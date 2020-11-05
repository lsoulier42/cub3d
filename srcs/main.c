/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: louise <lsoulier@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/18 14:36:08 by louise            #+#    #+#             */
/*   Updated: 2020/11/05 17:21:46 by louise           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"
#include "libft.h"

int	exit_hook(t_mlx_vars *vars)
{
	mlx_destroy_window(vars->mlx, vars->win);
	return (1);
}

void debug_point(t_mlx_vars *vars, t_point point)
{
	char str[20];
	static int i = 0;

	ft_strcat(str, "point(");
	ft_strcat(str, ft_itoa(point.x));
	ft_strcat(str, ",");
	ft_strcat(str, ft_itoa(point.y));
	ft_strcat(str, ")");
	mlx_string_put(vars->mlx, vars->win, 10, 500 + i * 10, create_trgb(0, 255, 0, 0), str);
	i++;
}

int main(int argc, char **argv)
{
	t_game			*parsed_map;
	t_file			cubmap;
	t_mlx_vars		vars;

	if (argc >= 2 && argc <= 3)
	{
		if (!(open_game_file(&cubmap, argv[1])))
			return (0);
		if (ft_strncmp("cub", cubmap.ext, 3) != 0)
			return (destroy_file(cubmap));
		if (!(parsed_map = parse_file(cubmap)))
			return (destroy_file(cubmap));
		vars.mlx = mlx_init();
		vars.win_res = parsed_map->window_res;
		vars.win = mlx_new_window(vars.mlx, vars.win_res.width, vars.win_res.height, "Cub3d");
		vars.map = parsed_map->map;
		print_map(&vars, vars.map);
		vars.player_img.img = mlx_new_image(vars.mlx, WALL_SIZE, WALL_SIZE);
		vars.current_card = parsed_map->player_start_card;
		draw_square(&vars.player_img, create_trgb(0, 255, 0, 0));
		vars.current_pos = parsed_map->player_start;
		print_player(&vars, vars.current_pos);
		vars.wall_touched = print_ray(&vars, vars.current_pos);
		mlx_key_hook(vars.win, &player_move, &vars);
		mlx_loop(vars.mlx);
		close_game_files(cubmap, parsed_map);
	}
	return (0);
}