/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing_player.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lsoulier <lsoulier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/22 13:56:44 by lsoulier          #+#    #+#             */
/*   Updated: 2020/11/22 13:57:38 by user42           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parsing.h"

int	parse_player_start(t_game_file *parsed_file)
{
	int		x;
	int		y;
	char	*row;
	int		found;

	y = -1;
	row = *parsed_file->map;
	found = 0;
	while (!found && row)
	{
		x = -1;
		row = parsed_file->map[++y];
		while (!found && row[++x])
			if (ft_strchr(CARD_CHARSET, row[x]) != NULL)
				found = 1;
	}
	if (!found)
	{
		error_msg_parsing(NO_PLAYER_START_ERROR);
		return (0);
	}
	set_point(&(parsed_file->player_start), x, y);
	parsed_file->player_start_card = parsed_file->map[y][x];
	parsed_file->map[y][x] = '0';
	return (1);
}
