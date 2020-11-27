/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lsoulier <lsoulier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/14 01:53:44 by lsoulier          #+#    #+#             */
/*   Updated: 2020/11/27 02:41:28 by user42           ###   ########.fr       */
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
	else if (error_type == NO_PLAYER_START_ERROR)
		ft_putstr("Player start hasn't been found.\n");
	else if (error_type == MISSING_SETTINGS_ERROR)
		ft_putstr("One of the settings is missing.\n");
	else if (error_type == COLOR_ALREADY_SET_ERROR)
		ft_putstr("One color has already been set for this background.\n");
	else if (error_type == SETTINGS_ALREADY_COMPLETE)
		ft_putstr("All settings are already complete.\n");
	else
		ft_putstr("Unknown parsing error.\n");
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
