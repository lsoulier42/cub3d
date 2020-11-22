/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing_textures.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lsoulier <lsoulier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/22 13:34:44 by lsoulier          #+#    #+#             */
/*   Updated: 2020/11/22 14:14:22 by user42           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parsing.h"

int	parse_textures(t_game_file *parsed_file, char *line)
{
	if (ft_strnstr(line, "NO ", 3) != NULL)
		if (!set_texture_path(line, &parsed_file->no_text))
			return (0);
	if (ft_strnstr(line, "SO ", 3) != NULL)
		if (!set_texture_path(line, &parsed_file->so_text))
			return (0);
	if (ft_strnstr(line, "WE ", 3) != NULL)
		if (!set_texture_path(line, &parsed_file->we_text))
			return (0);
	if (ft_strnstr(line, "EA ", 3) != NULL)
		if (!set_texture_path(line, &parsed_file->ea_text))
			return (0);
	if (ft_strnstr(line, "S ", 2) != NULL)
		if (!set_texture_path(line, &parsed_file->sprite_text))
			return (0);
	return (1);
}

int	set_texture_path(char *line, char **text_path)
{
	while (ft_isalpha(*line))
		line++;
	*text_path = trim_spaces(line);
	if (!check_extension_file(*text_path, ".xpm"))
	{
		error_msg_parsing(TEXTURE_EXT_ERROR);
		error_msg_texture(*text_path);
		return (0);
	}
	return (1);
}
