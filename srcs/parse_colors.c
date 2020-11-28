/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing_colors.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lsoulier <lsoulier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/22 13:30:10 by lsoulier          #+#    #+#             */
/*   Updated: 2020/11/28 01:29:04 by user42           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parsing.h"
#include "libft.h"

int		check_color_comas(char *line)
{
	int i;
	int nb_comas;

	i = -1;
	nb_comas = 0;
	while (line[++i])
		if (line[i] == ',')
			nb_comas++;
	if (nb_comas != 2)
	{
		error_msg_parsing(COLOR_SETTING_ERROR);
		return (0);
	}
	return (1);
}

int		invalid_format_color(char **values)
{
	char	*r;
	char	*g;
	char	*b;

	if (nb_tab_values(values) != 4)
		return (1);
	r = values[1];
	g = values[2];
	b = values[3];
	if (!str_is_uint(r) || !str_is_uint(g) || !str_is_uint(b))
		return (1);
	return (0);
}

int		set_colors(t_game_file *parsed_file, char **values)
{
	int r;
	int g;
	int b;
	int color;

	r = ft_atoi(values[1]);
	g = ft_atoi(values[2]);
	b = ft_atoi(values[3]);
	color = create_trgb(0, r, g, b);
	if (r > 255 || g > 255 || b > 255)
	{
		error_msg_parsing(COLOR_SETTING_ERROR);
		return (0);
	}
	if (ft_strcmp(values[0], "F") == 0)
		parsed_file->floor_color = color;
	else if (ft_strcmp(values[0], "C") == 0)
		parsed_file->ceiling_color = color;
	return (1);
}

int		parse_colors(t_game_file *parsed_file, char **values)
{
	if (invalid_format_color(values))
	{
		error_msg_parsing(COLOR_SETTING_ERROR);
		return (0);
	}
	if ((ft_strcmp(values[0], "F") == 0 && parsed_file->floor_color != -1)
		|| (ft_strcmp(values[0], "C") == 0
			&& parsed_file->ceiling_color != -1))
	{
		error_msg_parsing(COLOR_ALREADY_SET_ERROR);
		return (0);
	}
	if (!set_colors(parsed_file, values))
		return (0);
	return (1);
}
