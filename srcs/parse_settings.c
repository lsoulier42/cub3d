/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_settings.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lsoulier <lsoulier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/27 22:32:06 by lsoulier          #+#    #+#             */
/*   Updated: 2020/11/28 13:23:39 by user42           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parsing.h"

int		config_available(char **values)
{
	char	**setting_values;
	int		i;

	i = -1;
	setting_values = (char *[NB_SETTINGS + 1]) {"R", "NO", "SO", "WE",
		"EA", "S", "F", "C", NULL};
	while (setting_values[++i])
		if (ft_strcmp(values[0], setting_values[i]) == 0)
			return (1);
	return (0);
}

char	**parse_line(char *line)
{
	char	**values;

	if (ft_strchr(line, 'F') != NULL || ft_strchr(line, 'C') != NULL)
	{
		if (!check_color_comas(line))
		{
			free(line);
			return (0);
		}
		else
			values = ft_split_charset(line, " ,");
	}
	else
		values = ft_split(line, ' ');
	if (!values)
	{
		free(line);
		error_msg(ALLOCATION_ERROR);
		return (NULL);
	}
	free(line);
	return (values);
}

int		parse_settings_suite(t_game_file *parsed_file, char *line)
{
	char	**values;

	values = parse_line(line);
	if (!values)
		return (0);
	if (!config_available(values))
	{
		error_msg_parsing(SETTING_INVALID);
		free_double_tab(values);
		return (0);
	}
	if (!get_settings(parsed_file, values))
	{
		free_double_tab(values);
		return (0);
	}
	free_double_tab(values);
	return (1);
}

int		parse_settings(t_game_file *parsed_file, int fd)
{
	char	*line;
	int		ret_gnl;

	ret_gnl = 1;
	while (ret_gnl && !parsed_file->settings_complete)
	{
		ret_gnl = get_next_line(fd, &line);
		if (ret_gnl == -1)
			return (0);
		if (!line_is_whitespace(line))
		{
			if (!parse_settings_suite(parsed_file, line))
				return (0);
			check_missing_settings(parsed_file);
		}
		else
			free(line);
	}
	return (1);
}
