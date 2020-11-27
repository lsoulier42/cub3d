/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   texture.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lsoulier <lsoulier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/15 17:59:34 by lsoulier          #+#    #+#             */
/*   Updated: 2020/11/27 03:09:40 by user42           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int		get_texture_offset_x(t_point wall_hit, int was_hit_vertical,
	int text_width, int cell_size)
{
	int	offset_x;

	if (was_hit_vertical)
		offset_x = fmod(wall_hit.y, cell_size)
			* (text_width / cell_size);
	else
		offset_x = fmod(wall_hit.x, cell_size)
			* (text_width / cell_size);
	return (offset_x);
}

int		get_texture_offset_y(double current_y,
	double wall_height, int win_height, int text_height)
{
	int offset_y;

	offset_y = (int)(current_y + (wall_height / 2.0)
		- (win_height / 2.0))
		* (text_height / wall_height);
	if (offset_y < 0)
		offset_y = 0;
	return (offset_y);
}

void	set_wall_limits(t_dimension win_res, double wall_height,
	int *wall_top_pixel, int *wall_bottom_pixel)
{
	*wall_top_pixel = (win_res.height / 2.0) - (wall_height / 2);
	if (*wall_top_pixel < 0)
		*wall_top_pixel = 0;
	*wall_bottom_pixel = (win_res.height / 2.0) + (wall_height / 2);
	if (*wall_bottom_pixel > win_res.height)
		*wall_bottom_pixel = win_res.height;
}

void	set_line_texture(t_mlx_vars *vars, t_texture_data *text,
	double wall_height, int ray_index)
{
	t_point	texture_offset;
	int		y;
	int		wall_top_pixel;
	int		wall_bottom_pixel;
	int		color;

	set_wall_limits(vars->parsed_file.win_res, wall_height,
		&wall_top_pixel, &wall_bottom_pixel);
	y = wall_top_pixel - 1;
	texture_offset.x = get_texture_offset_x(vars->rays[ray_index].wall_hit,
		vars->rays[ray_index].was_hit_vertical, text->width, vars->cell_size);
	while (++y < wall_bottom_pixel)
	{
		texture_offset.y = get_texture_offset_y(y, wall_height,
			vars->parsed_file.win_res.height, text->height);
		color = get_texture_color(text, texture_offset.x, texture_offset.y);
		my_mlx_pixel_put(&vars->view, ray_index, y, color);
	}
}

void	map_texture(t_mlx_vars *vars, double wall_height,
	int ray_index)
{
	if (vars->rays[ray_index].was_hit_south)
		set_line_texture(vars, &vars->south_text, wall_height, ray_index);
	else if (vars->rays[ray_index].was_hit_north)
		set_line_texture(vars, &vars->north_text, wall_height, ray_index);
	else if (vars->rays[ray_index].was_hit_west)
		set_line_texture(vars, &vars->west_text, wall_height, ray_index);
	else if (vars->rays[ray_index].was_hit_east)
		set_line_texture(vars, &vars->east_text, wall_height, ray_index);
}
