/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing_textures.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lsoulier <lsoulier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/22 13:34:44 by lsoulier          #+#    #+#             */
/*   Updated: 2020/11/27 21:01:38 by user42           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parsing.h"

int	parse_textures(t_game_file *parsed_file, char *line)
{
	if (ft_strchr(CARD_CHARSET, *line) != NULL)
	{
		if (ft_strlen(line) > 1 && ((line[0] != 'S' && line[1] == ' ')
			|| (line[0] == 'S' && (line[1] != ' ' && line[1] != 'O'))))
		{
			error_msg_parsing(SETTING_INVALID);
			return (0);
		}
	}
	if (ft_strnstr(line, "NO ", 3) != NULL)
	{
		if (parsed_file->no_text != NULL)
		{
			error_msg_parsing(TEXTURE_ALREADY_SET_ERROR);
			return (0);
		}
		if (!set_texture_path(line, &parsed_file->no_text))
			return (0);
	}
	if (ft_strnstr(line, "SO ", 3) != NULL)
	{
		if (parsed_file->so_text != NULL)
		{
			error_msg_parsing(TEXTURE_ALREADY_SET_ERROR);
			return (0);
		}
		if (!set_texture_path(line, &parsed_file->so_text))
			return (0);
	}
	if (ft_strnstr(line, "WE ", 3) != NULL)
	{
		if (parsed_file->we_text != NULL)
		{
			error_msg_parsing(TEXTURE_ALREADY_SET_ERROR);
			return (0);
		}
		if (!set_texture_path(line, &parsed_file->we_text))
			return (0);
	}
	if (ft_strnstr(line, "EA ", 3) != NULL)
	{
		if(parsed_file->ea_text != NULL)
		{
			error_msg_parsing(TEXTURE_ALREADY_SET_ERROR);
			return (0);
		}
		if (!set_texture_path(line, &parsed_file->ea_text))
			return (0);
	}
	if (ft_strnstr(line, "S ", 2) != NULL)
	{
		if (parsed_file->sprite_text != NULL)
		{
			error_msg_parsing(TEXTURE_ALREADY_SET_ERROR);
			return (0);
		}
		if (!set_texture_path(line, &parsed_file->sprite_text))
			return (0);
	}
	return (1);
}

int	set_texture_path(char *line, char **text_path)
{
	while (ft_isalpha(*line))
		line++;
	*text_path = ft_strtrim(line, " ");
	if (!(*text_path))
	{
		error_msg(ALLOCATION_ERROR);
		return (0);
	}
	if (!check_filepath_text(*text_path))
	{
		error_msg_parsing(TEXTURE_NOT_FOUND);
		error_msg_texture(*text_path);
		free(*text_path);
		*text_path = NULL;
		return (0);
	}
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
