/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_struct.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: louise <lsoulier@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/18 22:04:58 by louise            #+#    #+#             */
/*   Updated: 2020/10/19 22:13:33 by louise           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"
#include "libft.h"

void		init_point(t_point *point)
{
	point->x = 0;
	point->y = 0;
}

void		init_dimension(t_dimension *dimension)
{
	dimension->width = 0;
	dimension->height = 0;
}

void		init_file(t_file *file)
{
	file->fullname = NULL;
	file->ext = NULL;
	file->filename = NULL;
	file->path = NULL;
	file->fd = 0;
}

void		init_color(t_color *color)
{
	color->r = 0;
	color->g = 0;
	color->b = 0;
}