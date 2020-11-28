/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   textures_utils.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lsoulier <lsoulier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/29 00:23:25 by lsoulier          #+#    #+#             */
/*   Updated: 2020/11/29 00:23:59 by user42           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int		get_texture_offset_x(t_point wall_hit, int was_hit_vertical,
								int text_width)
{
	int	offset_x;

	if (was_hit_vertical)
		offset_x = fmod(wall_hit.y, 1) * text_width;
	else
		offset_x = fmod(wall_hit.x, 1) * text_width;
	return (offset_x);
}

int		get_texture_offset_y(float current_y,
	float wall_height, int win_height, int text_height)
{
	int offset_y;

	offset_y = (current_y + (wall_height / 2.0)
		- (win_height / 2.0))
		* (text_height / wall_height);
	if (offset_y < 0)
		offset_y = 0;
	return (offset_y);
}

int		get_texture_color(t_texture_data *img, int x, int y)
{
	char	*dst;

	if (y < 0)
		y = 0;
	if (x < 0)
		x = 0;
	if (y > img->height)
		y = img->height;
	if (x > img->width)
		x = img->width;
	dst = img->addr + (y * img->line_length + x * img->bits_per_pixel / 8);
	return (*(unsigned int*)dst);
}
