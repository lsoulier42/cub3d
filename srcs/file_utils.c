/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cubmap_utils.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: louise <lsoulier@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/18 19:16:46 by louise            #+#    #+#             */
/*   Updated: 2020/10/18 22:11:15 by louise           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"
#include "libft.h"

int 	destroy_filevar(char *ext, char *filename, char *path)
{
	free (ext);
	free (filename);
	free (path);
	return (0);
}

int 	destroy_file(t_file file)
{
	destroy_filevar(file.ext, file.filename, file.path);
	close(file.fd);
	return (0);
}
