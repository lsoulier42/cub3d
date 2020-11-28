/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   constants.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lsoulier <lsoulier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/20 16:23:25 by lsoulier          #+#    #+#             */
/*   Updated: 2020/11/28 23:06:00 by user42           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CONSTANTS_H
# define CONSTANTS_H
# define MY_SCREEN_WIDTH 1920
# define MY_INCREMENT_SPEED 0.3
# define MY_INCREMENT_ROTATION 2.0
# define FOV_ANGLE 60
# define ESCAPE 65307
# define W_KEY 119
# define S_KEY 115
# define A_KEY 97
# define D_KEY 100
# define ARROW_LEFT 65361
# define ARROW_UP 65362
# define ARROW_RIGHT 65363
# define ARROW_DOWN 65364
# ifndef PROJECT_NAME
#  define PROJECT_NAME "Cub3D"
# endif

typedef enum	e_const_error
{
	PARSING_ERROR,
	CUB_FILE_ERROR,
	ARG_ERROR,
	MLX_INIT_ERROR,
	MLX_WINDOW_ERROR,
	IMAGE_ERROR,
	TEXTURE_ERROR,
	FORMAT_RESOLUTION_ERROR,
	COLOR_SETTING_ERROR,
	MAP_NOT_CLOSED_ERROR,
	MISSING_SETTINGS_ERROR,
	SETTINGS_ALREADY_COMPLETE,
	COLOR_ALREADY_SET_ERROR,
	TEXTURE_NOT_FOUND,
	ALLOCATION_ERROR,
	MAP_EMPTY_ERROR,
	INVALID_PLAYER_START,
	SETTING_INVALID,
	TEXTURE_ALREADY_SET_ERROR,
	RESOLUTION_ALREADY_SET,
	UNKNOWN_ELEMENT_ERROR
}				t_const_error;
#endif
