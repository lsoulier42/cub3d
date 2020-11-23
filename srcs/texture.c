/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   texture.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lsoulier <lsoulier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/15 17:59:34 by lsoulier          #+#    #+#             */
/*   Updated: 2020/11/22 22:56:15 by user42           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int		get_texture_color(t_texture_data *img, int x, int y)
{
	char	*dst;

	if (y < 0)
		y = 0;
	dst = img->addr + (y * img->line_length + x * img->bits_per_pixel / 8);
	return (*(unsigned int*)dst);
}

int		get_texture_offset_x(t_point wall_hit, int was_hit_vertical,
	int text_width)
{
	int	offset_x;

	if (was_hit_vertical)
		offset_x = fmod(wall_hit.y, CELL_SIZE)
			* (text_width / CELL_SIZE);
	else
		offset_x = fmod(wall_hit.x, CELL_SIZE)
			* (text_width / CELL_SIZE);
	return (offset_x);
}

void 	set_line_limits(t_dimension win_res, t_dimension elem_dimension,
	int *wall_top_pixel, int *wall_bottom_pixel)
{
	*wall_top_pixel = (win_res.height / 2) - (elem_dimension.height / 2);
	if (*wall_top_pixel < 0)
		*wall_top_pixel = 0;
	*wall_bottom_pixel = (win_res.height / 2) + (elem_dimension.height / 2);
	if (*wall_bottom_pixel > win_res.height)
		*wall_bottom_pixel = win_res.height;
}

void	set_line_texture(t_mlx_vars *vars, t_texture_data *text,
	t_dimension elem_dimension, int ray_index)
{
	t_point	texture_offset;
	int		y;
	int		wall_top_pixel;
	int		wall_bottom_pixel;
	int 	color;

	set_line_limits(vars->parsed_file.win_res, elem_dimension,
		&wall_top_pixel, &wall_bottom_pixel);
	y = wall_top_pixel - 1;
	texture_offset.x = get_texture_offset_x(vars->rays[ray_index].wall_hit,
		vars->rays[ray_index].was_hit_vertical, text->width);
	while (++y < wall_bottom_pixel)
	{
		texture_offset.y = (int)(y + (elem_dimension.height / 2)
			- (vars->parsed_file.win_res.height / 2))
			* (text->height / elem_dimension.height);
		if (text->img)
			color = get_texture_color(text, texture_offset.x, texture_offset.y);
		else
			color = text->default_color;
		my_mlx_pixel_put(&vars->view, ray_index, y, color);
	}
}

void	map_texture(t_mlx_vars *vars, t_dimension elem_dimension,
	int ray_index)
{
	if (vars->rays[ray_index].was_hit_south)
		set_line_texture(vars, &vars->south_text, elem_dimension, ray_index);
	else if (vars->rays[ray_index].was_hit_north)
		set_line_texture(vars, &vars->north_text, elem_dimension, ray_index);
	else if (vars->rays[ray_index].was_hit_west)
		set_line_texture(vars, &vars->west_text, elem_dimension, ray_index);
	else if (vars->rays[ray_index].was_hit_east)
		set_line_texture(vars, &vars->east_text, elem_dimension, ray_index);
}
