/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   constants.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lsoulier <lsoulier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/20 16:23:25 by lsoulier          #+#    #+#             */
/*   Updated: 2020/11/24 18:31:59 by user42           ###   ########.fr       */
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
# define FOUR_K_RES_WIDTH 3840
# define FOUR_K_RES_HEIGHT 2160
# ifndef PROJECT_NAME
#  define PROJECT_NAME "Cub3D"
# endif
# define INTENSITY_FACTOR 0.5

typedef enum	e_arrow
{
	ARROW_LEFT = 65361,
	ARROW_UP,
	ARROW_RIGHT,
	ARROW_DOWN
}				t_arrow;

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
	NO_PLAYER_START_ERROR,
	MISSING_SETTINGS_ERROR,
	SETTINGS_ALREADY_COMPLETE,
	COLOR_ALREADY_SET_ERROR,
	TEXTURE_NOT_FOUND,
	ALLOCATION_ERROR
}				t_const_error;
#endif