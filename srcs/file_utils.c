/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cubmap_utils.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: louise <lsoulier@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/18 19:16:46 by louise            #+#    #+#             */
/*   Updated: 2020/11/10 01:25:51 by louise           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"
#include "libft.h"

int		check_file(char *path)
{
	int fd;

	fd = 0;
	if (ft_strncmp(ft_strrev(path), "buc.", 4) != 0)
		return (-1);
	fd = open(path, O_RDONLY);
	if (fd <= 0)
		return (-1);
	else
		return (fd);
}

void	close_game_files(t_game *parsed_map)
{
	int i;

	i = -1;
	while (++i < parsed_map->map_res.height)
		free(parsed_map->map[i]);
	free(parsed_map->map);
	free(parsed_map->no_text);
	free(parsed_map->so_text);
	free(parsed_map->we_text);
	free(parsed_map->ea_text);
	free(parsed_map->sprite_text);
	free(parsed_map);
}
