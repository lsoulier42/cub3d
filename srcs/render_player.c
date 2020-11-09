/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pixel.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: louise <lsoulier@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/02 17:51:12 by louise            #+#    #+#             */
/*   Updated: 2020/11/09 14:29:48 by louise           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"
#include "libft.h"

char change_card(int keycode)
{
	char new_card;

	new_card = 0;
	if (keycode == ARROW_UP)
		new_card = 'N';
	else if (keycode == ARROW_DOWN)
		new_card = 'S';
	else if (keycode == ARROW_LEFT)
		new_card = 'W';
	else if (keycode == ARROW_RIGHT)
		new_card = 'E';
	return (new_card);
}

int player_move(int keycode, t_mlx_vars *vars)
{
	int		collision;
	t_point	previous_pos;
	char	previous_card;

	collision = 0;
	previous_pos = vars->current_pos;
	previous_card = vars->current_card;
	vars->current_card = change_card(keycode);
	if (keycode == ARROW_UP && vars->map[vars->current_pos.y - 1][vars->current_pos.x] == '0')
		vars->current_pos.y--;
	else if (keycode == ARROW_DOWN && vars->map[vars->current_pos.y + 1][vars->current_pos.x] == '0')
		vars->current_pos.y++;
	else if (keycode == ARROW_LEFT && vars->map[vars->current_pos.y][vars->current_pos.x - 1] == '0')
		vars->current_pos.x--;
	else if (keycode == ARROW_RIGHT && vars->map[vars->current_pos.y][vars->current_pos.x + 1] == '0')
		vars->current_pos.x++;
	else
		collision = 1;
	if (!collision) {
		erase_previous_pos(vars, previous_pos);
	}
		print_player(vars, vars->current_pos);
		if (previous_card != vars->current_card)
			erase_previous_ray(vars, previous_pos, previous_card);
		vars->wall_touched = print_ray(vars, vars->current_pos);
	return (1);
}

void	print_player(t_mlx_vars *vars, t_point player_pos)
{
	void *img;
	int x;
	int y;

	//change_player_img(vars);
	img = vars->player_img.img;
	x = player_pos.x * vars->tile_size;
	y = player_pos.y * vars->tile_size;
	erase_previous_pos(vars, player_pos);
	mlx_put_image_to_window(vars->mlx, vars->win, img, x, y);
}

void erase_previous_pos(t_mlx_vars *vars, t_point player_pos)
{
	t_image_data empty;
	int x;
	int y;

	x = player_pos.x * vars->tile_size;
	y = player_pos.y * vars->tile_size;
	my_mlx_new_image(vars->mlx, &empty, vars->tile_size, vars->tile_size);
	draw_square(&empty, color_trgb(WHITE), vars->tile_size);
	mlx_put_image_to_window(vars->mlx, vars->win, empty.img, x, y);
}