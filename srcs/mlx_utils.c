/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mlx_utils.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: louise <lsoulier@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/05 17:46:02 by louise            #+#    #+#             */
/*   Updated: 2020/11/12 22:25:03 by user42           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "cub3d.h"

int		create_trgb(int t, int r, int g, int b)
{
	return (t << 24 | r << 16 | g << 8 | b);
}

int		color_trgb(int const_color)
{
	int color;

	color = 0;
	if (const_color == BLACK)
		color = create_trgb(0, 0, 0, 0);
	else if (const_color == WHITE)
		color = create_trgb(0, 255, 255, 255);
	else if (const_color == RED)
		color = create_trgb(0, 255, 0, 0);
	else if (const_color == BLUE)
		color = create_trgb(0, 0, 0, 255);
	else if (const_color == YELLOW)
		color = create_trgb(0, 255, 255, 0);
	else if (const_color == GREEN)
		color = create_trgb(0, 0, 255, 0);
	else if (const_color == PURPLE)
		color = create_trgb(0, 128, 0, 128);
	else if (const_color == PINK)
		color = create_trgb(0, 255, 192, 203);
	else if (const_color == ORANGE)
		color = create_trgb(0, 255, 168, 0);
	return (color);
}

void	my_mlx_pixel_put(t_image_data *img, int x, int y, int color)
{
	char	*dst;

	dst = img->addr + (y * img->line_length + x * (img->bits_per_pixel / 8));
	*(unsigned int*)dst = color;
}

void	get_sprite(t_image_data sprite_sheet,
	t_image_data *sprite, t_point sprite_location, int size)
{
	int		x;
	int		y;
	char	*dst;
	char	*src;

	x = -1;
	while (++x < size)
	{
		y = -1;
		while (++y < size)
		{
			src = sprite_sheet.addr
				+ (((int)sprite_location.y + y) * sprite_sheet.line_length
				+ ((int)sprite_location.x + x)
				* (sprite_sheet.bits_per_pixel / 8));
			dst = sprite->addr
				+ (y * sprite->line_length + x * (sprite->bits_per_pixel / 8));
			*(unsigned int*)dst = *(unsigned int*)src;
		}
	}
}

void	my_mlx_new_image(void *mlx_ptr, t_image_data *img,
	int width, int height)
{
	img->img = mlx_new_image(mlx_ptr, width, height);
	img->addr = mlx_get_data_addr(img->img,
		&(img->bits_per_pixel), &(img->line_length), &(img->endian));
}
