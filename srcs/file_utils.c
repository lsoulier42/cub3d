/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cubmap_utils.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: louise <lsoulier@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/18 19:16:46 by louise            #+#    #+#             */
/*   Updated: 2020/10/18 19:19:03 by louise           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"
#include "libft.h"

void 	*destroy_filevar(char *ext, char *filename, char *path)
{
	free (ext);
	free (filename);
	free (path);
	return (NULL);
}

void	*destroy_file(t_file *file)
{
	destroy_filevar(cubmap->ext, cubmap->filename, cubmap->path);
	close(cubmap->fd);
	free(cubmap);
	return (NULL);
}
