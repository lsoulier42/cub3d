/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_circle.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: louise <lsoulier@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/08 22:28:40 by louise            #+#    #+#             */
/*   Updated: 2020/11/09 17:49:37 by louise           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "cub3d.h"

void circle_pixelset(t_image_data *map, t_point center, t_point coord, int color)
{
    my_mlx_pixel_put(map, center.x + coord.x, center.y + coord.y, color);
    my_mlx_pixel_put(map, center.x + coord.x, center.y + coord.y, color);
    my_mlx_pixel_put(map, center.x + coord.y, center.y + coord.x, color);
    my_mlx_pixel_put(map, center.x - coord.x, center.y + coord.y, color);
    my_mlx_pixel_put(map, center.x - coord.y, center.y + coord.x, color);
    my_mlx_pixel_put(map, center.x + coord.x, center.y - coord.y, color);
    my_mlx_pixel_put(map, center.x + coord.y, center.y - coord.x, color);
    my_mlx_pixel_put(map, center.x - coord.x, center.y - coord.y, color);
    my_mlx_pixel_put(map, center.x - coord.y, center.y - coord.x, color);
}

void draw_circle(t_image_data *map, t_point center, int ray, int color)
{
    t_point coord;
    int d;

    d = 3 - (2 * ray);
    set_point(&coord, 0, ray);
    while (coord.y >= coord.x) {
        circle_pixelset(map, center, coord, color);
        if (d < 0)
            d += coord.x * 4 + 6;
        else {
            d += (coord.x - coord.y) * 4 + 10;
            coord.y--;
        }
        coord.x++;
    }
}