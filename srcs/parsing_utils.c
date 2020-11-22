/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lsoulier <lsoulier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/22 13:35:26 by lsoulier          #+#    #+#             */
/*   Updated: 2020/11/22 14:12:52 by user42           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parsing.h"

int		parse_settings(t_game_file *parsed_file, char *line)
{
	if (!parse_resolution(parsed_file, line))
		return (0);
	if (!parse_textures(parsed_file, line))
		return (0);
	if (!parse_colors(parsed_file, line))
		return (0);
	return (1);
}

char	*trim_spaces(char *str)
{
	int new_size;
	int i;
	char *new_str;

	new_size = 0;
	i = -1;
	while (str[++i])
		if (str[i] != ' ')
			new_size++;
	new_str = (char*)malloc(sizeof(char) * (new_size + 1));
	if (!new_str)
		return (NULL);
	i = 0;
	while (*str)
	{
		if (*str != ' ')
		{
			new_str[i] = *str;
			i++;
		}
		str++;
	}
	new_str[i] = '\0';
	return (new_str);
}

char	**realloc_map(char **data, int prev_size, int new_size)
{
	char	**new_data;
	int		i;

	i = -1;
	new_data = malloc(sizeof(char*) * new_size);
	if (!new_data)
		return (NULL);
	while (++i < prev_size)
		new_data[i] = data[i];
	if (data)
		free(data);
	return (new_data);
}

