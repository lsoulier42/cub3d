/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   constants.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lsoulier <lsoulier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/20 16:23:25 by lsoulier          #+#    #+#             */
/*   Updated: 2020/11/22 02:55:42 by user42           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CONSTANTS_H
# define CONSTANTS_H

# define ESCAPE 65307
# define W_KEY 119
# define S_KEY 115
# define A_KEY 97
# define D_KEY 100
# define FOV_ANGLE 60
# define CELL_SIZE 16
# define FOUR_K_RES_WIDTH 3840
# define FOUR_K_RES_HEIGHT 2160

typedef enum	e_arrow
{
	ARROW_LEFT = 65361,
	ARROW_UP,
	ARROW_RIGHT,
	ARROW_DOWN
}				t_arrow;

typedef enum	e_map_elem
{
	EMPTY,
	WALL,
	SPRITE,
	ELEM_TOTAL
}				t_map_elem;

typedef enum	e_const_color
{
	BLACK,
	WHITE,
	RED,
	BLUE,
	YELLOW,
	GREEN,
	PURPLE,
	PINK,
	ORANGE,
	GRAY
}				t_const_color;

typedef enum	e_const_error
{
	EXT_ERROR,
	PARSING_ERROR,
	CUB_FILE_ERROR,
	ARG_ERROR,
	STRUCT_ERROR,
	MLX_INIT_ERROR,
	MLX_WINDOW_ERROR,
	IMAGE_ERROR,
	VARS_ALLOC_ERROR,
	PLAYER_ALLOC_ERROR,
	RAYS_ALLOC_ERROR,
	PARSED_FILE_ALLOC_ERROR,
	IMAGE_ALLOC_ERROR,
	TEXTURE_ERROR,
	TEXTURE_ALLOC_ERROR,
	TEXTURE_ADDR_ERROR,
	IMAGE_CREATION_ERROR,
	FORMAT_RESOLUTION_ERROR,
	COLOR_SETTING_ERROR,
	TEXTURE_EXT_ERROR,
	MAP_NOT_CLOSED_ERROR,
	MAP_TAB_ALLOCATION_ERROR,
	NO_PLAYER_START_ERROR,
	BACKGROUND_COLOR_ERROR
}				t_const_error;
#endif