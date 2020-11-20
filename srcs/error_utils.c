/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lsoulier <lsoulier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/14 01:53:44 by lsoulier          #+#    #+#             */
/*   Updated: 2020/11/20 19:01:43 by user42           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "cub3d.h"

void	error_msg(int error_type)
{
	if (error_type == EXT_ERROR)
		ft_putstr("Invalid extension error.\n");
	else if (error_type == PARSING_ERROR)
		ft_putstr("Parsing .cub file hasn't gone well.\n");
	else if (error_type == CUB_FILE_ERROR)
		ft_putstr("Error\nError during loading of .cub file.\n");
	else if (error_type == ARG_ERROR)
		ft_putstr("Error\nInvalid number of arguments.\n");
	else if (error_type == MLX_INIT_ERROR)
		ft_putstr("Error during initialization of minilibX.\n");
	else if (error_type == MLX_WINDOW_ERROR)
		ft_putstr("Creating window error.\n");
	else if (error_type == IMAGE_ERROR)
		ft_putstr("Creating image error.\n");
	else if (error_type == IMAGE_CREATION_ERROR)
		ft_putstr("Creating mlx image object error.\n");
	else if (error_type == TEXTURE_ADDR_ERROR)
		ft_putstr("Getting address from texture file error.\n");
	else if (error_type == STRUCT_ERROR)
		ft_putstr("Loading structures error.\n");
	else if (error_type == TEXTURE_ERROR)
		ft_putstr("Loading texture error.\n");
	else
		ft_putstr("Unknown error.\n");
}

void 	error_msg_parsing(int error_type)
{
	ft_putstr("Error\n");
	if (error_type == FORMAT_RESOLUTION_ERROR)
		ft_putstr("Invalid resolution size.\n");
	else if (error_type == COLOR_SETTING_ERROR)
		ft_putstr("Invalid color setting.\n");
	else if (error_type == TEXTURE_EXT_ERROR)
		ft_putstr("Invalid texture extension.\n");
	else if (error_type == MAP_NOT_CLOSED_ERROR)
		ft_putstr("Invalid map : map not closed with walls.\n");
	else if (error_type == NO_PLAYER_START_ERROR)
		ft_putstr("Player start hasn't been found.\n");
	else
		ft_putstr("Unknown parsing error.\n");
}

void	error_msg_alloc(int error_type)
{
	ft_putstr("Error\n");
	ft_putstr("Allocating memory failed : ");
	if (error_type == VARS_ALLOC_ERROR)
		ft_putstr("storing general data structure.\n");
	else if (error_type == PLAYER_ALLOC_ERROR)
		ft_putstr("storing player data structure.\n");
	else if (error_type == RAYS_ALLOC_ERROR)
		ft_putstr("storing rays data structure.\n");
	else if (error_type == PARSED_FILE_ALLOC_ERROR)
		ft_putstr("storing .cub file data structure.\n");
	else if (error_type == IMAGE_ALLOC_ERROR)
		ft_putstr("storing mlx image object data structure.\n");
	else if (error_type == TEXTURE_ALLOC_ERROR)
		ft_putstr("storing texture image data structure.\n");
	else if (error_type == MAP_TAB_ALLOCATION_ERROR)
		ft_putstr("map tab allocating error during parsing.\n");
	else
		ft_putstr("unknown structure.\n");
}

void 	error_msg_texture(char *filepath)
{
	ft_putstr("This texture file was involved in the error : ");
	if (filepath)
		ft_putstr(filepath);
	else
		ft_putstr("unknown filepath");
	ft_putstr("\n");
}