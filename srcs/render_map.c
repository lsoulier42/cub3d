/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render_map.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: louise <lsoulier@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/05 17:48:24 by louise            #+#    #+#             */
/*   Updated: 2020/11/09 14:36:36 by louise           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "cub3d.h"

void	set_map_elem(t_mlx_vars *vars, t_image_data elem[ELEM_TOTAL])
{
	int size;

	size = vars->tile_size;
	my_mlx_new_image(vars->mlx, &elem[EMPTY], size, size);
	my_mlx_new_image(vars->mlx, &elem[WALL], size, size);
	my_mlx_new_image(vars->mlx, &elem[SPRITE], size, size);
	draw_square(&elem[EMPTY], color_trgb(WHITE), size);
	draw_square(&elem[WALL], color_trgb(BLUE), size);
	draw_square(&elem[SPRITE], color_trgb(YELLOW), size);
}

void	print_map(t_mlx_vars *vars, char **map)
{
	t_image_data	elem[ELEM_TOTAL];
	int 			i;
	int 			j;
	int 			x;
	int 			y;

	i = -1;
	set_map_elem(vars, elem);
	while (map[++i])
	{
		j = -1;
		while (map[i][++j])
			if (map[i][j] >= '0' && map[i][j] < '0' + ELEM_TOTAL)
			{
				x = j * vars->tile_size;
				y = i * vars->tile_size;
				mlx_put_image_to_window(vars->mlx, vars->win,
					elem[map[i][j] - '0'].img, x, y);
			}
	}
}