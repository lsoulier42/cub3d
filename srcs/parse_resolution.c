/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing_resolution.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lsoulier <lsoulier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/22 14:03:31 by lsoulier          #+#    #+#             */
/*   Updated: 2020/11/28 00:56:00 by user42           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parsing.h"

int	str_is_uint(char *str)
{
	int i;

	i = -1;
	while (str[++i])
		if (!ft_isdigit(str[i]))
			return (0);
	return (1);
}

int	invalid_format_res(char **values)
{
	if (nb_tab_values(values) != 3)
		return (1);
	if (!str_is_uint(values[1]) || !str_is_uint(values[2]))
		return (1);
	return (0);
}

int	parse_resolution(t_game_file *parsed_file, char **values)
{
	int width;
	int height;

	if (parsed_file->win_res.height != 0)
	{
		error_msg_parsing(RESOLUTION_ALREADY_SET);
		return (0);
	}
	if (invalid_format_res(values))
	{
		error_msg_parsing(FORMAT_RESOLUTION_ERROR);
		return (0);
	}
	width = ft_atoi(values[1]);
	height = ft_atoi(values[2]);
	if (width <= 0 || height <= 0)
	{
		error_msg_parsing(FORMAT_RESOLUTION_ERROR);
		return (0);
	}
	set_dimension(&parsed_file->win_res, width, height);
	return (1);
}
