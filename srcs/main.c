/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: louise <lsoulier@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/18 14:36:08 by louise            #+#    #+#             */
/*   Updated: 2020/11/10 01:36:29 by louise           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"
#include "libft.h"

int exit_game(t_mlx_vars *vars)
{
	mlx_destroy_window(vars->mlx, vars->win);
	exit(0);
	return (1);
}

int error_msg(int error_type)
{
	if (error_type == EXT_ERROR)
		ft_putstr("Erreur d'extension du fichier\n");
	else if (error_type == PARSING_ERROR)
		ft_putstr("Erreur pendant le parsing de la map\n");
	else if (error_type == FILE_ERROR)
		ft_putstr("Erreur d'ouverture du fichier\n");
	else if (error_type == ARG_ERROR)
		ft_putstr("Nombre d'arguments invalides\n");
	else
		ft_putstr("Erreur inconnue\n");
	return (1);
}

int main(int argc, char **argv)
{
	t_game		*parsed_map;
	t_mlx_vars	vars;
	int 		error_occured;

	error_occured = 0;
	if (argc >= 2 && argc <= 3)
	{
		parsed_map = parse_file(argv[1]);
		if (!parsed_map)
			error_occured = error_msg(PARSING_ERROR);
		if (!error_occured)
		{
			init_vars(&vars, parsed_map);
			mlx_hook(vars.win, 2, 1L << 0, &key_press_hook, &vars);
			mlx_hook(vars.win, 3, 1L<<1, &key_release_hook, &vars);
			mlx_hook(vars.win, 17, 1L<<17, exit_game, &vars);
			mlx_loop_hook(vars.mlx, &update_hook, &vars);
			mlx_loop(vars.mlx);
			close_game_files(parsed_map);
		}
	}
	else
		error_occured = error_msg(ARG_ERROR);
	return (0);
}