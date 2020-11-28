/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_game_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lsoulier <lsoulier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/28 23:40:34 by lsoulier          #+#    #+#             */
/*   Updated: 2020/11/29 00:22:49 by user42           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"
#include "parsing.h"

void	init_player(t_player *player, t_game_file parsed_file)
{
	t_point		start;
	char		card;
	float		angle;

	start = parsed_file.player_start;
	card = parsed_file.player_start_card;
	set_point(&player->current_pos, start.x + 0.5,
		start.y + 0.5);
	player->turn_direction = 0;
	player->walk_direction = 0;
	if (card == 'S')
		angle = M_PI / 2.0;
	else if (card == 'N')
		angle = (3.0 * M_PI) / 2.0;
	else if (card == 'E')
		angle = 0;
	else
		angle = M_PI;
	player->rotation_angle = angle;
	player->move_speed = parsed_file.win_res.width
		* MY_INCREMENT_SPEED / MY_SCREEN_WIDTH;
	player->rotation_speed = ((parsed_file.win_res.width
		* MY_INCREMENT_ROTATION / MY_SCREEN_WIDTH) * M_PI) / 180;
	player->direction_angle = 0;
}

int		create_mlx_ptr(t_mlx_vars *vars)
{
	vars->mlx = mlx_init();
	if (!vars->mlx)
	{
		error_msg(MLX_INIT_ERROR);
		return (0);
	}
	return (1);
}

int		create_game_struct_suite(t_mlx_vars *vars)
{
	vars->rays = (t_ray*)malloc(sizeof(t_ray)
		* vars->parsed_file.win_res.width);
	if (!vars->rays)
	{
		error_msg(ALLOCATION_ERROR);
		return (0);
	}
	if (!init_sprites(vars))
		return (0);
	init_player(&vars->player, vars->parsed_file);
	return (1);
}

int		load_texture(t_mlx_vars *vars, t_texture_data *text, char *filepath)
{
	if (!check_extension_file(filepath, ".xpm"))
	{
		error_msg(TEXTURE_ERROR);
		error_msg_texture(filepath);
		return (0);
	}
	text->img = mlx_xpm_file_to_image(vars->mlx,
		filepath, &text->width, &text->height);
	if (!text->img)
	{
		error_msg(TEXTURE_ERROR);
		error_msg_texture(filepath);
		return (0);
	}
	text->addr = mlx_get_data_addr(text->img,
		&text->bits_per_pixel, &text->line_length, &text->endian);
	return (1);
}
