/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cubmap_utils.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: louise <lsoulier@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/18 19:16:46 by louise            #+#    #+#             */
/*   Updated: 2020/10/20 19:34:55 by louise           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"
#include "libft.h"

int		open_game_file(t_file *file, char *fullname)
{
	int 	fd;

	init_file(file);
	fd = open(fullname, O_RDONLY);
	if (fd == -1)
		return (0);
	if (!(set_file(file, fullname, fd)))
		return (0);
	return (1);
}

void 	init_file(t_file *file)
{
	file->fullname = NULL;
	file->ext = NULL;
	file->filename = NULL;
	file->path = NULL;
	file->fd = 0;
}

int		set_file(t_file *file, char *fullname, int fd)
{
	size_t	len;
	size_t	point;
	size_t	slash;

	point = 0;
	slash = 0;
	if (fullname)
	{
		len = ft_strlen(fullname);
		file->fullname = fullname;
		while (fullname[point] && fullname[len - point - 1] != '.')
			point++;
		while (fullname[slash] && fullname[len - slash - 1] != '/')
			slash++;
		if (!(file->filename = (char *)malloc(sizeof(char) * (slash - point))) ||
			!(file->ext = (char *)malloc(sizeof(char) * (point + 1))) ||
			!(file->path = (char *)malloc(sizeof(char) * (len - slash + 1))))
			return (0);
		ft_strlcpy(file->filename, fullname + len - slash, slash - point);
		ft_strlcpy(file->path, fullname, len - slash + 1);
		ft_strlcpy(file->ext, fullname + len - point, point + 1);
	}
	file->fd = fd;
	return (1);
}

void 	close_game_files(t_file cubmap, t_game *parsed_map)
{
	int i;

	i = -1;
	destroy_file(cubmap);
	while (++i < parsed_map->map_res.height)
		free(parsed_map->map[i]);
	free(parsed_map->map);
	destroy_file(parsed_map->no_text);
	destroy_file(parsed_map->so_text);
	destroy_file(parsed_map->we_text);
	destroy_file(parsed_map->ea_text);
	destroy_file(parsed_map->sprite_text);
	free(parsed_map);
}

int 	destroy_file(t_file file)
{
	if(ft_strncmp("cub", file.ext, 3) != 0)
		free(file.fullname);
	free(file.ext);
	free(file.filename);
	free(file.path);
	close(file.fd);
	return (0);
}
