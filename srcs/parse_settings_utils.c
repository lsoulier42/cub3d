/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_settings_utils.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lsoulier <lsoulier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/27 22:59:47 by lsoulier          #+#    #+#             */
/*   Updated: 2020/11/28 13:24:47 by user42           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parsing.h"

int		get_settings(t_game_file *parsed_file, char **values)
{
	int		(*parsing_fct[NB_SETTINGS])(t_game_file*, char**);
	char	**setting_values;
	int		i;
	int		ret_value;

	i = -1;
	setting_values = (char *[NB_SETTINGS + 1]) {"R", "NO", "SO", "WE",
		"EA", "S", "F", "C", NULL};
	ret_value = 0;
	parsing_fct[0] = &parse_resolution;
	parsing_fct[1] = &parse_textures;
	parsing_fct[2] = &parse_textures;
	parsing_fct[3] = &parse_textures;
	parsing_fct[4] = &parse_textures;
	parsing_fct[5] = &parse_textures;
	parsing_fct[6] = &parse_colors;
	parsing_fct[7] = &parse_colors;
	while (setting_values[++i])
		if (ft_strcmp(setting_values[i], values[0]) == 0)
			ret_value = parsing_fct[i](parsed_file, values);
	return (ret_value);
}

void	check_missing_settings(t_game_file *parsed_file)
{
	if (parsed_file->floor_color != -1 && parsed_file->ceiling_color != -1
		&& parsed_file->win_res.width != 0 && parsed_file->win_res.height != 0
		&& parsed_file->so_text != NULL && parsed_file->no_text != NULL
		&& parsed_file->ea_text != NULL && parsed_file->we_text != NULL
		&& parsed_file->sprite_text != NULL)
		parsed_file->settings_complete = 1;
}
