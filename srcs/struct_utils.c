/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_struct.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: louise <lsoulier@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/20 18:02:33 by louise            #+#    #+#             */
/*   Updated: 2020/11/14 03:48:18 by user42           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	set_dimension(t_dimension *dimension, float width, float height)
{
	dimension->width = width;
	dimension->height = height;
}

void	set_point(t_point *point, float x, float y)
{
	point->x = x;
	point->y = y;
}
