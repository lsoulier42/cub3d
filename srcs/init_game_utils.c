/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_game_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lsoulier <lsoulier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/15 21:12:16 by lsoulier          #+#    #+#             */
/*   Updated: 2020/11/22 01:21:31 by user42           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "cub3d.h"

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
	player->move_speed = parsed_file->win_res.width * 4.0 / FOUR_K_RES_WIDTH;
	player->rotation_speed = (player->move_speed * M_PI) / 180;
	player->direction_angle = 0;
	return (player);
}

int 		check_filepath_text(char *filepath)
{
	int fd;

	fd = open(filepath, O_RDONLY);
	if (fd == -1)
		return (0);
	close(fd);
	return (1);
}

t_texture_data *load_texture(t_mlx_vars *vars, char *filepath, int default_color)
{
	t_texture_data *new_texture;

	new_texture = (t_texture_data*)ft_calloc(1, sizeof(t_texture_data));
	if (!new_texture)
	{
		error_msg_alloc(TEXTURE_ALLOC_ERROR);
		return (NULL);
	}
	if (filepath && check_filepath_text(filepath))
	{
		new_texture->img = mlx_xpm_file_to_image(vars->mlx, filepath,
												 &new_texture->width, &new_texture->height);
		if (!new_texture->img)
		{
			error_msg_texture(filepath);
			return (NULL);
		}
		new_texture->addr = mlx_get_data_addr(new_texture->img,
											  &new_texture->bits_per_pixel, &new_texture->line_length,
											  &new_texture->endian);
		if (!new_texture->addr)
		{
			error_msg(TEXTURE_ADDR_ERROR);
			return (NULL);
		}
	}
	else
		new_texture->default_color = color_trgb(default_color);
	return (new_texture);
}

int 		init_texture_files(t_mlx_vars *vars)
{
	vars->south_text = load_texture(vars, vars->parsed_file->so_text, WHITE);
	vars->north_text = load_texture(vars, vars->parsed_file->no_text, GRAY);
	vars->west_text = load_texture(vars, vars->parsed_file->we_text, BLACK);
	vars->east_text = load_texture(vars, vars->parsed_file->ea_text, BLUE);
	if (!vars->south_text || !vars->north_text || !vars->west_text || !vars->east_text)
		return (0);
	return (1);
}