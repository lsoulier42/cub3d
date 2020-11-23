/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing_map.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lsoulier <lsoulier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/22 13:34:19 by lsoulier          #+#    #+#             */
/*   Updated: 2020/11/23 00:05:04 by user42           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parsing.h"

int		parse_map(t_game_file *parsed_file, char **line, int fd)
{
	char	**map;
	int		map_width;
	int		y;

	map = create_map(line, fd);
	y = -1;
	map_width = 0;
	if (!map)
		return (0);
	if (!check_map(map))
		return (0);
	parsed_file->map = map;
	while (map[++y])
		if ((int)ft_strlen(map[y]) > map_width)
			map_width = ft_strlen(map[y]);
	set_dimension(&parsed_file->map_res, map_width, y);
	if (!parse_player_start(parsed_file))
		return (0);
	return (1);
}

char	**create_map(char **line, int fd)
{
	char	**map;
	int		line_nb;
	int		ret_gnl;

	line_nb = 0;
	ret_gnl = 1;
	map = NULL;
	while (ret_gnl >= 0)
	{
		map = realloc_map(map, line_nb, line_nb + 1);
		if (!map)
		{
			error_msg(ALLOCATION_ERROR);
			return (NULL);
		}
		if (ret_gnl != 0)
			map[line_nb] = ft_strdup(*line);
		free(*line);
		if (ret_gnl == 0)
			break ;
		line_nb++;
		ret_gnl = get_next_line(fd, line);
	}
	*line = NULL;
	return (map);
}

int		check_map(char **map)
{
	int		x;
	int		y;
	int		line_len;
	int		map_height;

	y = -1;
	map_height = 0;
	while (map[map_height])
		map_height++;
	while (map[++y])
	{
		x = -1;
		line_len = (int)ft_strlen(map[y]);
		while (map[y][++x])
			if ((ft_strchr(NOT_WALL, map[y][x]) != NULL) && (y == 0 || x == 0
				|| y == (map_height - 1) || x == (line_len - 1)
				|| map[y - 1][x] == ' ' || map[y + 1][x] == ' '
				|| map[y][x - 1] == ' ' || map[y][x + 1] == ' '))
			{
				error_msg_parsing(MAP_NOT_CLOSED_ERROR);
				return (0);
			}
	}
	return (1);
}
