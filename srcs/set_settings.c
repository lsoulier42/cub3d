/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_settings.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: louise <lsoulier@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/18 22:06:07 by louise            #+#    #+#             */
/*   Updated: 2020/10/19 22:52:08 by louise           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"
#include "libft.h"

void 	set_dimension(t_dimension *dimension, int width, int height)
{
	dimension->width = width;
	dimension->height = height;
}

void	set_window_res(char *line, t_dimension *window_res)
{
	while (!ft_isdigit(*line))
		line++;
	window_res->width = (int)ft_atoi(line);
	while(ft_isdigit(*line))
		line++;
	window_res->height = (int)ft_atoi(line);
}

void	set_map_texture(char *line, t_file *text_file)
{
	char 	*filestr;

	while (ft_isalpha(*line))
		line++;
	filestr = ft_strtrim(line, " ");
	text_file->fullname = ft_strdup(filestr);
	//check_file(filestr, text_file);
	free(filestr);
}

void	set_map_color(char *line, t_color *color)
{
	while (ft_isalpha(*line))
		line++;
	color->r = (char)ft_atoi(line);
	while (*line != ',')
		line++;
	line++;
	color->g = (char)ft_atoi(line);
	while (*line != ',')
		line++;
	line++;
	color->b = (char)ft_atoi(line);
}