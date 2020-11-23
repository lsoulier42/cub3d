/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lsoulier <lsoulier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/22 13:35:26 by lsoulier          #+#    #+#             */
/*   Updated: 2020/11/23 01:17:05 by user42           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parsing.h"

int	parse_settings(t_game_file *parsed_file, int fd)
{
	char	*line;
	int 	ret_gnl;
	int		error_occurred;

	ret_gnl = 1;
	line = NULL;
	error_occurred = 0;
	while (ret_gnl && !error_occurred && !parsed_file->settings_complete)
	{
		ret_gnl = get_next_line(fd, &line);
		if (ret_gnl == -1)
			return (0);
		if (ft_strchr(SETTINGS_CHARSET, *line) != NULL)
		{
			if (!parse_resolution(parsed_file, line))
				error_occurred = 1;
			if (!parse_textures(parsed_file, line))
				error_occurred = 1;
			if (!parse_colors(parsed_file, line))
				error_occurred = 1;
			check_missing_settings(parsed_file);
		}
		free(line);
	}
	return (!error_occurred);
}

void 	check_missing_settings(t_game_file *parsed_file)
{
	if (parsed_file->floor_color != -1 && parsed_file->ceiling_color != -1
		&& parsed_file->win_res.width != 0 && parsed_file->win_res.height != 0
		&& parsed_file->so_text != NULL && parsed_file->no_text != NULL
		&& parsed_file->ea_text != NULL && parsed_file->we_text != NULL
		&& parsed_file->sprite_text != NULL)
			parsed_file->settings_complete = 1;
}

char	**realloc_map(char **data, int prev_size, int new_size)
{
	char	**new_data;
	int		i;

	i = -1;
	new_data = (char**)malloc(sizeof(char*) * new_size);
	if (!new_data)
		return (NULL);
	while (++i < prev_size)
		new_data[i] = data[i];
	new_data[i]= NULL;
	if(prev_size != 0)
		free(data);
	return (new_data);
}

