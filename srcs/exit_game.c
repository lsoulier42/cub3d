/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_mlx.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lsoulier <lsoulier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/14 01:36:40 by lsoulier          #+#    #+#             */
/*   Updated: 2020/11/28 22:08:06 by user42           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"
#include "parsing.h"

void	free_parsed_file(t_game_file parsed_file)
{
	if (parsed_file.map)
		free_twod_array(parsed_file.map);
	if (parsed_file.no_text)
		free(parsed_file.no_text);
	if (parsed_file.so_text)
		free(parsed_file.so_text);
	if (parsed_file.we_text)
		free(parsed_file.we_text);
	if (parsed_file.ea_text)
		free(parsed_file.ea_text);
	if (parsed_file.sprite_text)
		free(parsed_file.sprite_text);
}

void	free_mlx_struct(t_mlx_vars *vars)
{
	if (vars->view.img)
		mlx_destroy_image(vars->mlx, vars->view.img);
	if (vars->south_text.img)
		mlx_destroy_image(vars->mlx, vars->south_text.img);
	if (vars->north_text.img)
		mlx_destroy_image(vars->mlx, vars->north_text.img);
	if (vars->west_text.img)
		mlx_destroy_image(vars->mlx, vars->west_text.img);
	if (vars->east_text.img)
		mlx_destroy_image(vars->mlx, vars->east_text.img);
	if (vars->sprites_text.img)
		mlx_destroy_image(vars->mlx, vars->sprites_text.img);
}

int		exit_game(t_mlx_vars *vars)
{
	free_mlx_struct(vars);
	if (vars->win)
		mlx_destroy_window(vars->mlx, vars->win);
	if (vars->mlx)
	{
		mlx_destroy_display(vars->mlx);
		free(vars->mlx);
	}
	if (vars->sprites)
		free(vars->sprites);
	if (vars->rays)
		free(vars->rays);
	free_parsed_file(vars->parsed_file);
	return (1);
}
