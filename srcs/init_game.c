/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_vars.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: louise <lsoulier@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/05 18:27:36 by louise            #+#    #+#             */
/*   Updated: 2020/11/14 20:08:10 by user42           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"
#include "libft.h"

t_mlx_vars	*create_vars_struct(t_game_file *parsed_file)
{
	t_mlx_vars		*vars;

	vars = (t_mlx_vars*)malloc(sizeof(t_mlx_vars));
	if (!vars)
	{
		error_msg_alloc(VARS_ALLOC_ERROR);
		return (NULL);
	}
	vars->parsed_file = parsed_file;
	vars->cell_size = 16;
	vars->player = init_player(parsed_file, vars->cell_size);
	if (vars->player == NULL)
	{
		error_msg_alloc(PLAYER_ALLOC_ERROR);
		return (NULL);
	}
	vars->rays = (t_ray*)malloc(sizeof(t_ray) * parsed_file->win_res.width);
	if (vars->rays == NULL)
	{
		error_msg_alloc(RAYS_ALLOC_ERROR);
		return (0);
	}
	return (vars);
}

int			create_window(t_mlx_vars *vars)
{
	t_dimension win_res;

	win_res = vars->parsed_file->win_res;
	vars->mlx = mlx_init();
	if (vars->mlx == NULL)
	{
		error_msg(MLX_INIT_ERROR);
		return (0);
	}
	vars->win = mlx_new_window(vars->mlx,
		win_res.width, win_res.height, "Cub3d");
	if (vars->win == NULL)
	{
		error_msg(MLX_WINDOW_ERROR);
		return (0);
	}
	return (1);
}

int 		create_images(t_mlx_vars *vars)
{
	t_dimension	win_res;
	t_dimension map_res;

	win_res = vars->parsed_file->win_res;
	map_res = vars->parsed_file->map_res;
	vars->view = (t_image_data*)malloc(sizeof(t_image_data));
	if (!vars->view)
	{
		error_msg_alloc(IMAGE_ALLOC_ERROR);
		return (0);
	}
	my_mlx_new_image(vars->mlx, vars->view, win_res.width, win_res.height);
	vars->minimap = (t_image_data*)malloc(sizeof(t_image_data));
	if (!vars->minimap)
	{
		error_msg_alloc(IMAGE_ALLOC_ERROR);
		return (0);
	}
	my_mlx_new_image(vars->mlx, vars->minimap,
		map_res.width * vars->cell_size,
		map_res.height * vars->cell_size);
	return (1);
}

double		set_rotation_angle(char card)
{
	double angle;

	if (card == 'S')
		angle = M_PI / 2;
	else if (card == 'N')
		angle = (3 * M_PI) / 2;
	else if (card == 'E')
		angle = 0;
	else
		angle = M_PI;
	return (angle);
}

t_player	*init_player(t_game_file *parsed_file, int cell_size)
{
	t_player	*player;
	t_point		start;
	char		card;

	player = (t_player*)malloc(sizeof(t_player));
	if (!player)
	{
		error_msg_alloc(PLAYER_ALLOC_ERROR);
		return (NULL);
	}
	start = parsed_file->player_start;
	card = parsed_file->player_start_card;
	set_point(&player->current_pos, start.x * cell_size, start.y * cell_size);
	player->size = cell_size / 4;
	player->turn_direction = 0;
	player->walk_direction = 0;
	player->rotation_angle = set_rotation_angle(card);
	player->move_speed = 3.0;
	player->rotation_speed = (3.0 * M_PI) / 180;
	player->direction_angle = 0;
	return (player);
}
