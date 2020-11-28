/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing_map.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lsoulier <lsoulier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/22 13:34:19 by lsoulier          #+#    #+#             */
/*   Updated: 2020/11/28 13:20:43 by user42           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parsing.h"

int		parse_map(t_game_file *parsed_file, char **line, int fd)
{
	if (!*line)
	{
		error_msg_parsing(MAP_EMPTY_ERROR);
		return (0);
	}
	parsed_file->map = create_map(line, fd);
	if (!parsed_file->map)
		return (0);
	if (!check_map(parsed_file->map))
		return (0);
	if (!set_map_settings(parsed_file))
		return (0);
	return (1);
}

int		set_map_settings(t_game_file *parsed_file)
{
	int		map_width;
	int		y;
	char	**map;

	y = -1;
	map = parsed_file->map;
	map_width = 0;
	while (map[++y])
		if ((int)ft_strlen(map[y]) > map_width)
			map_width = ft_strlen(map[y]);
	set_dimension(&parsed_file->map_res, map_width, y);
	if (!parse_player_star(parsed_file->map, &parsed_file->player_start,
		&parsed_file->player_start_card))
		return (0);
	parsed_file->map[(int)parsed_file->player_start.y]
		[(int)parsed_file->player_start.x] = '0';
	return (1);
}

char	**concat_lines(char **map, int line_index, char *line)
{
	char	**new_map;
	int		i;

	i = -1;
	new_map = (char **)ft_calloc(line_index + 2, sizeof(char *));
	if (!new_map)
	{
		error_msg(ALLOCATION_ERROR);
		return (NULL);
	}
	if (line_index != 0)
	{
		while (++i < line_index)
			new_map[i] = map[i];
		free(map);
	}
	new_map[line_index] = ft_strdup(line);
	free(line);
	if (!new_map[line_index])
	{
		error_msg(ALLOCATION_ERROR);
		return (NULL);
	}
	return (new_map);
}

char	**create_map(char **line, int fd)
{
	char	**map;
	int		line_index;
	int		ret_gnl;

	line_index = 0;
	ret_gnl = 1;
	map = NULL;
	while (ret_gnl >= 0 && !(line_is_whitespace(*line)))
	{
		map = concat_lines(map, line_index, *line);
		*line = NULL;
		if (!map)
			return (0);
		if (ret_gnl == 0)
			break ;
		line_index++;
		ret_gnl = get_next_line(fd, line);
	}
	if (line_is_whitespace(*line))
		free(*line);
	return (map);
}
