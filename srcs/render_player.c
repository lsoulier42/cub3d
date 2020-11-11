/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pixel.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: louise <lsoulier@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/02 17:51:12 by louise            #+#    #+#             */
/*   Updated: 2020/11/10 02:40:15 by louise           ###   ########.fr       */
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

int is_wall(char **map, int x, int y, int tile_size)
{
	int index_x;
	int index_y;

	index_x = floor(x / tile_size);
	index_y = floor(y / tile_size);
	return (map[index_y][index_x] == '1');
}

void find_horizontal_intersection(t_ray *ray, t_point player_pos, char **map)
{
	t_point first_intersection;
	t_point next_intersection;
	int xstep;
	int ystep;
	int tile_size;

	tile_size = ray->tile_size;
	first_intersection.y = (player_pos.y * tile_size) / tile_size;
	first_intersection.x = player_pos.x + ((player_pos.y - first_intersection.y) / tan(ray->ray_angle));
	ystep = tile_size;
	xstep = ystep / tan(ray->ray_angle);
	next_intersection = first_intersection;
	while (!is_wall(map, next_intersection.x, next_intersection.y, tile_size))
	{
		next_intersection.x += xstep;
		next_intersection.y += ystep;
	}
	ray->horizontal_intersection = next_intersection;
}

void find_vertical_intersection(t_ray *ray, t_point player_pos, char **map)
{
	t_point first_intersection;
	t_point next_intersection;
	int xstep;
	int ystep;
	int tile_size;

	tile_size = ray->tile_size;
	first_intersection.x = (player_pos.x * tile_size) / tile_size;
	first_intersection.y = player_pos.y + ((player_pos.x - first_intersection.x) * tan(ray->ray_angle));
	xstep = tile_size;
	ystep = xstep * tan(ray->ray_angle);
	next_intersection = first_intersection;
	while (!is_wall(map, next_intersection.x, next_intersection.y, tile_size))
	{
		next_intersection.x += xstep;
		next_intersection.y += ystep;
	}
	ray->vertical_intersection = next_intersection;
}

void 	cast_ray(t_ray *ray, t_point player_pos, char **map, int column_index)
{
	int horizontal_length;
	int vertical_length;

	find_horizontal_intersection(ray, player_pos, map);
	find_vertical_intersection(ray, player_pos, map);
	horizontal_length = distance_points(player_pos, ray->horizontal_intersection);
	vertical_length = distance_points(player_pos, ray->vertical_intersection);
	ray->length = vertical_length > horizontal_length ? horizontal_length : vertical_length;
}

void 	init_ray

t_ray    *cast_all_rays(t_player player, char **map, int nb_column, int tile_size)
{
    int     column_index;
    double  ray_angle;
    int     i;
    t_ray   *rays;

    column_index = 0;
    i = -1;
    ray_angle = player.rotation_angle - (FOV_ANGLE / 2);
    rays = (t_ray*)malloc(sizeof(t_ray) * nb_column);
    if (!rays)
    	return (NULL);
    while (++i < nb_column)
    {
        rays[i].ray_angle = normalize_angle(ray_angle);
        set_point(&rays[i].horizontal_intersection, 0 , 0);
		set_point(&rays[i].vertical_intersection, 0 , 0);
        rays[i].length = 0;
		rays[i].tile_size = tile_size;
        cast_ray(rays + i, player.current_pos, map, column_index);
        ray_angle += FOV_ANGLE / nb_column;
        column_index++;
    }
    return (rays);
}

int update_hook(t_mlx_vars *vars)
{
	int             move_step;
	int             next_x;
	int             next_y;
	t_image_data    view;
	t_ray			*rays;

    my_mlx_new_image(vars->mlx, &view, vars->win_res.width, vars->win_res.height);
    vars->player.rotation_angle += vars->player.turn_direction * vars->player.rotation_speed;
   	move_step = vars->player.walk_direction * vars->player.move_speed;
	next_x = vars->player.current_pos.x + (cos(vars->player.rotation_angle) * move_step);
	next_y = vars->player.current_pos.y + (sin(vars->player.rotation_angle) * move_step);
	if (!is_wall(vars->map, next_x, next_y, vars->tile_size))
	{
        vars->player.current_pos.x = next_x;
        vars->player.current_pos.y = next_y;
    }
    //fill_map(&vars->map_img, vars->map, vars->tile_size);
    //print_player(vars, vars->player);
    rays = cast_all_rays(vars->player, vars->map, vars->win_res.width, vars->tile_size);
	if (rays == NULL)
		return (0);
	//mlx_put_image_to_window(vars->mlx, vars->win, vars->map_img.img, 0, 0);
	free(rays);
	return (1);
}