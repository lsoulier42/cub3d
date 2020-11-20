/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_file.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: louise <lsoulier@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/18 19:25:00 by louise            #+#    #+#             */
/*   Updated: 2020/11/20 21:01:25 by user42           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"
#include "libft.h"

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

int			check_cub_file(char *path)
{
	int		fd;

	if (!check_extension_file(path, ".cub"))
	{
		error_msg(EXT_ERROR);
		return (-1);
	}
	fd = open(path, O_RDONLY);
	if (fd <= 0)
	{
		error_msg(CUB_FILE_ERROR);
		return (-1);
	}
	else
		return (fd);
}

t_game_file	*init_parsed_file(void)
{
	t_game_file	*parsed_file;

	parsed_file = (t_game_file*)malloc(sizeof(t_game_file));
	if (!parsed_file)
	{
		error_msg_alloc(PARSED_FILE_ALLOC_ERROR);
		return (NULL);
	}
	parsed_file->map = NULL;
	parsed_file->player_start_card = 0;
	set_point(&(parsed_file->player_start), 0, 0);
	set_dimension(&(parsed_file->map_res), 0, 0);
	set_dimension(&(parsed_file->win_res), 800, 600);
	parsed_file->no_text = NULL;
	parsed_file->so_text = NULL;
	parsed_file->we_text = NULL;
	parsed_file->ea_text = NULL;
	parsed_file->sprite_text = NULL;
	parsed_file->floor_color = color_trgb(BLACK);
	parsed_file->ceiling_color = color_trgb(BLACK);
	return (parsed_file);
}

int			read_cub_file(t_game_file *parsed_file, int fd)
{
	char	*line;
	int 	ret_gnl;

	ret_gnl = 1;
	line = NULL;
	while (ret_gnl)
	{
		ret_gnl = get_next_line(fd, &line);
		if (ft_strchr(CONFIG_CHARSET, *line) != NULL)
		{
			if (!check_config(parsed_file, line))
				return (0);
		}
		else if (*line && *line != '\n')
			if (!set_map(parsed_file, &line, fd))
				return (0);
		free(line);
	}
	return (1);
}

t_game_file		*parse_file(char *path)
{
	t_game_file	*parsed_file;
	int			fd;

	fd = check_cub_file(path);
	parsed_file = init_parsed_file();
	if (fd < 0 || !parsed_file)
		return (NULL);
	if (!read_cub_file(parsed_file, fd))
	{
		free_parsed_file(parsed_file);
		return (NULL);
	}
	return (parsed_file);
}
