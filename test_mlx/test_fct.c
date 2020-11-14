/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_fct.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: louise <lsoulier@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/22 18:37:15 by louise            #+#    #+#             */
/*   Updated: 2020/11/10 01:25:16 by louise           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"
#include "libft.h"

void test_parsed_map(t_game_file *parsed_file)
{
	int i;
	int floor;
	int ceiling;

	i = -1;
	floor = parsed_file->floor_color;
	ceiling = parsed_file->ceiling_color;
	printf("---------Test de parsing du fichier de la map---------\n");
	printf("Resolution fenetre largeur: %d - hauteur: %d\n", parsed_file->win_res.width, parsed_file->win_res.height);
	printf("Resolution map largeur: %d - hauteur: %d\n", parsed_file->map_res.width, parsed_file->map_res.height);
	printf("Position de depart du joueur: (x:%f, y: %f)\n", parsed_file->player_start.x, parsed_file->player_start.y);
	printf("Sens de depart: %c\n", parsed_file->player_start_card);
	printf("Texture mur nord: %s\n", parsed_file->no_text);
	printf("Texture mur sud: %s\n", parsed_file->so_text);
	printf("Texture mur ouest: %s\n", parsed_file->we_text);
	printf("Texture mur est: %s\n", parsed_file->ea_text);
	printf("Texture sprite: %s\n", parsed_file->sprite_text);
	printf("Couleur du sol: %d\n", floor);
	printf("Couleur du plafond: %d\n", ceiling);
	printf("La map : \n");
	if (parsed_file->map)
		while (parsed_file->map[++i])
			printf("|%s|\n", parsed_file->map[i]);
	else
		printf("Map invalid\n");
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