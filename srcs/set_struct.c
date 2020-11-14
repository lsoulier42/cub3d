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
#include "libft.h"

void	set_dimension(t_dimension *dimension, double width, double height)
{
	dimension->width = width;
	dimension->height = height;
}

void	set_point(t_point *point, double x, double y)
{
	point->x = x;
	point->y = y;
}
