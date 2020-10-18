/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_file.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: louise <lsoulier@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/18 19:25:00 by louise            #+#    #+#             */
/*   Updated: 2020/10/18 21:22:51 by louise           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"
#include "libft.h"

t_game		*init_map(void)
{

}

t_dimension	*set_window_res(char *line)
{
	t_dimension *window_res;

	if (!(window_re = (t_dimension*)malloc(sizeof(t_dimension))))
		return (NULL);
	while (!ft_isdigit(*line))
		line++;
	window_res->width = (int)ft_atoi(line);
	while(ft_isdigit(*line))
		line++;
	window_res->height = (int)ft_atoi(line);
	return(window_res);
}

t_file		*set_texture(char *line)
{
	t_file	*text_file;
	char 	*filestr;

	while (ft_isalpha(*line))
		line++;
	filestr = ft_strtrim(line, " ");
	if(!(text_file = check_file(filestr)))
		return (NULL);
	return (text_file);
}

t_color		*set_color(char *line)
{
	t_color	*color;

	if(!(color = (t_color*)malloc(sizeof(t_color))))
		return (NULL);
	while (ft_isalpha(*line))
		line++;
	color->r = (char)ft_atoi(line);
	while (*line != ',')
		line++;
	line++;
	color->g = (char)ft_atoi(line);
	while (*line != ',')
		line++;
	line++;
	 color->b = (char)ft_atoi(line);
	 return (color);
}

t_game		*parse_file(t_file *cubmap)
{
	char	*line;
	t_game	*parsed_map;

	if (!(parsed_map = init_map()))
		return (NULL);
	while (get_next_line(cubmap->fd, &line) == 1)
	{
		if (ft_strnstr(line, "R ", 2) != NULL)
			parsed_map->window_res = set_window_res(line);
		else if (ft_strnstr(line, "NO ", 3) != NULL)
			parsed_map->no_text = set_texture(line);
		else if (ft_strnstr(line, "SO ", 3) != NULL)
			parsed_map->so_text = set_texture(line);
		else if (ft_strnstr(line, "WE ", 3) != NULL)
			parsed_map->we_text = set_texture(line);
		else if (ft_strnstr(line, "EA ", 3) != NULL)
			parsed_map->ea_text = set_texture(line);
		else if (ft_strnstr(line, "S ", 2) != NULL)
			parsed_map->sprite_text = set_texture(line);
		else if (ft_strnstr(line, "F ", 2) != NULL)
			parsed_map->floor_color = set_color(line);
		else if (ft_strnstr(line, "C ", 2) != NULL)
			parsed_map->ceiling_color = set_color(line);
		else if(*line)
			set_map(parsed_map, &line);
	}
	return (parsed_map);
}