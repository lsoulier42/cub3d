/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render_map.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: louise <lsoulier@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/05 17:48:24 by louise            #+#    #+#             */
/*   Updated: 2020/11/14 17:25:07 by user42           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "cub3d.h"

int		minimap_colors(char map_elem)
{
	int color;

	color = 0;
	if (map_elem == EMPTY + '0')
		color = color_trgb(WHITE);
	else if (map_elem == WALL + '0')
		color = color_trgb(BLUE);
	else if (map_elem == SPRITE + '0')
		color = color_trgb(GREEN);
	return (color);
}

void	fill_map(t_mlx_vars *vars, t_image_data *minimap)
{
	int			i;
	int			j;
	t_dimension	tile;
	t_point		location;
	char		**map;

	i = -1;
	map = vars->parsed_file->map;
	set_dimension(&tile, vars->cell_size, vars->cell_size);
	while (map[++i])
	{
		j = -1;
		while (map[i][++j])
		{
			set_point(&location,
				j * vars->cell_size,
				i * vars->cell_size);
			draw_rect(minimap, location, tile, minimap_colors(map[i][j]));
		}
	}
}

void	fill_ray(t_mlx_vars *vars, t_image_data *minimap, t_ray *rays)
{
	int			i;
	t_point		minimap_pos;
	t_point		minimap_wall;
	t_dimension	win_res;

	i = -1;
	win_res = vars->parsed_file->win_res;
	set_point(&minimap_pos,
		vars->player->current_pos.x,
		vars->player->current_pos.y);
	while (++i < win_res.width)
	{
		set_point(&minimap_wall,
			rays[i].wall_hit.x,
			rays[i].wall_hit.y);
		draw_line(minimap, minimap_pos, minimap_wall, color_trgb(YELLOW));
	}
}

void	render_minimap(t_mlx_vars *vars)
{
	fill_map(vars, vars->minimap);
	fill_player(vars, vars->minimap);
	fill_ray(vars, vars->minimap, vars->rays);
}

void	fill_player(t_mlx_vars *vars, t_image_data *minimap)
{
	t_point minimap_pos;

	set_point(&minimap_pos,
		vars->player->current_pos.x,
		vars->player->current_pos.y);
	draw_circle(minimap, minimap_pos, vars->player->size, color_trgb(RED));
}
