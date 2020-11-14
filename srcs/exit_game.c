/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_mlx.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lsoulier <lsoulier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/14 01:36:40 by lsoulier          #+#    #+#             */
/*   Updated: 2020/11/14 02:52:23 by user42           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "cub3d.h"

void	free_parsed_file(t_game_file *parsed_file)
{
	int i;

	i = -1;
	while (parsed_file->map[++i])
		free(parsed_file->map[i]);
	free(parsed_file->map);
	free(parsed_file->no_text);
	free(parsed_file->so_text);
	free(parsed_file->we_text);
	free(parsed_file->ea_text);
	free(parsed_file->sprite_text);
	free(parsed_file);
}

void	free_game_struct(t_mlx_vars *vars)
{
	if (vars->player)
		free(vars->player);
	free(vars);
}

int		exit_game(t_mlx_vars *vars)
{
	mlx_destroy_window(vars->mlx, vars->win);
	exit(0);
	return (1);
}
