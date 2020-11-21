/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   save_bmp.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lsoulier <lsoulier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/21 09:47:53 by lsoulier          #+#    #+#             */
/*   Updated: 2020/11/21 11:53:24 by user42           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "cub3d.h"

t_bmp_img	*init_img(int width, int height)
{
	t_bmp_img *new_img;
	new_img = (t_bmp_img*)malloc(sizeof(t_bmp_img));
	if (!new_img)
		return (NULL);
	new_img->width = width;
	new_img->height = height;
	new_img->color_buffer = NULL;
	return (new_img);
}

t_bmp_color	convert_trgb_to_bmp(t_image_data *img, int x, int y)
{
	t_bmp_color	pixel_color;
	int			color;
	char 		*dst;

	dst = img->addr + (y * img->line_length + x * (img->bits_per_pixel / 8));
	color = *(unsigned int*)dst;
	pixel_color.r = (color & 0xFFFF00) >> 16;
	pixel_color.g = (color & 0xFF00) >> 8;
	pixel_color.b = color & 0xFF;
	return (pixel_color);
}

t_bmp_color	*fill_color_buffer(t_image_data *first_frame, t_dimension img_res)
{
	t_bmp_color *color_buffer;
	t_bmp_color	bmp_color;
	int			x;
	int 		y;

	x = -1;
	color_buffer = (t_bmp_color*)ft_calloc(img_res.width
			* img_res.height, sizeof(t_bmp_color));
	if (!color_buffer)
		return (NULL);
	while (++x < img_res.width)
	{
		y = -1;
		while (++y < img_res.height)
		{
			bmp_color = convert_trgb_to_bmp(first_frame, x, y);
			color_buffer[((int)img_res.width * y) + x] = bmp_color;
		}
	}
	return (color_buffer);
}

int			save_bmp(t_image_data *first_frame, t_dimension img_res)
{
	t_bmp_img	*frame_bmp;

	frame_bmp = init_img(img_res.width, img_res.height);
	if (!first_frame)
		return (0);
	frame_bmp->color_buffer = fill_color_buffer(first_frame, img_res);
	if (!(frame_bmp->color_buffer))
		return (0);
	free(frame_bmp->color_buffer);
	free(frame_bmp);
	return (1);
}