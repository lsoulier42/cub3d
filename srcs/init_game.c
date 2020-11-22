/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_vars.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: louise <lsoulier@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/05 18:27:36 by louise            #+#    #+#             */
/*   Updated: 2020/11/22 01:20:11 by user42           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"
#include "parsing.h"

int init_game(t_mlx_vars *vars, char *first_arg, int save_opt)
{
	t_game_file	*parsed_file;

	parsed_file = load_config_file(first_arg);
	if (!parsed_file)
	{
		error_msg(PARSING_ERROR);
		return (0);
	}
	else
	{
		if (create_game_struct(&vars, parsed_file, save_opt))
			event_mngt(vars);
		if (vars)
			free_game_struct(vars);
		free_parsed_file(parsed_file);
	}
	return (1);
}

int create_game_struct(t_mlx_vars **vars, t_game_file *parsed_file, int save_opt)
{
	*vars = create_vars_struct(parsed_file);
	if (!(*vars))
	{
		error_msg(STRUCT_ERROR);
		return (0);
	}
	(*vars)->save = save_opt;
	if (create_window(*vars) != 1)
		return (0);
	if (create_images(*vars) != 1)
	{
		error_msg(IMAGE_ERROR);
		return (0);
	}
	if (init_texture_files(*vars) != 1)
	{
		error_msg(TEXTURE_ERROR);
		return (0);
	}
	return (1);
}

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
	t_dimension *win_res;
	int 		screen_width;
	int 		screen_height;

	win_res = &vars->parsed_file->win_res;
	vars->mlx = mlx_init();
	if (vars->mlx == NULL)
	{
		error_msg(MLX_INIT_ERROR);
		return (0);
	}
	mlx_get_screen_size(vars->mlx, &screen_width, &screen_height);
	if (screen_width < win_res->width)
		set_dimension(win_res, screen_width, win_res->height);
	if (screen_height < win_res->height)
		set_dimension(win_res, win_res->width, screen_height);
	vars->win = mlx_new_window(vars->mlx,
		win_res->width, win_res->height, "Cub3d");
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
	vars->minimap = (t_image_data*)malloc(sizeof(t_image_data));
	if (!vars->view || !vars->minimap)
	{
		error_msg_alloc(IMAGE_ALLOC_ERROR);
		return (0);
	}
	my_mlx_new_image(vars->mlx, vars->view, win_res.width, win_res.height);
	my_mlx_new_image(vars->mlx, vars->minimap,
	map_res.width * vars->cell_size,
	map_res.height * vars->cell_size);
	if (!vars->view->img || !vars->view->addr
		||!vars->minimap->img || !vars->minimap->addr)
	{
		error_msg(IMAGE_CREATION_ERROR);
		return (0);
	}
	return (1);
}
