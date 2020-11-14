/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_file.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: louise <lsoulier@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/18 19:25:00 by louise            #+#    #+#             */
/*   Updated: 2020/11/14 04:05:57 by user42           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"
#include "libft.h"

int			check_file(char *path)
{
	int		fd;
	char	*invert_ext;
	int		strcmp_ret;

	fd = 0;
	invert_ext = ft_strrev(path);
	strcmp_ret = ft_strncmp(invert_ext, "buc.", 4);
	free(invert_ext);
	if (strcmp_ret != 0)
	{
		error_msg(EXT_ERROR);
		return (-1);
	}
	fd = open(path, O_RDONLY);
	if (fd <= 0)
	{
		error_msg(FILE_ERROR);
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
	set_dimension(&(parsed_file->win_res), 0, 0);
	parsed_file->no_text = NULL;
	parsed_file->so_text = NULL;
	parsed_file->we_text = NULL;
	parsed_file->ea_text = NULL;
	parsed_file->sprite_text = NULL;
	parsed_file->floor_color = color_trgb(BLACK);
	parsed_file->ceiling_color = color_trgb(BLACK);
	parsed_file->tile_size = 0;
	return (parsed_file);
}

void		check_config(t_game_file *parsed_file, char **line, int fd)
{
	if (ft_strnstr(*line, "R ", 2) != NULL)
		set_window_res(*line, &parsed_file->win_res);
	else if (ft_strnstr(*line, "NO ", 3) != NULL)
		set_map_texture(*line, &parsed_file->no_text);
	else if (ft_strnstr(*line, "SO ", 3) != NULL)
		set_map_texture(*line, &parsed_file->so_text);
	else if (ft_strnstr(*line, "WE ", 3) != NULL)
		set_map_texture(*line, &parsed_file->we_text);
	else if (ft_strnstr(*line, "EA ", 3) != NULL)
		set_map_texture(*line, &parsed_file->ea_text);
	else if (ft_strnstr(*line, "S ", 2) != NULL)
		set_map_texture(*line, &parsed_file->sprite_text);
	else if (ft_strnstr(*line, "F ", 2) != NULL)
		set_map_color(*line, &parsed_file->floor_color);
	else if (ft_strnstr(*line, "C ", 2) != NULL)
		set_map_color(*line, &parsed_file->ceiling_color);
	else if (**line)
		set_map(parsed_file, line, fd);
}

t_game_file	*parse_file(char *path)
{
	char		*line;
	int			ret_gnl;
	t_game_file	*parsed_file;
	int			fd;

	ret_gnl = 1;
	fd = check_file(path);
	if (fd < 0)
		return (NULL);
	parsed_file = init_parsed_file();
	if (!parsed_file)
		return (NULL);
	while (ret_gnl)
	{
		ret_gnl = get_next_line(fd, &line);
		check_config(parsed_file, &line, fd);
		free(line);
	}
	return (parsed_file);
}
