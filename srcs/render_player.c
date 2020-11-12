/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pixel.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: louise <lsoulier@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/02 17:51:12 by louise            #+#    #+#             */
/*   Updated: 2020/11/12 02:21:27 by user42           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"
#include "libft.h"

void print_player(t_mlx_vars *vars, t_player player)
{
	t_point	direction;

	direction.x = player.current_pos.x + cos(player.rotation_angle) * (player.size / 2);
	direction.y = player.current_pos.y + sin(player.rotation_angle) * (player.size / 2);
	draw_circle(&vars->map_img, player.current_pos, player.size / 2, color_trgb(RED));
	draw_line(&vars->map_img, player.current_pos, direction, color_trgb(RED));
}

int is_wall(t_mlx_vars *vars, int x, int y)
{
	int index_x;
	int index_y;

	index_x = floor(x / vars->tile_size);
	index_y = floor(y / vars->tile_size);
	if (index_x < 0 || index_y < 0 || index_x >= vars->map_res.width || index_y >= vars->map_res.height)
		return (1);
	else
		return (vars->map[index_y][index_x] == '1');
}

int update_hook(t_mlx_vars *vars)
{
	int             move_step;
	int             next_x;
	int             next_y;
	//t_image_data    view;
	t_ray			*rays;
	int				i = -1;

    //my_mlx_new_image(vars->mlx, &view, vars->win_res.width, vars->win_res.height);
    vars->player.rotation_angle += vars->player.turn_direction * vars->player.rotation_speed;
   	move_step = vars->player.walk_direction * vars->player.move_speed;
	next_x = vars->player.current_pos.x + (cos(vars->player.rotation_angle) * move_step);
	next_y = vars->player.current_pos.y + (sin(vars->player.rotation_angle) * move_step);
	if (!is_wall(vars, next_x, next_y))
	{
        vars->player.current_pos.x = next_x;
        vars->player.current_pos.y = next_y;
    }
    fill_map(&vars->map_img, vars->map, vars->tile_size);
    print_player(vars, vars->player);
    rays = cast_all_rays(vars);
	if (rays == NULL)
		return (0);
	while (++i < vars->win_res.width)
		draw_line(&vars->map_img, vars->player.current_pos, rays[i].wall_hit, color_trgb(YELLOW));
	mlx_put_image_to_window(vars->mlx, vars->win, vars->map_img.img, 0, 0);
	free(rays);
	return (1);
}