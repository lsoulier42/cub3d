/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lsoulier <lsoulier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/22 13:35:26 by lsoulier          #+#    #+#             */
/*   Updated: 2020/11/28 13:01:00 by user42           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parsing.h"

void	free_double_tab(char **tab)
{
	int i;

	i = -1;
	while (tab[++i])
		free(tab[i]);
	free(tab);
}

int		nb_tab_values(char **values)
{
	int i;

	i = 0;
	while (values[i])
		i++;
	return (i);
}

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
	line = NULL;
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
