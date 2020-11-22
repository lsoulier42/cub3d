/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing_colors.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lsoulier <lsoulier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/22 13:30:10 by lsoulier          #+#    #+#             */
/*   Updated: 2020/11/22 14:17:30 by user42           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parsing.h"
#include "libft.h"

int		parse_colors(t_game_file *parsed_file, char *line)
{
	if (ft_strnstr(line, "F", 1) != NULL)
		if (!set_background_color(line, &parsed_file->floor_color))
			return (0);
	if (ft_strnstr(line, "C", 1) != NULL)
		if (!set_background_color(line, &parsed_file->ceiling_color))
			return (0);
	return (1);
}

int check_color_format(char *line)
{
	int		i;
	int 	nb_coma;
	int 	no_error;
	char 	*new_line;

	i = -1;
	nb_coma = 0;
	new_line = trim_spaces(line);
	no_error = new_line && ft_isdigit(*new_line);
	while (new_line[++i] && no_error)
	{
		if (new_line[i] == ',')
		{
			nb_coma++;
			if (!ft_isdigit(new_line[i + 1]))
				no_error = 0;
		}
		if (new_line[i] != ',' && !ft_isdigit(new_line[i]))
			no_error = 0;
	}
	if (nb_coma != 2)
		no_error = 0;
	free(new_line);
	return (no_error);
}

int	set_background_color(char *line, int *color)
{
	int		r;
	int		g;
	int		b;

	line += 2;
	if (!ft_isdigit(*line) || !check_color_format(line))
	{
		error_msg_parsing(COLOR_SETTING_ERROR);
		return (0);
	}
	r = ft_atoi(line);
	while (*line && *line != ',')
		line++;
	line++;
	g = ft_atoi(line);
	while (*line && *line != ',')
		line++;
	line++;
	b = ft_atoi(line);
	if (r < 0 || g < 0 || b < 0 || r > 255 || g > 255 || b > 255)
	{
		error_msg_parsing(COLOR_SETTING_ERROR);
		return (0);
	}
	*color = create_trgb(0, r, g, b);
	return (1);
}

int 		check_background(int floor_color, int ceiling_color)
{
	if((floor_color == -1 && ceiling_color != -1)
	   || (floor_color != -1 && ceiling_color == -1))
		return (0);
	return (1);
}
