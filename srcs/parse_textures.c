/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing_textures.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lsoulier <lsoulier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/22 13:34:44 by lsoulier          #+#    #+#             */
/*   Updated: 2020/11/28 13:25:11 by user42           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parsing.h"

int	already_set_text(t_game_file *parsed_file, char **values)
{
	if ((ft_strcmp(values[0], "NO") == 0 && parsed_file->no_text != NULL)
		|| (ft_strcmp(values[0], "SO") == 0 && parsed_file->so_text != NULL)
		|| (ft_strcmp(values[0], "WE") == 0 && parsed_file->we_text != NULL)
		|| (ft_strcmp(values[0], "EA") == 0 && parsed_file->ea_text != NULL)
		|| (ft_strcmp(values[0], "S") == 0
			&& parsed_file->sprite_text != NULL))
		return (1);
	return (0);
}

int	set_texture_path(t_game_file *parsed_file, char **values)
{
	char *text_path;

	text_path = ft_strdup(values[1]);
	if (!text_path)
	{
		error_msg(ALLOCATION_ERROR);
		return (0);
	}
	if (ft_strcmp(values[0], "NO") == 0)
		parsed_file->no_text = text_path;
	else if (ft_strcmp(values[0], "SO") == 0)
		parsed_file->so_text = text_path;
	else if (ft_strcmp(values[0], "WE") == 0)
		parsed_file->we_text = text_path;
	else if (ft_strcmp(values[0], "EA") == 0)
		parsed_file->ea_text = text_path;
	else if (ft_strcmp(values[0], "S") == 0)
		parsed_file->sprite_text = text_path;
	else
	{
		error_msg_parsing(-1);
		return (0);
	}
	return (1);
}

int	parse_textures(t_game_file *parsed_file, char **values)
{
	if (nb_tab_values(values) != 2)
	{
		error_msg_parsing(TEXTURE_NOT_FOUND);
		return (0);
	}
	if (!check_filepath_text(values[1]))
	{
		error_msg_parsing(TEXTURE_NOT_FOUND);
		error_msg_texture(values[1]);
		return (0);
	}
	if (already_set_text(parsed_file, values))
	{
		error_msg_parsing(TEXTURE_ALREADY_SET_ERROR);
		return (0);
	}
	if (!set_texture_path(parsed_file, values))
		return (0);
	return (1);
}

int	check_filepath_text(char *filepath)
{
	int fd;

	if (!filepath)
		return (0);
	fd = open(filepath, O_RDONLY);
	if (fd == -1)
		return (0);
	close(fd);
	return (1);
}
