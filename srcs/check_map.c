/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lsoulier <lsoulier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/28 13:01:59 by lsoulier          #+#    #+#             */
/*   Updated: 2020/11/29 00:19:14 by user42           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parsing.h"

int		check_around(char **map, int x, int y)
{
	if (map[y - 1][x] == ' ' || map[y + 1][x] == ' '
		|| map[y][x - 1] == ' ' || map[y][x + 1] == ' '
		|| !map[y - 1][x - 1] || map[y - 1][x - 1] == ' '
		|| !map[y + 1][x - 1] || map[y + 1][x - 1] == ' '
		|| !map[y - 1][x + 1] || map[y - 1][x + 1] == ' '
		|| !map[y + 1][x + 1] || map[y + 1][x + 1] == ' ')
		return (0);
	return (1);
}

int		invalid_map(char **map, int y, int map_height, int line_len)
{
	int		x;
	int		next_len;
	int		previous_len;

	x = -1;
	if (y > 0)
		previous_len = ft_strlen(map[y - 1]);
	next_len = y + 1 != map_height ? (int)ft_strlen(map[y + 1]) : 0;
	while (map[y][++x])
	{
		if ((ft_strchr(NOT_WALL, map[y][x]) != NULL) && (y == 0 || x == 0
			|| y == (map_height - 1) || x == (line_len - 1)
			|| x - 1 > previous_len || x + 1 > next_len
			|| !check_around(map, x, y)))
		{
			error_msg_parsing(MAP_NOT_CLOSED_ERROR);
			return (1);
		}
		if (ft_strchr(ELEMENTS_CHARSET, map[y][x]) == NULL)
		{
			error_msg(UNKNOWN_ELEMENT_ERROR);
			return (1);
		}
	}
	return (0);
}

int		check_map(char **map)
{
	int		y;
	int		line_len;
	int		map_height;

	y = -1;
	map_height = 0;
	while (map[map_height])
		map_height++;
	while (map[++y])
	{
		line_len = ft_strlen(map[y]);
		if (invalid_map(map, y, map_height, line_len))
			return (0);
	}
	return (1);
}
