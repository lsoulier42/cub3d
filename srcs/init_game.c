/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_vars.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: louise <lsoulier@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/05 18:27:36 by louise            #+#    #+#             */
/*   Updated: 2020/11/27 02:54:06 by user42           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int		create_game_struct(t_mlx_vars *vars, int save_opt)
{
	if (vars->parsed_file.win_res.width > 320)
		vars->cell_size = 16;
	else
		vars->cell_size = 5;
	vars->distance_to_projection_plane = (vars->parsed_file.win_res.width / 2)
		/ tan(degree_to_radian(FOV_ANGLE / 2));
	vars->rays = (t_ray*)malloc(sizeof(t_ray)
		* vars->parsed_file.win_res.width);
	if (!vars->rays)
	{
		error_msg(ALLOCATION_ERROR);
		return (0);
	}
	if (!init_sprites(vars))
		return (0);
	init_player(&vars->player, vars->parsed_file, vars->cell_size);
	vars->save = save_opt;
	if (!create_window(vars))
		return (0);
	if (!create_images(vars))
		return (0);
	return (1);
}

void	init_player(t_player *player, t_game_file parsed_file, int cell_size)
{
	t_point		start;
	char		card;
	double		angle;

	start = parsed_file.player_start;
	card = parsed_file.player_start_card;
	set_point(&player->current_pos, (start.x * cell_size) + cell_size / 2,
		(start.y * cell_size) + cell_size / 2);
	player->turn_direction = 0;
	player->walk_direction = 0;
	if (card == 'S')
		angle = M_PI / 2;
	else if (card == 'N')
		angle = (3 * M_PI) / 2;
	else if (card == 'E')
		angle = 0;
	else
		angle = M_PI;
	player->rotation_angle = angle;
	player->move_speed = parsed_file.win_res.width * 4.0 / FOUR_K_RES_WIDTH;
	player->move_speed *= cell_size / 16.0;
	player->rotation_speed = (player->move_speed * M_PI) / 180;
	player->direction_angle = 0;
}

int		create_window(t_mlx_vars *vars)
{
	t_dimension *win_res;
	int			screen_width;
	int			screen_height;

	win_res = &vars->parsed_file.win_res;
	vars->mlx = mlx_init();
	if (!vars->mlx)
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
	t_dimension map_res;

	win_res = vars->parsed_file.win_res;
	map_res = vars->parsed_file.map_res;
	if (!my_mlx_new_image(vars->mlx, &vars->view,
		win_res.width, win_res.height)
		|| !my_mlx_new_image(vars->mlx, &vars->minimap,
		map_res.width * vars->cell_size,
		map_res.height * vars->cell_size))
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
