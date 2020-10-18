/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   file.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: louise <lsoulier@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/18 16:05:48 by louise            #+#    #+#             */
/*   Updated: 2020/10/18 19:22:26 by louise           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"
#include "libft.h"

char 	*get_extension(char *file)
{
	char	*ext;
	size_t	len;
	size_t	point;

	point = 0;
	len = ft_strlen(file);
	while (file[point] && file[len - point - 1] != '.')
		point++;
	if (!(ext = (char*)malloc(sizeof(char) * (point + 1))))
		return (NULL);
	ft_strlcpy(ext, file + len - point, point + 1);
	return (ext);
}

char 	*get_filename(char *file)
{
	char	*filename;
	size_t	len;
	size_t	point;
	size_t	slash;

	point = 0;
	slash = 0;
	len = ft_strlen(file);
	while (file[point] && file[len - point - 1] != '.')
		point++;
	while (file[slash] && file[len - slash - 1] != '/')
		slash++;
	if(!(filename = (char*)malloc(sizeof(char) * (slash - point))))
		return (NULL);
	ft_strlcpy(filename, file + len - slash, slash - point);
	return (filename);
}

char 	*get_filepath(char *file)
{
	char	*filepath;
	size_t	len;
	size_t	slash;

	slash = 0;
	len = ft_strlen(file);
	while (file[slash] && file[len - slash - 1] != '/')
		slash++;
	if(!(filepath = (char*)malloc(sizeof(char) * (len - slash + 1))))
		return (NULL);
	ft_strlcpy(filepath, file, len - slash + 1);
	return (filepath);
}

t_file	*check_file(char *filestr)
{
	t_file	*file;
	char	*ext;
	char 	*filename;
	char 	*path;
	int 	fd;

	if (!(ext = get_extension(filestr)) || !(filename = get_filename(filestr))
		|| !(path = get_filepath(filestr)))
		return (NULL);
	if ((fd = open(filestr, O_RDONLY)) == -1 || !(file = (t_file*)malloc(sizeof(t_file))))
		return (destroy_filevar(ext, filename, path));
	file->fullname = filestr;
	file->ext = ext;
	file->filename = filename;
	file->path = path;
	file->fd = fd;
	return (file);
}