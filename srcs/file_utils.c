/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cubmap_utils.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: louise <lsoulier@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/18 19:16:46 by louise            #+#    #+#             */
/*   Updated: 2020/11/13 01:38:04 by user42           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"
#include "libft.h"

int		check_file(char *path)
{
	int		fd;
	char	*invert_ext;
	int		strcmp_ret;

	fd = 0;
	invert_ext = ft_strrev(path);
	strcmp_ret = ft_strncmp(invert_ext, "buc.", 4);
	free(invert_ext);
	if (strcmp_ret != 0)
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
