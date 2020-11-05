/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_fct.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: louise <lsoulier@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/22 18:37:15 by louise            #+#    #+#             */
/*   Updated: 2020/10/22 18:37:37 by louise           ###   ########.fr       */
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
	printf("---------Test de parsing du fichier de la map---------\n");
	printf("Resolution fenetre largeur: %d - hauteur: %d\n", parsed_map->window_res.width, parsed_map->window_res.height);
	printf("Resolution map largeur: %d - hauteur: %d\n", parsed_map->map_res.width, parsed_map->map_res.height);
	printf("Position de depart du joueur: (x:%d, y: %d)\n", parsed_map->player_start.x, parsed_map->player_start.y);
	printf("Sens de depart: %c\n", parsed_map->player_start_card);
	printf("Texture mur nord: %s\n", parsed_map->no_text.fullname);
	printf("Texture mur sud: %s\n", parsed_map->so_text.fullname);
	printf("Texture mur ouest: %s\n", parsed_map->we_text.fullname);
	printf("Texture mur est: %s\n", parsed_map->ea_text.fullname);
	printf("Texture sprite: %s\n", parsed_map->sprite_text.fullname);
	printf("Couleur du sol: R:%d, G:%d, B:%d\n", floor.r, floor.g, floor.b);
	printf("Couleur du plafond: R:%d, G:%d, B:%d\n", ceiling.r, ceiling.g, ceiling.b);
	printf("La map : \n");
	if (parsed_map->map)
		while (parsed_map->map[++i])
			printf("|%s|\n", parsed_map->map[i]);
	else
		printf("Map invalid\n");
}

void test_opened_file(t_file file)
{
	printf("---------Test de lecture du fichier .cub---------\n");
	printf("Fullname: %s\n", file.fullname);
	printf("Filename: %s\n", file.filename);
	printf("Extension: %s\n", file.ext);
	printf("Path: %s\n", file.path);
	printf("File descriptor: %d\n", file.fd);
}

void debug_point(t_mlx_vars *vars, t_point point)
{
	char str[20];
	static int i = 0;

	ft_strcat(str, "point(");
	ft_strcat(str, ft_itoa(point.x));
	ft_strcat(str, ",");
	ft_strcat(str, ft_itoa(point.y));
	ft_strcat(str, ")");
	mlx_string_put(vars->mlx, vars->win, 10, 500 + i * 10, create_trgb(0, 255, 0, 0), str);
	i++;
}