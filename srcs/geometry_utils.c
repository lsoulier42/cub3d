/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   distance_utils.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: louise <lsoulier@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/09 12:12:08 by louise            #+#    #+#             */
/*   Updated: 2020/11/17 23:44:56 by user42           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "cub3d.h"

double	distance_points(t_point start, t_point end)
{
	double	distance;
	double	dx;
	double	dy;

	dx = end.x - start.x;
	dy = end.y - start.y;
	distance = sqrt(pow(dy, 2) + pow(dx, 2));
	return (distance);
}

double	degree_to_radian(double angle)
{
	double radian;

	radian = (M_PI * angle) / 180;
	return (radian);
}

double	normalize_angle(double angle)
{
	angle = fmod(angle, (2 * M_PI));
	if (angle < 0)
		angle += (2 * M_PI);
	return (angle);
}
