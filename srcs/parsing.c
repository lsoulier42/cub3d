/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_file.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: louise <lsoulier@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/18 19:25:00 by louise            #+#    #+#             */
/*   Updated: 2020/11/22 13:51:59 by user42           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parsing.h"

t_game_file	*init_parsed_file(void)
{
	t_game_file	*parsed_file;

	parsed_file = (t_game_file*)malloc(sizeof(t_game_file));
	if (!parsed_file)
	{
		error_msg_alloc(PARSED_FILE_ALLOC_ERROR);
		return (NULL);
	}
	parsed_file->map = NULL;
	parsed_file->player_start_card = 0;
	set_point(&(parsed_file->player_start), 0, 0);
	set_dimension(&(parsed_file->map_res), 0, 0);
	set_dimension(&(parsed_file->win_res), 800, 600);
	parsed_file->no_text = NULL;
	parsed_file->so_text = NULL;
	parsed_file->we_text = NULL;
	parsed_file->ea_text = NULL;
	parsed_file->sprite_text = NULL;
	parsed_file->floor_color = -1;
	parsed_file->ceiling_color = -1;
	return (parsed_file);
}

int			parse_config_file(t_game_file *parsed_file, int fd)
{
	char	*line;
	int 	ret_gnl;

	ret_gnl = 1;
	line = NULL;
	while (ret_gnl)
	{
		ret_gnl = get_next_line(fd, &line);
		if (ft_strchr(CONFIG_CHARSET, *line) != NULL)
		{
			if (!parse_settings(parsed_file, line))
				return (0);
		}
		else if (*line && *line != '\n')
			if (!parse_map(parsed_file, &line, fd))
				return (0);
	}
	return (1);
}

t_game_file		*load_config_file(char *path)
{
	t_game_file	*parsed_file;
	int			fd;

	fd = check_cub_file(path);
	parsed_file = init_parsed_file();
	if (fd < 0 || !parsed_file)
		return (NULL);
	if (!parse_config_file(parsed_file, fd))
	{
		free_parsed_file(parsed_file);
		return (NULL);
	}
	if(!check_background(parsed_file->floor_color, parsed_file->ceiling_color))
	{
		error_msg_parsing(BACKGROUND_COLOR_ERROR);
		return (0);
	}
	return (parsed_file);
}
