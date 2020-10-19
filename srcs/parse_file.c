/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_file.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: louise <lsoulier@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/18 19:25:00 by louise            #+#    #+#             */
/*   Updated: 2020/10/19 22:31:10 by louise           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"
#include "libft.h"

t_game	*init_map(void)
{
	t_game	*parsed_map;

	if(!(parsed_map = (t_game*)malloc(sizeof(t_game))))
		return (NULL);
	parsed_map->map = NULL;
	init_point(&(parsed_map->player_start));
	init_dimension(&(parsed_map->map_res));
	init_dimension(&(parsed_map->window_res));
	init_file(&(parsed_map->no_text));
	init_file(&(parsed_map->so_text));
	init_file(&(parsed_map->we_text));
	init_file(&(parsed_map->ea_text));
	init_file(&(parsed_map->sprite_text));
	init_color(&(parsed_map->floor_color));
	init_color(&(parsed_map->ceiling_color));
	return (parsed_map);
}

t_game	*parse_file(t_file cubmap)
{
	char	*line;
	t_game	*parsed_map;

	if (!(parsed_map = init_map()))
		return (NULL);
	while (get_next_line(cubmap.fd, &line) == 1)
	{
		if (ft_strnstr(line, "R ", 2) != NULL)
			set_window_res(line, &(parsed_map->window_res));
		else if (ft_strnstr(line, "NO ", 3) != NULL)
			set_map_texture(line, &(parsed_map->no_text));
		else if (ft_strnstr(line, "SO ", 3) != NULL)
			set_map_texture(line, &(parsed_map->so_text));
		else if (ft_strnstr(line, "WE ", 3) != NULL)
			set_map_texture(line, &(parsed_map->we_text));
		else if (ft_strnstr(line, "EA ", 3) != NULL)
			set_map_texture(line, &(parsed_map->ea_text));
		else if (ft_strnstr(line, "S ", 2) != NULL)
			set_map_texture(line, &(parsed_map->sprite_text));
		else if (ft_strnstr(line, "F ", 2) != NULL)
			set_map_color(line, &(parsed_map->floor_color));
		else if (ft_strnstr(line, "C ", 2) != NULL)
			set_map_color(line, &(parsed_map->ceiling_color));
		else if(*line)
		{
			set_map(parsed_map, &line, cubmap.fd);
			break;
		}
	}
	return (parsed_map);
}