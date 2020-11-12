/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_file.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: louise <lsoulier@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/18 19:25:00 by louise            #+#    #+#             */
/*   Updated: 2020/11/12 15:57:57 by user42           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"
#include "libft.h"

t_game	*init_parsed_map(void)
{
	t_game	*parsed_map;

	if (!(parsed_map = (t_game*)malloc(sizeof(t_game))))
		return (NULL);
	parsed_map->map = NULL;
	parsed_map->player_start_card = 0;
	set_point(&(parsed_map->player_start), 0, 0);
	set_dimension(&(parsed_map->map_res), 0, 0);
	set_dimension(&(parsed_map->window_res), 0, 0);
	parsed_map->no_text = NULL;
	parsed_map->so_text = NULL;
	parsed_map->we_text = NULL;
	parsed_map->ea_text = NULL;
	parsed_map->sprite_text = NULL;
	set_color(&(parsed_map->floor_color), 0, 0, 0);
	set_color(&(parsed_map->ceiling_color), 0, 0, 0);
	return (parsed_map);
}

void	check_config(t_game *parsed_map, char **line, int fd)
{
	if (ft_strnstr(*line, "R ", 2) != NULL)
		set_window_res(*line, &parsed_map->window_res);
	else if (ft_strnstr(*line, "NO ", 3) != NULL)
		set_map_texture(*line, &parsed_map->no_text);
	else if (ft_strnstr(*line, "SO ", 3) != NULL)
		set_map_texture(*line, &parsed_map->so_text);
	else if (ft_strnstr(*line, "WE ", 3) != NULL)
		set_map_texture(*line, &parsed_map->we_text);
	else if (ft_strnstr(*line, "EA ", 3) != NULL)
		set_map_texture(*line, &parsed_map->ea_text);
	else if (ft_strnstr(*line, "S ", 2) != NULL)
		set_map_texture(*line, &parsed_map->sprite_text);
	else if (ft_strnstr(*line, "F ", 2) != NULL)
		set_map_color(*line, &parsed_map->floor_color);
	else if (ft_strnstr(*line, "C ", 2) != NULL)
		set_map_color(*line, &parsed_map->ceiling_color);
	else if (**line)
		set_map(parsed_map, line, fd);
}

t_game	*parse_file(char *path)
{
	char	*line;
	int		ret_gnl;
	t_game	*parsed_map;
	int		fd;

	ret_gnl = 1;
	fd = check_file(path);
	parsed_map = init_parsed_map();
	if (fd <= 0 || !parsed_map)
		return (NULL);
	while (ret_gnl)
	{
		ret_gnl = get_next_line(fd, &line);
		check_config(parsed_map, &line, fd);
		free(line);
	}
	return (parsed_map);
}
