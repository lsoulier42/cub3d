/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_map.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: louise <lsoulier@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/18 22:07:27 by louise            #+#    #+#             */
/*   Updated: 2020/10/19 23:18:44 by louise           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"
#include "libft.h"

char 	**complete_map(char **map, char *line, int nb_lines)
{
	char	**new_map;
	int		i;

	i = -1;
	if(!(new_map = (char**)malloc(sizeof(char*) * (nb_lines + 1))))
		return (NULL);
	while (++i < nb_lines - 1)
		new_map[i] = map[i];
	free(map);
	new_map[i] = ft_strdup(line);
	new_map[nb_lines] = NULL;
	return (new_map);
}

void 	set_map(t_game *parsed_map, char **line, int fd)
{
	int 	nb_lines;
	int 	max_width;
	int 	line_len;
	char 	**map;
	int 	is_not_end;

	nb_lines = 2;
	max_width = ft_strlen(*line);
	if((map = (char**)malloc(sizeof(char*) * 2)) != NULL)
	{
		map[0] = ft_strdup(*line);
		map[1] = NULL;
		while ((is_not_end = get_next_line(fd, line)) >= 0) {
			map = complete_map(map, *line, nb_lines);
			nb_lines++;
			if (max_width < (line_len = (int) ft_strlen(*line)))
				max_width = line_len;
			if(!is_not_end)
				break;
		}
		parsed_map->map = map;
		set_dimension(&(parsed_map->map_res), max_width, nb_lines - 1);
	}
}