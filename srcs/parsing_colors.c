/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing_colors.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lsoulier <lsoulier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/22 13:30:10 by lsoulier          #+#    #+#             */
/*   Updated: 2020/11/27 03:00:58 by user42           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parsing.h"
#include "libft.h"

int		parse_colors(t_game_file *parsed_file, char *line)
{
	if (ft_strnstr(line, "F", 1) != NULL)
	{
		if (parsed_file->floor_color != -1)
		{
			error_msg_parsing(COLOR_ALREADY_SET_ERROR);
			return (0);
		}
		if (!set_background_colors(line, &parsed_file->floor_color))
			return (0);
	}
	if (ft_strnstr(line, "C", 1) != NULL)
	{
		if (parsed_file->ceiling_color != -1)
		{
			error_msg_parsing(COLOR_ALREADY_SET_ERROR);
			return (0);
		}
		if (!set_background_colors(line, &parsed_file->ceiling_color))
			return (0);
	}
	return (1);
}

int		check_color_format(char *line)
{
	int		nb_comas;
	int		i;
	char	*new_line;
	int		error_occurred;

	i = -1;
	nb_comas = 0;
	error_occurred = 0;
	new_line = trim_spaces(line + 1);
	if (!new_line)
		return (0);
	if (!ft_isdigit(*new_line))
		error_occurred = 1;
	while (new_line[++i])
	{
		if (new_line[i] == ',')
			nb_comas++;
		if (!ft_isdigit(new_line[i]) && new_line[i] != ',')
			error_occurred = 1;
	}
	if (nb_comas != 2 || !ft_isdigit(new_line[i - 1]))
		error_occurred = 1;
	free(new_line);
	return (!error_occurred);
}

int		atoi_color(char *line, int index)
{
	char	*new_line;
	int		ret_nb;
	char	*tmp;

	if (!(new_line = trim_spaces(line + 2)))
		return (-1);
	tmp = new_line;
	if (index == 1)
		ret_nb = ft_atoi(new_line);
	else
	{
		while (*new_line && *new_line != ',')
			new_line++;
		if (index == 2)
			ret_nb = ft_atoi(new_line + 1);
		else
		{
			new_line++;
			while (*new_line && *new_line != ',')
				new_line++;
			ret_nb = ft_atoi(new_line + 1);
		}
	}
	free(tmp);
	return (ret_nb);
}

int		set_background_colors(char *line, int *color)
{
	t_parsing_color	colors;

	if (!check_color_format(line))
	{
		error_msg_parsing(COLOR_SETTING_ERROR);
		return (0);
	}
	colors.r = atoi_color(line, 1);
	colors.g = atoi_color(line, 2);
	colors.b = atoi_color(line, 3);
	if (colors.r < 0 || colors.g < 0 || colors.b < 0
		|| colors.r > 255 || colors.g > 255 || colors.b > 255)
	{
		error_msg_parsing(COLOR_SETTING_ERROR);
		return (0);
	}
	*color = create_trgb(0, colors.r, colors.g, colors.b);
	return (1);
}
