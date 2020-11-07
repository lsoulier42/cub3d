/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render_map.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: louise <lsoulier@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/05 17:48:24 by louise            #+#    #+#             */
/*   Updated: 2020/11/07 15:33:44 by louise           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "cub3d.h"

void	set_map_elem(t_mlx_vars *vars, t_image_data elem[ELEM_TOTAL])
{
	char		*path;
	t_dimension	wall_dimension;

	path = "./img/wall.xpm";
	my_mlx_new_image(vars->mlx, &elem[EMPTY], WALL_SIZE, WALL_SIZE);
	elem[WALL].img = mlx_xpm_file_to_image(vars->mlx, path, &wall_dimension.width, &wall_dimension.height);
	my_mlx_new_image(vars->mlx, &elem[SPRITE], WALL_SIZE, WALL_SIZE);
	draw_square(&elem[EMPTY], color_trgb(WHITE));
	draw_square(&elem[SPRITE], color_trgb(YELLOW));
}

void	print_map(t_mlx_vars *vars, char **map)
{
	t_image_data	elem[ELEM_TOTAL];
	int 			i;
	int 			j;

	i = -1;
	set_map_elem(vars, elem);
	while (map[++i])
	{
		j = -1;
		while (map[i][++j])
			if (map[i][j] >= '0' && map[i][j] < '0' + ELEM_TOTAL)
				mlx_put_image_to_window(vars->mlx, vars->win, elem[map[i][j] - '0'].img, j * WALL_SIZE, i * WALL_SIZE);
	}
}