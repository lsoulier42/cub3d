/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render_ray.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: louise <lsoulier@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/05 18:20:24 by louise            #+#    #+#             */
/*   Updated: 2020/11/05 18:20:49 by louise           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"
#include "libft.h"

t_image_data create_vertical_ray(t_mlx_vars *vars)
{
	t_image_data vertical_line;
	int i;

	i = -1;
	vertical_line.img = mlx_new_image(vars->mlx, 1, WALL_SIZE);
	vertical_line.addr = mlx_get_data_addr(vertical_line.img, &(vertical_line.bits_per_pixel), &(vertical_line.line_length), &(vertical_line.endian));
	while (++i < WALL_SIZE)
		my_mlx_pixel_put(&vertical_line, 0, i, create_trgb(0, 255, 0, 0));
	return (vertical_line);
}

t_image_data create_horizontal_ray(t_mlx_vars *vars)
{
	t_image_data horizontal_line;
	int j;

	j = -1;
	horizontal_line.img = mlx_new_image(vars->mlx, WALL_SIZE, 1);
	horizontal_line.addr = mlx_get_data_addr(horizontal_line.img, &(horizontal_line.bits_per_pixel), &(horizontal_line.line_length), &(horizontal_line.endian));
	while (++j < WALL_SIZE)
		my_mlx_pixel_put(&horizontal_line, j, 0, create_trgb(0, 255, 0, 0));
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
			mlx_put_image_to_window(vars->mlx, vars->win, line.img, (current_pos.x * WALL_SIZE) + WALL_SIZE / 2, (current_pos.y - i) * WALL_SIZE);
	else if (vars->current_card == 'S')
		while (vars->map[vars->current_pos.y - --i][vars->current_pos.x] == '0')
			mlx_put_image_to_window(vars->mlx, vars->win, line.img, (current_pos.x * WALL_SIZE) + WALL_SIZE / 2, (current_pos.y - i) * WALL_SIZE);
	else if (vars->current_card == 'W')
		while (vars->map[vars->current_pos.y][vars->current_pos.x - ++i] == '0')
			mlx_put_image_to_window(vars->mlx, vars->win, line.img, (current_pos.x - i) * WALL_SIZE, (current_pos.y * WALL_SIZE) + WALL_SIZE / 2);
	else if (vars->current_card == 'E')
		while (vars->map[vars->current_pos.y][vars->current_pos.x - --i] == '0')
			mlx_put_image_to_window(vars->mlx, vars->win, line.img, (current_pos.x - i) * WALL_SIZE, (current_pos.y * WALL_SIZE) + WALL_SIZE / 2);
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
	empty.img = mlx_new_image(vars->mlx, WALL_SIZE, WALL_SIZE);
	draw_square(&empty, create_trgb(0, 255, 255, 255));
	if (previous_card == 'N')
		while (++i < previous_pos.y - vars->wall_touched.y)
			mlx_put_image_to_window(vars->mlx, vars->win, empty.img, vars->wall_touched.x * WALL_SIZE, (vars->wall_touched.y + i) * WALL_SIZE);
	else if (previous_card == 'S')
		while (++i < vars->wall_touched.y - previous_pos.y)
			mlx_put_image_to_window(vars->mlx, vars->win, empty.img, previous_pos.x * WALL_SIZE, (previous_pos.y + i) * WALL_SIZE);
	else if (previous_card == 'W')
		while (++i < previous_pos.x - vars->wall_touched.x)
			mlx_put_image_to_window(vars->mlx, vars->win, empty.img, (vars->wall_touched.x + i) * WALL_SIZE, vars->wall_touched.y * WALL_SIZE);
	else if (previous_card == 'E')
		while (++i < vars->wall_touched.x - previous_pos.x)
			mlx_put_image_to_window(vars->mlx, vars->win, empty.img, (previous_pos.x + i) * WALL_SIZE, previous_pos.y * WALL_SIZE);
}
