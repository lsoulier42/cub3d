/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: louise <lsoulier@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/18 14:36:08 by louise            #+#    #+#             */
/*   Updated: 2020/10/19 23:12:51 by louise           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"
#include "libft.h"

void test_parsed_map(t_game *parsed_map)
{
	int i;
	t_color floor;
	t_color ceiling;

	i = -1;
	floor = parsed_map->floor_color;
	ceiling = parsed_map->ceiling_color;
	printf("Resolution fenetre largeur: %d\n", parsed_map->window_res.width);
	printf("Resolution fenetre hauteur: %d\n", parsed_map->window_res.height);
	printf("Resolution map largeur: %d\n", parsed_map->map_res.width);
	printf("Resolution map hauteur: %d\n", parsed_map->map_res.height);
	printf("Texture mur nord: %s\n", parsed_map->no_text.fullname);
	printf("Texture mur sud: %s\n", parsed_map->so_text.fullname);
	printf("Texture mur ouest: %s\n", parsed_map->we_text.fullname);
	printf("Texture mur est: %s\n", parsed_map->ea_text.fullname);
	printf("Texture sprite: %s\n", parsed_map->sprite_text.fullname);
	printf("Couleur du sol: R:%d, G:%d, B:%d\n", floor.r, floor.g, floor.b);
	printf("Couleur du plafond: R:%d, G:%d, B:%d\n", ceiling.r, ceiling.g, ceiling.b);
	printf("La map : \n");
	while (parsed_map->map[++i])
		printf("%s\n", parsed_map->map[i]);
}

int main(int argc, char **argv)
{
	t_game	*parsed_map;
	t_file	cubmap;

	if (argc >= 2 && argc <= 3)
	{
		if (!(check_file(argv[1], &cubmap)))
			return (0);
		if (ft_strncmp("cub", cubmap.ext, 3) != 0)
			return (destroy_file(cubmap));
		if (!(parsed_map = parse_file(cubmap)))
			return (destroy_file(cubmap));
		test_parsed_map(parsed_map);

		//suite
		close(cubmap.fd);
		free(parsed_map);
	}
	return (0);
}