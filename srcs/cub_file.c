/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub_file.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lsoulier <lsoulier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/22 13:37:56 by lsoulier          #+#    #+#             */
/*   Updated: 2020/11/22 13:51:25 by user42           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parsing.h"

int			check_cub_file(char *path)
{
	int		fd;

	if (!check_extension_file(path, ".cub"))
	{
		error_msg(CUB_FILE_ERROR);
		return (-1);
	}
	fd = open(path, O_RDONLY);
	if (fd < 0)
	{
		error_msg(CUB_FILE_ERROR);
		return (-1);
	}
	else
		return (fd);
}

int			check_extension_file(char *path, char *ext)
{
	int path_len;
	int ext_len;
	int i;

	i = -1;
	path_len = 0;
	ext_len = 0;
	if (path && ext)
	{
		path_len = ft_strlen(path);
		ext_len = ft_strlen(ext);
		while (++i < path_len - ext_len)
			path++;
		if (ft_strncmp(path, ext, ext_len) == 0)
			return (1);
	}
	return (0);
}