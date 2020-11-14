/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render_floor.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lsoulier <lsoulier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/14 14:57:59 by lsoulier          #+#    #+#             */
/*   Updated: 2020/11/14 15:06:37 by user42           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "cub3d.h"

void	render_background(t_mlx_vars *vars, t_image_data *view)
{
	t_point		ceiling_location;
	t_point		floor_location;
	t_dimension win_res;
	t_dimension	half_screen;

	win_res = vars->parsed_file->win_res;
	set_point(&ceiling_location, 0, 0);
	set_point(&floor_location, 0, (win_res.height / 2) - 1);
	set_dimension(&half_screen, win_res.width, win_res.height / 2);
	draw_rect(view, ceiling_location, half_screen,
		vars->parsed_file->ceiling_color);
	draw_rect(view, floor_location, half_screen,
		vars->parsed_file->floor_color);
}
