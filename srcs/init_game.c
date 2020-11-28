/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_vars.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: louise <lsoulier@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/05 18:27:36 by louise            #+#    #+#             */
/*   Updated: 2020/11/28 23:33:08 by user42           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int		create_game_struct(t_mlx_vars *vars, int save_opt)
{
	vars->distance_to_projection_plane = (vars->parsed_file.win_res.width / 2)
		/ tan(degree_to_radian(FOV_ANGLE / 2));
	vars->rays = NULL;
	vars->sprites = NULL;
	vars->mlx = NULL;
	vars->win = NULL;
	if (!create_game_struct_suite(vars))
		return (0);
	if (!create_mlx_ptr(vars))
		return (0);
	if (!create_images(vars))
		return (0);
	if (save_opt)
	{
		render_one_frame(vars);
		return (0);
	}
	if (!create_window(vars))
		return (0);
	return (1);
}

int		create_window(t_mlx_vars *vars)
{
	t_dimension *win_res;
	int			screen_width;
	int			screen_height;

	win_res = &vars->parsed_file.win_res;
	mlx_get_screen_size(vars->mlx, &screen_width, &screen_height);
	if (screen_width < win_res->width)
		set_dimension(win_res, screen_width, win_res->height);
	if (screen_height < win_res->height)
		set_dimension(win_res, win_res->width, screen_height);
	vars->win = mlx_new_window(vars->mlx,
		win_res->width, win_res->height, PROJECT_NAME);
	if (!vars->win)
	{
		error_msg(MLX_WINDOW_ERROR);
		return (0);
	}
	return (1);
}

int		create_images(t_mlx_vars *vars)
{
	t_dimension	win_res;

	vars->view.img = NULL;
	vars->south_text.img = NULL;
	vars->north_text.img = NULL;
	vars->west_text.img = NULL;
	vars->east_text.img = NULL;
	vars->sprites_text.img = NULL;
	win_res = vars->parsed_file.win_res;
	if (!my_mlx_new_image(vars->mlx, &vars->view,
		win_res.width, win_res.height))
		return (0);
	if (!load_texture(vars, &vars->south_text, vars->parsed_file.so_text)
		|| !load_texture(vars, &vars->north_text, vars->parsed_file.no_text)
		|| !load_texture(vars, &vars->west_text, vars->parsed_file.we_text)
		|| !load_texture(vars, &vars->east_text, vars->parsed_file.ea_text)
		|| !load_texture(vars, &vars->sprites_text,
			vars->parsed_file.sprite_text))
		return (0);
	return (1);
}
