/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   distance_utils.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: louise <lsoulier@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/09 12:12:08 by louise            #+#    #+#             */
/*   Updated: 2020/11/27 01:01:33 by user42           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

float	distance_points(t_point start, t_point end)
{
	float	distance;
	float	dx;
	float	dy;

	dx = end.x - start.x;
	dy = end.y - start.y;
	distance = sqrt(pow(dx, 2) + pow(dy, 2));
	return (distance);
}

float	degree_to_radian(float angle)
{
	float radian;

	radian = (M_PI * angle) / 180;
	return (radian);
}

float	normalize_angle(float angle)
{
	angle = fmod(angle, (2 * M_PI));
	if (angle < 0)
		angle += (2 * M_PI);
	return (angle);
}
