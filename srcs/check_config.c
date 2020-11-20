/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_config.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lsoulier <lsoulier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/20 14:59:51 by lsoulier          #+#    #+#             */
/*   Updated: 2020/11/20 16:57:44 by user42           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "cub3d.h"

int		check_texture_config(t_game_file *parsed_file, char *line)
{
	if (ft_strnstr(line, "NO ", 3) != NULL)
		if (!set_map_texture(line, &parsed_file->no_text))
			return (0);
	if (ft_strnstr(line, "SO ", 3) != NULL)
		if (!set_map_texture(line, &parsed_file->so_text))
			return (0);
	if (ft_strnstr(line, "WE ", 3) != NULL)
		if (!set_map_texture(line, &parsed_file->we_text))
			return (0);
	if (ft_strnstr(line, "EA ", 3) != NULL)
		if (!set_map_texture(line, &parsed_file->ea_text))
			return (0);
	if (ft_strnstr(line, "S ", 2) != NULL)
		if (!set_map_texture(line, &parsed_file->sprite_text))
			return (0);
	return (1);
}

int		check_color_config(t_game_file *parsed_file, char *line)
{
	if (ft_strnstr(line, "F ", 2) != NULL)
		if (!set_map_color(line, &parsed_file->floor_color))
			return (0);
	if (ft_strnstr(line, "C ", 2) != NULL)
		if (!set_map_color(line, &parsed_file->ceiling_color))
			return (0);
	return (1);
}

int 	check_resolution_config(t_game_file *parsed_file, char *line)
{
	if (ft_strnstr(line, "R ", 2) != NULL)
		if (!set_window_res(line, &parsed_file->win_res))
			return (0);
	return (1);
}

int		check_config(t_game_file *parsed_file, char *line)
{
	if (!check_resolution_config(parsed_file, line))
		return (0);
	if (!check_texture_config(parsed_file, line))
		return (0);
	if (!check_color_config(parsed_file, line))
		return (0);
	return (1);
}