/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_map.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: louise <lsoulier@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/18 22:07:27 by louise            #+#    #+#             */
/*   Updated: 2020/11/20 21:16:37 by user42           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"
#include "libft.h"

int	set_player_start(t_game_file *parsed_file)
{
	int		x;
	int		y;
	char	*line;
	int		found;

	y = -1;
	line = *parsed_file->map;
	found = 0;
	while (!found && line)
	{
		x = -1;
		line = parsed_file->map[++y];
		while (!found && line[++x])
			if (ft_strchr(CARD_CHARSET, line[x]) != NULL)
				found = 1;
	}
	if (!found)
	{
		error_msg_parsing(NO_PLAYER_START_ERROR);
		return (0);
	}
	set_point(&(parsed_file->player_start), x, y);
	parsed_file->player_start_card = parsed_file->map[y][x];
	parsed_file->map[y][x] = '0';
	return (1);
}

int		check_map(char **map)
{
	int		x;
	int		y;
	int		line_len;
	char	*not_wall;
	int		map_height;

	y = -1;
	not_wall = "02NSWE ";
	map_height = 0;
	while (map[map_height])
		map_height++;
	while (map[++y])
	{
		x = -1;
		printf("%s\n", map[y]);
		line_len = (int)ft_strlen(map[y]);
		while (map[y][++x])
			if ((ft_strchr(not_wall, map[y][x]) != NULL) && (y == 0 || x == 0
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

char	**realloc_map(char **data, int prev_size, int new_size)
{
	char	**new_data;
	int		i;

	i = -1;
	new_data = malloc(sizeof(char*) * new_size);
	if (!new_data)
		return (NULL);
	while (++i < prev_size)
		new_data[i] = data[i];
	if (data)
		free(data);
	return (new_data);
}

char	**create_map(char **line, int fd)
{
	char	**map;
	int		line_nb;
	int		ret_gnl;

	line_nb = 0;
	ret_gnl = 1;
	map = NULL;
	while (ret_gnl)
	{
		map = realloc_map(map, line_nb, line_nb + 1);
		if (!map)
		{
			error_msg_alloc(MAP_TAB_ALLOCATION_ERROR);
			return (NULL);
		}
		map[line_nb] = ft_strdup(*line);
		free(*line);
		line_nb++;
		ret_gnl = get_next_line(fd, line);
	}
	map[line_nb] = NULL;
	return (map);
}

int		set_map(t_game_file *parsed_file, char **line, int fd)
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
	if (!set_player_start(parsed_file))
		return (0);
	return (1);
}
