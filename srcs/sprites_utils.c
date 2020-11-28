/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sprites_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lsoulier <lsoulier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/27 02:34:37 by lsoulier          #+#    #+#             */
/*   Updated: 2020/11/28 20:14:28 by user42           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	sort_sprites(t_sprite *sprites, int nb_sprites)
{
	t_sprite	tmp;
	int			i;
	int			j;

	i = -1;
	while (++i < nb_sprites - 1)
	{
		j = i;
		while (++j < nb_sprites)
		{
			if (sprites[i].distance < sprites[j].distance)
			{
				tmp = sprites[j];
				sprites[j] = sprites[i];
				sprites[i] = tmp;
				i = 0;
			}
		}
	}
}

void	get_sprites_positions(t_mlx_vars *vars)
{
	t_sprite_positions	data;
	int					i;

	i = -1;
	while (++i < vars->nb_sprites)
	{
		if (vars->sprites[i].is_visible)
		{
			data.sprite_index = i;
			data.sprite_height = (vars->distance_to_projection_plane
					/ (cos(vars->sprites[i].angle)
					* vars->sprites[i].distance)) * vars->cell_size;
			set_texture_limits(vars->parsed_file.win_res, data.sprite_height,
				&data.sprite_top_pixel, &data.sprite_bottom_pixel);
			data.first_x_position = vars->distance_to_projection_plane
				* tan(vars->sprites[i].angle)
				+ (vars->parsed_file.win_res.width / 2.0)
				- (data.sprite_height / 2);
			render_sprite(vars, data);
		}
	}
}

void	render_sprite(t_mlx_vars *vars, t_sprite_positions data)
{
	t_point	drawing;
	t_point	sprite_texture_offset;
	double	ray_distance;

	drawing.x = -1;
	while (data.first_x_position + drawing.x < 0)
		drawing.x++;
	while (++drawing.x < data.sprite_height)
	{
		ray_distance = vars->rays[(int)(data.first_x_position
			+ drawing.x)].distance;
		if (ray_distance > vars->sprites[data.sprite_index].distance
			&& data.first_x_position + drawing.x
			        < vars->parsed_file.win_res.width)
		{
			sprite_texture_offset.x = drawing.x *
				vars->sprites_text.width / data.sprite_height;
			drawing.y = data.sprite_top_pixel - 1;
			while (++drawing.y < data.sprite_bottom_pixel)
				draw_sprite(vars, data, drawing, sprite_texture_offset);
		}
	}
}

void	draw_sprite(t_mlx_vars *vars, t_sprite_positions data,
	t_point drawing, t_point sprite_texture_offset)
{
	int	color;
	int	transparency_color;

	transparency_color = get_texture_color(&vars->sprites_text, 0, 0);
	sprite_texture_offset.y = get_texture_offset_y(drawing.y,
		data.sprite_height, vars->parsed_file.win_res.height,
		vars->sprites_text.height);
	color = get_texture_color(&vars->sprites_text,
		sprite_texture_offset.x,
		sprite_texture_offset.y);
	if (color != transparency_color)
		my_mlx_pixel_put(&vars->view,
			data.first_x_position + drawing.x,
			drawing.y, color);
}
