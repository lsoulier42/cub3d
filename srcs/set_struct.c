/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_struct.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: louise <lsoulier@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/20 18:02:33 by louise            #+#    #+#             */
/*   Updated: 2020/11/12 16:37:19 by user42           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"
#include "libft.h"

void	set_dimension(t_dimension *dimension, int width, int height)
{
	dimension->width = width;
	dimension->height = height;
}

void	set_point(t_point *point, double x, double y)
{
	point->x = x;
	point->y = y;
}

void	set_color(t_color *color, unsigned char r, unsigned char g,
				unsigned char b)
{
	color->r = r;
	color->g = g;
	color->b = b;
}
