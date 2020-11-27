/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing_utils2.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lsoulier <lsoulier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/23 02:27:01 by lsoulier          #+#    #+#             */
/*   Updated: 2020/11/23 02:27:49 by user42           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parsing.h"

int		line_is_whitespace(char *str)
{
	int	i;

	i = -1;
	if (!str)
		return (0);
	while (str[++i])
		if (!ft_isspace(str[i]))
			return (0);
	return (1);
}

char	*trim_white_lines(int fd)
{
	int		ret_gnl;
	char	*line;

	ret_gnl = 1;
	while (ret_gnl)
	{
		ret_gnl = get_next_line(fd, &line);
		if (ret_gnl == -1)
			return (NULL);
		if (line_is_whitespace(line))
		{
			free(line);
			line = NULL;
		}
		else
			break ;
	}
	return (line);
}

char	*trim_spaces(char *str)
{
	int		new_size;
	int		i;
	char	*new_str;

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
