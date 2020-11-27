/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing_resolution.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lsoulier <lsoulier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/22 14:03:31 by lsoulier          #+#    #+#             */
/*   Updated: 2020/11/27 20:24:15 by user42           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parsing.h"

int	parse_resolution(t_game_file *parsed_file, char *line)
{
	if (ft_strnstr(line, "R", 2) != NULL)
	{
		if (line[1] != ' ')
		{
			error_msg_parsing(SETTING_INVALID);
			return (0);
		}
		if (!set_win_res(line, &parsed_file->win_res))
			return (0);
	}
	return (1);
}

int	set_win_res(char *line, t_dimension *win_res)
{
	int i;

	i = -1;
	if (ft_strchr(line, '-') != NULL)
	{
		error_msg_parsing(FORMAT_RESOLUTION_ERROR);
		return (0);
	}
	while (*line && !ft_isdigit(*line))
		line++;
	i = -1;
	while (line[++i])
	{
		if (!ft_isdigit(line[i]) && line[i] != ' ') {
			error_msg_parsing(FORMAT_RESOLUTION_ERROR);
			return (0);
		}
	}
	if (!detect_res(line, win_res))
		return (0);
	return (1);
}

void free_res_tab(char **values)
{
	int i;

	i = -1;
	while (values[++i])
		free(values[i]);
	free(values);
}

char **create_res_tab(char *line)
{
	char **values;
	int nb_num;

	values = ft_split(line, ' ');
	nb_num = 0;
	if (!values)
	{
		error_msg(ALLOCATION_ERROR);
		return (NULL);
	}
	while (values[nb_num])
		nb_num++;
	if (nb_num != 2)
	{
		error_msg_parsing(FORMAT_RESOLUTION_ERROR);
		free_res_tab(values);
		return (NULL);
	}
	return (values);
}

int detect_res(char *line, t_dimension *win_res)
{
	char **values;
	int width;
	int height;

	values = create_res_tab(line);
	if (!values)
		return (0);
	width = ft_atoi(values[0]);
	height = ft_atoi(values[1]);
	if (width <= 0 || height <= 0
		|| width > FOUR_K_RES_WIDTH || height > FOUR_K_RES_HEIGHT)
	{
		error_msg_parsing(FORMAT_RESOLUTION_ERROR);
		free_res_tab(values);
		return (0);
	}
	free_res_tab(values);
	set_dimension(win_res, width, height);
	return (1);
}
