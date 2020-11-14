/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lsoulier <lsoulier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/14 01:53:44 by lsoulier          #+#    #+#             */
/*   Updated: 2020/11/14 03:35:51 by user42           ###   ########.fr       */
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
	else if (error_type == MLX_INIT_ERROR)
		ft_putstr("Erreur d'initialisation de la minilibX.\n");
	else if (error_type == MLX_WINDOW_ERROR)
		ft_putstr("Erreur de creation de la fenetre.\n");
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
	else
		ft_putstr("structure inconnue.\n");
}
