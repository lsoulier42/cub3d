/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing_resolution.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lsoulier <lsoulier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/22 14:03:31 by lsoulier          #+#    #+#             */
/*   Updated: 2020/11/22 14:07:15 by user42           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parsing.h"

int	parse_resolution(t_game_file *parsed_file, char *line)
{
	if (ft_strnstr(line, "R ", 2) != NULL)
		if (!set_win_res(line, &parsed_file->win_res))
			return (0);
	return (1);
}

int	set_win_res(char *line, t_dimension *win_res)
{
	int width;
	int height;
	int i;

	i = -1;
	while (*line && !ft_isdigit(*line))
		line++;
	while (line[++i])
		if (!ft_isdigit(line[i]) && line[i] != ' ')
		{
			error_msg_parsing(FORMAT_RESOLUTION_ERROR);
			return (0);
		}
	width = (int)ft_atoi(line);
	while (*line && ft_isdigit(*line))
		line++;
	height = (int)ft_atoi(line);
	if (width <= 0 || height <= 0
		|| width > FOUR_K_RES_WIDTH || height > FOUR_K_RES_HEIGHT)
	{
		error_msg_parsing(FORMAT_RESOLUTION_ERROR);
		return (0);
	}
	set_dimension(win_res, width, height);
	return (1);
}
