/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   angle_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: louise <lsoulier@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/09 12:27:31 by louise            #+#    #+#             */
/*   Updated: 2020/11/13 01:06:13 by user42           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

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
