/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_settings.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: louise <lsoulier@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/18 22:06:07 by louise            #+#    #+#             */
/*   Updated: 2020/11/14 02:10:30 by user42           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"
#include "libft.h"

void	set_window_res(char *line, t_dimension *window_res)
{
	int width;
	int height;

	while (!ft_isdigit(*line))
		line++;
	width = (int)ft_atoi(line);
	while (ft_isdigit(*line))
		line++;
	height = (int)ft_atoi(line);
	set_dimension(window_res, width, height);
}

void	set_map_texture(char *line, char **file_path)
{
	while (ft_isalpha(*line))
		line++;
	*file_path = ft_strtrim(line, " ");
}

void	set_map_color(char *line, int *color)
{
	unsigned char	r;
	unsigned char	g;
	unsigned char	b;

	while (ft_isalpha(*line))
		line++;
	r = (unsigned char)ft_atoi(line);
	while (*line != ',')
		line++;
	line++;
	g = (unsigned char)ft_atoi(line);
	while (*line != ',')
		line++;
	line++;
	b = (unsigned char)ft_atoi(line);
	*color = create_trgb(0, r, g, b);
}
