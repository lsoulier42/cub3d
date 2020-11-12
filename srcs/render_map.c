/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render_map.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: louise <lsoulier@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/05 17:48:24 by louise            #+#    #+#             */
/*   Updated: 2020/11/10 00:09:46 by louise           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "cub3d.h"

int 	tile_color(char map_elem)
{
	int color;

	color = 0;
	if (map_elem == EMPTY + '0')
		color = color_trgb(WHITE);
	else if (map_elem == WALL + '0')
		color = color_trgb(BLUE);
	else if (map_elem == SPRITE + '0')
		color = color_trgb(YELLOW);
	return (color);
}

void 	fill_map(t_image_data *map_img, char **map_array, int tile_size)
{
	int 		i;
	int 		j;
	t_dimension	tile;
	t_point		location;
	int			color;

	i = -1;
	set_dimension(&tile, tile_size, tile_size);
	while (map_array[++i])
	{
		j = -1;
		while (map_array[i][++j])
		{
			color = tile_color(map_array[i][j]);
			set_point(&location, j * tile_size, i * tile_size);
			draw_rect(map_img, location, tile, color);
		}

	}
}

void print_minimap(t_mlx_vars *vars, t_ray *rays)
{
	int i;

	i = -1;
	fill_map(&vars->map_img, vars->map, vars->tile_size);
	print_player(vars, vars->player);
	while (++i < vars->win_res.width)
		draw_line(&vars->map_img, vars->player.current_pos,
				  rays[i].wall_hit, color_trgb(YELLOW));
	mlx_put_image_to_window(vars->mlx, vars->win, vars->map_img.img, 0, 0);
}