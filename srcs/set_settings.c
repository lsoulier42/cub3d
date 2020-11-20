/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_settings.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: louise <lsoulier@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/18 22:06:07 by louise            #+#    #+#             */
/*   Updated: 2020/11/20 17:34:45 by user42           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"
#include "libft.h"

int	set_window_res(char *line, t_dimension *win_res)
{
	int width;
	int height;
	int i;

	i = -1;
	while (*line && !ft_isdigit(*line))
		line++;
	while (line[++i])
		if (!ft_isdigit(line[i]) && line[i] != ' ')
		{
			error_msg_parsing(FORMAT_RESOLUTION_ERROR);
			return (0);
		}
	width = (int)ft_atoi(line);
	while (*line && ft_isdigit(*line))
		line++;
	height = (int)ft_atoi(line);
	if (width == 0 || height == 0
		|| width == FOUR_K_RES_WIDTH || height == FOUR_K_RES_HEIGHT)
	{
		error_msg_parsing(FORMAT_RESOLUTION_ERROR);
		return (0);
	}
	set_dimension(win_res, width, height);
	return (1);
}

int	set_map_texture(char *line, char **text_path)
{
	while (ft_isalpha(*line))
		line++;
	*text_path = ft_strtrim(line, " ");
	if (!check_extension_file(*text_path, ".xpm"))
	{
		error_msg_parsing(TEXTURE_EXT_ERROR);
		error_msg_texture(*text_path);
		return (0);
	}
	return (1);
}

int check_color_format(char *line)
{
	int i;

	i = -1;
	while (line[++i])
		if (!ft_isdigit(line[i]) && line[i] != ' ' && line[i] != ',')
			return (0);
	return (1);
}

int	set_map_color(char *line, int *color)
{
	int	r;
	int	g;
	int	b;

	while (*line == 'F' || *line == 'C' || *line == ' ')
		line++;
	if (!check_color_format(line))
	{
		error_msg_parsing(COLOR_SETTING_ERROR);
		return (0);
	}
	r = (unsigned char)ft_atoi(line);
	while (*line && *line != ',')
		line++;
	line++;
	g = (unsigned char)ft_atoi(line);
	while (*line && *line != ',')
		line++;
	line++;
	b = (unsigned char)ft_atoi(line);
	if (r < 0 || g < 0 || b < 0 || r > 255 || g > 255 || b > 255)
	{
		error_msg_parsing(COLOR_SETTING_ERROR);
		return (0);
	}
	*color = create_trgb(0, r, g, b);
	return (1);
}
