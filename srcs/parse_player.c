/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing_player.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lsoulier <lsoulier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/22 13:56:44 by lsoulier          #+#    #+#             */
/*   Updated: 2020/11/27 19:29:45 by user42           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parsing.h"

int	parse_player_star(char **map, t_point *player_start,
	char *player_start_card)
{
	int x;
	int y;
	int nb_start;

	y = -1;
	nb_start = 0;
	while (map[++y])
	{
		x = -1;
		while (map[y] && map[y][++x])
		{
			if (ft_strchr(CARD_CHARSET, map[y][x]) != NULL)
			{
				set_point(player_start, x, y);
				nb_start++;
			}
		}
	}
	*player_start_card = map[(int)player_start->y][(int)player_start->x];
	if (nb_start != 1)
	{
		error_msg_parsing(INVALID_PLAYER_START);
		return (0);
	}
	return (1);
}
