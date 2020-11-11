/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   angle_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: louise <lsoulier@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/09 12:27:31 by louise            #+#    #+#             */
/*   Updated: 2020/11/09 12:35:41 by louise           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "cub3d.h"

double radian_to_degree(double angle)
{
	double degree;

	degree = (180 * angle) / M_PI;
	return (degree);
}

double degree_to_radian(double angle)
{
	double radian;

	radian = (M_PI * angle) / 180;
	return (radian);
}

double normalize_angle(double angle)
{
	angle = fmod(angle, (2 * M_PI));
	if (angle < 0)
		angle += (2 * M_PI);
	return (angle);
}
