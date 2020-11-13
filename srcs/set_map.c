/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_map.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: louise <lsoulier@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/18 22:07:27 by louise            #+#    #+#             */
/*   Updated: 2020/11/13 01:04:06 by user42           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"
#include "libft.h"

char	**create_map(char **map, char *line, int line_nb)
{
	char	**new_map;
	int		i;

	i = -1;
	new_map = (char**)malloc(sizeof(char*) * (line_nb + 1));
	if (!new_map)
		return (NULL);
	while (++i < line_nb - 1)
		new_map[i] = map[i];
	free(map);
	new_map[i] = ft_strdup(line);
	new_map[line_nb] = NULL;
	return (new_map);
}

void	set_player_start(t_game *parsed_map)
{
	int		x;
	int		y;
	char	*line;
	int		found;

	y = -1;
	line = parsed_map->map[0];
	found = 0;
	while (!found && line)
	{
		x = -1;
		line = parsed_map->map[++y];
		while (!found && line[++x])
			if (ft_strchr(CARD_CHARSET, line[x]) != NULL)
				found = 1;
	}
	set_point(&(parsed_map->player_start), x, y);
	parsed_map->player_start_card = parsed_map->map[y][x];
	parsed_map->map[y][x] = '0';
}

int		check_map(char **map, int map_height)
{
	int		x;
	int		y;
	int		line_len;
	char	*not_wall;

	y = -1;
	not_wall = "02NSWE";
	while (map[++y])
	{
		x = -1;
		line_len = (int)ft_strlen(map[y]);
		while (map[y][++x])
			if ((ft_strchr(not_wall, map[y][x]) != NULL) && (y == 0 || x == 0
				|| y == (map_height - 1) || x == (line_len - 1)
				|| map[y - 1][x] == ' ' || map[y + 1][x] == ' '
				|| map[y][x - 1] == ' ' || map[y][x + 1] == ' '))
				return (0);
	}
	return (1);
}

void	set_parsed_map(t_game *parsed_map, char **map,
	int map_width, int map_height)
{
	parsed_map->map = map;
	set_dimension(&(parsed_map->map_res), map_width, map_height);
	set_player_start(parsed_map);
}

void	set_map(t_game *parsed_map, char **line, int fd)
{
	int		line_nb;
	int		max_width;
	int		line_len;
	char	**map;
	int		ret_gnl;

	line_nb = 0;
	ret_gnl = 1;
	max_width = 0;
	map = (char**)malloc(sizeof(char*) * 2);
	if (map != NULL)
	{
		while (ret_gnl)
		{
			map = create_map(map, *line, ++line_nb);
			line_len = (int)ft_strlen(*line);
			if (max_width < line_len)
				max_width = line_len;
			free(*line);
			ret_gnl = get_next_line(fd, line);
		}
		if (check_map(map, line_nb))
			set_parsed_map(parsed_map, map, max_width, line_nb);
	}
}
