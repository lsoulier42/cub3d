/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_mlx.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lsoulier <lsoulier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/14 01:36:40 by lsoulier          #+#    #+#             */
/*   Updated: 2020/11/15 21:09:30 by user42           ###   ########.fr       */
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

void 	free_textures(t_mlx_vars *vars)
{
	if (vars->south_text)
	{
		mlx_destroy_image(vars->mlx, vars->south_text->img);
		free(vars->south_text);
	}
	if (vars->north_text)
	{
		mlx_destroy_image(vars->mlx, vars->north_text->img);
		free(vars->north_text);
	}
	if (vars->west_text)
	{
		mlx_destroy_image(vars->mlx, vars->west_text->img);
		free(vars->west_text);
	}
	if (vars->east_text)
	{
		mlx_destroy_image(vars->mlx, vars->east_text->img);
		free(vars->east_text);
	}
}

void	free_game_struct(t_mlx_vars *vars)
{
	if (vars->player)
		free(vars->player);
	if (vars->rays)
		free(vars->rays);
	if (vars->view)
	{
		mlx_destroy_image(vars->mlx, vars->view->img);
		free(vars->view);
	}
	if (vars->minimap)
	{
		mlx_destroy_image(vars->mlx, vars->minimap->img);
		free(vars->minimap);
	}
	free_textures(vars);
	free(vars);
}

int		exit_game(t_mlx_vars *vars)
{
	mlx_destroy_window(vars->mlx, vars->win);
	exit(0);
	return (1);
}
