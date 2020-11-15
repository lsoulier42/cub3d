/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lsoulier <lsoulier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/14 01:53:44 by lsoulier          #+#    #+#             */
/*   Updated: 2020/11/15 21:06:57 by user42           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "cub3d.h"

void	error_msg(int error_type)
{
	if (error_type == EXT_ERROR)
		ft_putstr("Erreur d'extension du fichier.\n");
	else if (error_type == PARSING_ERROR)
		ft_putstr("Erreur pendant le parsing de la map.\n");
	else if (error_type == FILE_ERROR)
		ft_putstr("Erreur d'ouverture du fichier de map.\n");
	else if (error_type == ARG_ERROR)
		ft_putstr("Nombre d'arguments invalides.\n");
	else if (error_type == MLX_ERROR)
		ft_putstr("Erreur minilibX\n");
	else if (error_type == MLX_INIT_ERROR)
		ft_putstr("Erreur d'initialisation de la minilibX.\n");
	else if (error_type == MLX_WINDOW_ERROR)
		ft_putstr("Erreur de creation de la fenetre.\n");
	else if (error_type == IMAGE_ERROR)
		ft_putstr("Erreur de creation des vues.\n");
	else if (error_type == IMAGE_CREATION_ERROR)
		ft_putstr("Erreur mlx_put_image.\n");
	else if (error_type == TEXTURE_ADDR_ERROR)
		ft_putstr("Erreur de chargement memoire de la texture.\n");
	else if (error_type == STRUCT_ERROR)
		ft_putstr("Erreur de creation des structures.\n");
	else if (error_type == TEXTURE_ERROR)
		ft_putstr("Erreur de creation des textures.\n");
	else
		ft_putstr("Erreur inconnue.\n");
}

void	error_msg_alloc(int error_type)
{
	ft_putstr("Erreur d'allocation memoire : ");
	if (error_type == VARS_ALLOC_ERROR)
		ft_putstr("structure -vars-.\n");
	else if (error_type == PLAYER_ALLOC_ERROR)
		ft_putstr("structure -player-.\n");
	else if (error_type == RAYS_ALLOC_ERROR)
		ft_putstr("structure -rays-.\n");
	else if (error_type == PARSED_FILE_ALLOC_ERROR)
		ft_putstr("structure -parsed_file-.\n");
	else if (error_type == IMAGE_ALLOC_ERROR)
		ft_putstr("structure -image_data-.\n");
	else if (error_type == TEXTURE_ALLOC_ERROR)
		ft_putstr("chargement textures.\n");
	else
		ft_putstr("structure inconnue.\n");
}

void 	error_msg_texture(char *filepath)
{
	ft_putstr("Erreur de chargement du fichier de texture : ");
	ft_putstr(filepath);
	ft_putstr("\n");
}