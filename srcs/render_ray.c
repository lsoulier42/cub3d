/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render_ray.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: louise <lsoulier@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/05 18:20:24 by louise            #+#    #+#             */
/*   Updated: 2020/11/09 14:33:58 by louise           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"
#include "libft.h"

t_image_data create_vertical_ray(t_mlx_vars *vars)
{
	t_image_data vertical_line;
	int i;

	i = -1;
	my_mlx_new_image(vars->mlx, &vertical_line, 1, vars->tile_size);
	while (++i < vars->tile_size)
		my_mlx_pixel_put(&vertical_line, 0, i, color_trgb(RED));
	return (vertical_line);
}

t_image_data create_horizontal_ray(t_mlx_vars *vars)
{
	t_image_data horizontal_line;
	int j;

	j = -1;
	my_mlx_new_image(vars->mlx, &horizontal_line, vars->tile_size, 1);
	while (++j < vars->tile_size)
		my_mlx_pixel_put(&horizontal_line, j, 0, color_trgb(RED));
	return (horizontal_line);
}

t_point print_ray(t_mlx_vars *vars, t_point current_pos)
{
	t_image_data	line;
	t_point			wall_touched;
	int				i;

	i = 0;
	set_point(&wall_touched, -1, -1);
	if (vars->current_card == 'N' || vars->current_card == 'S')
		line = create_vertical_ray(vars);
	else
		line = create_horizontal_ray(vars);
	if (vars->current_card == 'N')
		while (vars->map[vars->current_pos.y - ++i][vars->current_pos.x] == '0')
			mlx_put_image_to_window(vars->mlx, vars->win, line.img, (current_pos.x * vars->tile_size) + vars->tile_size / 2, (current_pos.y - i) * vars->tile_size);
	else if (vars->current_card == 'S')
		while (vars->map[vars->current_pos.y - --i][vars->current_pos.x] == '0')
			mlx_put_image_to_window(vars->mlx, vars->win, line.img, (current_pos.x * vars->tile_size) + vars->tile_size / 2, (current_pos.y - i) * vars->tile_size);
	else if (vars->current_card == 'W')
		while (vars->map[vars->current_pos.y][vars->current_pos.x - ++i] == '0')
			mlx_put_image_to_window(vars->mlx, vars->win, line.img, (current_pos.x - i) * vars->tile_size, (current_pos.y * vars->tile_size) + vars->tile_size / 2);
	else if (vars->current_card == 'E')
		while (vars->map[vars->current_pos.y][vars->current_pos.x - --i] == '0')
			mlx_put_image_to_window(vars->mlx, vars->win, line.img, (current_pos.x - i) * vars->tile_size, (current_pos.y * vars->tile_size) + vars->tile_size / 2);
	if (vars->current_card == 'N' || vars->current_card == 'S')
		set_point(&wall_touched, current_pos.x, current_pos.y - i);
	else
		set_point(&wall_touched, current_pos.x - i, current_pos.y);
	return (wall_touched);
}

void	erase_previous_ray(t_mlx_vars *vars, t_point previous_pos, char previous_card)
{
	int				i;
	t_image_data	empty;

	i = 0;
	my_mlx_new_image(vars->mlx, &empty, vars->tile_size, vars->tile_size);
	draw_square(&empty, color_trgb(WHITE), vars->tile_size);
	if (previous_card == 'N')
		while (++i < previous_pos.y - vars->wall_touched.y)
			mlx_put_image_to_window(vars->mlx, vars->win, empty.img, vars->wall_touched.x * vars->tile_size, (vars->wall_touched.y + i) * vars->tile_size);
	else if (previous_card == 'S')
		while (++i < vars->wall_touched.y - previous_pos.y)
			mlx_put_image_to_window(vars->mlx, vars->win, empty.img, previous_pos.x * vars->tile_size, (previous_pos.y + i) * vars->tile_size);
	else if (previous_card == 'W')
		while (++i < previous_pos.x - vars->wall_touched.x)
			mlx_put_image_to_window(vars->mlx, vars->win, empty.img, (vars->wall_touched.x + i) * vars->tile_size, vars->wall_touched.y * vars->tile_size);
	else if (previous_card == 'E')
		while (++i < vars->wall_touched.x - previous_pos.x)
			mlx_put_image_to_window(vars->mlx, vars->win, empty.img, (previous_pos.x + i) * vars->tile_size, previous_pos.y * vars->tile_size);
}
