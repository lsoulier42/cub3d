/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   distance_utils.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: louise <lsoulier@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/09 12:12:08 by louise            #+#    #+#             */
/*   Updated: 2020/11/09 12:16:52 by louise           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "cub3d.h"

int distance_points(t_point start, t_point end)
{
	int distance;
	int dx;
	int dy;

	dx = end.x - start.x;
	dy = end.y - start.y;
	distance = sqrt(pow(dy, 2) + pow(dx, 2));
	return (distance);
}
