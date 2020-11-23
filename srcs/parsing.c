/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_file.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: louise <lsoulier@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/18 19:25:00 by louise            #+#    #+#             */
/*   Updated: 2020/11/23 02:26:49 by user42           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parsing.h"

void 	init_parsed_file(t_game_file *parsed_file)
{
	parsed_file->map = NULL;
	parsed_file->player_start_card = 0;
	set_point(&(parsed_file->player_start), 0, 0);
	set_dimension(&(parsed_file->map_res), 0, 0);
	set_dimension(&(parsed_file->win_res), 0, 0);
	parsed_file->no_text = NULL;
	parsed_file->so_text = NULL;
	parsed_file->we_text = NULL;
	parsed_file->ea_text = NULL;
	parsed_file->sprite_text = NULL;
	parsed_file->floor_color = -1;
	parsed_file->ceiling_color = -1;
	parsed_file->settings_complete = 0;
}

int 		parse_map_loop(t_game_file *parsed_file, int fd)
{
	char	*next_line;
	int		error_occurred;

	next_line = trim_white_lines(fd);
	error_occurred = 0;
	if (next_line && ft_strchr(SETTINGS_CHARSET, *next_line) != NULL)
	{
		error_msg_parsing(SETTINGS_ALREADY_COMPLETE);
		free(next_line);
		return (0);
	}
	if (!parse_map(parsed_file, &next_line, fd))
		error_occurred = 1;
	return (!error_occurred);
}

int			parse_config_file(t_game_file *parsed_file, int fd)
{
	int no_error;

	if (parse_settings(parsed_file, fd))
	{
		if (parsed_file->settings_complete == 1)
			no_error = parse_map_loop(parsed_file, fd);
		else
		{
			no_error = 0;
			error_msg_parsing(MISSING_SETTINGS_ERROR);
		}
	}
	else
		no_error = 0;
	return (no_error);
}

int	load_config_file(t_game_file *parsed_file, char *path)
{
	int			fd;

	fd = check_cub_file(path);
	if (fd < 0)
		return (0);
	init_parsed_file(parsed_file);
	if (!parse_config_file(parsed_file, fd))
	{
		free_parsed_file(*parsed_file);
		return (0);
	}
	return (1);
}
