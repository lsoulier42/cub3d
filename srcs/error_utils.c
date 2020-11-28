/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lsoulier <lsoulier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/14 01:53:44 by lsoulier          #+#    #+#             */
/*   Updated: 2020/11/28 20:36:25 by user42           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	error_msg(int error_type)
{
	if (error_type == PARSING_ERROR)
		ft_putstr("Parsing .cub file hasn't gone well.\n");
	else if (error_type == CUB_FILE_ERROR)
		ft_putstr("Error\nError during loading of .cub file.\n");
	else if (error_type == ARG_ERROR)
		ft_putstr("Error\nInvalid number of arguments.\n");
	else if (error_type == MLX_INIT_ERROR)
		ft_putstr("Error\nError during initialization of minilibX.\n");
	else if (error_type == MLX_WINDOW_ERROR)
		ft_putstr("Error\nCreating window error.\n");
	else if (error_type == IMAGE_ERROR)
		ft_putstr("CError\nreating image error.\n");
	else if (error_type == ALLOCATION_ERROR)
		ft_putstr("Error\n Allocating memory failed.\n");
	else if (error_type == TEXTURE_ERROR)
		ft_putstr("Error\nLoading texture error.\n");
	else if (error_type == UNKNOWN_ELEMENT_ERROR)
		ft_putstr("Error\nUnknown element found in map.\n");
	else
		ft_putstr("Error\nUnknown error.\n");
}

void	error_msg_parsing(int error_type)
{
	ft_putstr("Error\n");
	if (error_type == FORMAT_RESOLUTION_ERROR)
		ft_putstr("Invalid resolution size.\n");
	else if (error_type == COLOR_SETTING_ERROR)
		ft_putstr("Invalid color setting.\n");
	else if (error_type == TEXTURE_NOT_FOUND)
		ft_putstr("Texture file not found.\n");
	else if (error_type == MAP_NOT_CLOSED_ERROR)
		ft_putstr("Invalid map : map not closed with walls.\n");
	else if (error_type == INVALID_PLAYER_START)
		ft_putstr("Player start has 0 or more than 1 positions.\n");
	else if (error_type == MISSING_SETTINGS_ERROR)
		ft_putstr("One of the settings is missing.\n");
	else if (error_type == COLOR_ALREADY_SET_ERROR)
		ft_putstr("One color has already been set for this background.\n");
	else if (error_type == SETTINGS_ALREADY_COMPLETE)
		ft_putstr("All settings are already complete.\n");
	else if (error_type == MAP_EMPTY_ERROR)
		ft_putstr("Map is empty.\n");
	else if (error_type == SETTING_INVALID)
		ft_putstr("Invalid setting format.\n");
	else if (error_type == TEXTURE_ALREADY_SET_ERROR)
		ft_putstr("One texture has already been set for this side.\n");
	else if (error_type == RESOLUTION_ALREADY_SET)
		ft_putstr("Resolution has already been set.\n");
}

void	error_msg_texture(char *filepath)
{
	ft_putstr("This texture file was involved in the error : ");
	if (filepath)
		ft_putstr(filepath);
	else
		ft_putstr("unknown filepath");
	ft_putstr("\n");
}
