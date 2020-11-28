/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   texture.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lsoulier <lsoulier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/15 17:59:34 by lsoulier          #+#    #+#             */
/*   Updated: 2020/11/28 22:26:05 by user42           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	set_texture_limits(t_dimension win_res,
	float texture_height_in_screen, int *texture_top_pixel,
	int *texture_bottom_pixel)
{
	*texture_top_pixel = (win_res.height / 2.0)
		- (texture_height_in_screen / 2);
	if (*texture_top_pixel < 0)
		*texture_top_pixel = 0;
	*texture_bottom_pixel = (win_res.height / 2.0)
		+ (texture_height_in_screen / 2);
	if (*texture_bottom_pixel > win_res.height)
		*texture_bottom_pixel = win_res.height;
}

void	set_line_texture(t_mlx_vars *vars, t_texture_data *text,
	float wall_height, int ray_index)
{
	t_point	texture_offset;
	int		y;
	int		wall_top_pixel;
	int		wall_bottom_pixel;
	int		color;

	set_texture_limits(vars->parsed_file.win_res, wall_height,
		&wall_top_pixel, &wall_bottom_pixel);
	y = wall_top_pixel - 1;
	texture_offset.x = get_texture_offset_x(vars->rays[ray_index].wall_hit,
		vars->rays[ray_index].was_hit_vertical, text->width);
	while (++y < wall_bottom_pixel)
	{
		texture_offset.y = get_texture_offset_y(y, wall_height,
			vars->parsed_file.win_res.height, text->height);
		color = get_texture_color(text, texture_offset.x, texture_offset.y);
		my_mlx_pixel_put(&vars->view, ray_index, y, color);
	}
}

void	map_texture(t_mlx_vars *vars, float wall_height,
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
