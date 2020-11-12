/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render_map.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: louise <lsoulier@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/05 17:48:24 by louise            #+#    #+#             */
/*   Updated: 2020/11/12 22:39:19 by user42           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "cub3d.h"

int		tile_color(char map_elem)
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

void	fill_map(t_image_data *map_img, char **map_array, int tile_size)
{
	int			i;
	int			j;
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

void	render_ray(t_mlx_vars *vars, t_ray *rays)
{
	int		i;
	t_point	minimap_pos;
	t_point	minimap_wall;

	i = -1;
	set_point(&minimap_pos, vars->player.current_pos.x * MINIMAP_SCALE,
		vars->player.current_pos.y * MINIMAP_SCALE);
	while (++i < vars->win_res.width)
	{
		set_point(&minimap_wall, rays[i].wall_hit.x * MINIMAP_SCALE,
			rays[i].wall_hit.y * MINIMAP_SCALE);
		draw_line(&vars->map_img, minimap_pos,
			minimap_wall, color_trgb(YELLOW));
	}
}

void	print_minimap(t_mlx_vars *vars, t_ray *rays)
{
	fill_map(&vars->map_img, vars->map, MINIMAP_SCALE * vars->tile_size);
	print_player(vars, vars->player);
	render_ray(vars, rays);
	mlx_put_image_to_window(vars->mlx, vars->win, vars->map_img.img, 0, 0);
}

int		is_wall(t_mlx_vars *vars, double x, double y)
{
	int index_x;
	int index_y;

	index_x = floor(x / vars->tile_size);
	index_y = floor(y / vars->tile_size);
	if (index_x < 0 || index_y < 0
		|| index_x >= vars->map_res.width || index_y >= vars->map_res.height)
		return (1);
	else
		return (vars->map[index_y][index_x] == '1');
}
