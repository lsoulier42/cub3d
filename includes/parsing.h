/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lsoulier <lsoulier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/22 13:30:56 by lsoulier          #+#    #+#             */
/*   Updated: 2020/11/28 20:33:55 by user42           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PARSING_H
# define PARSING_H
# include "libft.h"
# include "constants.h"
# include "cub3d.h"
# define NOT_WALL "02NSWE"
# define CARD_CHARSET "NSEW"
# define SETTINGS_CHARSET "RNSWEFC"
# define ELEMENTS_CHARSET " 012NSEW"

typedef enum	e_settings
{
	RESOLUTION,
	NORTH_TEXTURE,
	SOUTH_TEXTURE,
	WEST_TEXTURE,
	EAST_TEXTURE,
	SPRITE_TEXTURE,
	FLOOR_COLOR,
	CEIL_COLOR,
	NB_SETTINGS
}				t_settings;

int				load_config_file(t_game_file *parsed_file, char *path);
int				check_cub_file(char *path);
int				check_extension_file(char *path, char *ext);
void			init_parsed_file(t_game_file *parsed_file);
int				parse_config_file(t_game_file *parsed_file, int fd);
int				parse_settings(t_game_file *parsed_file, int fd);
int				line_is_whitespace(char *str);
int				config_available(char **values);
char			**parse_line(char *line);
int				parse_settings_suite(t_game_file *parsed_file, char *line);
int				get_settings(t_game_file *parsed_file, char **values);
int				nb_tab_values(char **values);
int				parse_resolution(t_game_file *parsed_file, char **values);
int				invalid_format_res(char **values);
int				str_is_uint(char *str);
int				parse_textures(t_game_file *parsed_file, char **values);
int				set_texture_path(t_game_file *parsed_file, char **values);
int				already_set_text(t_game_file *parsed_file, char **values);
int				parse_colors(t_game_file *parsed_file, char **values);
int				check_color_comas(char *line);
int				invalid_format_color(char **values);
int				set_colors(t_game_file *parsed_file, char **values);
void			check_missing_settings(t_game_file *parsed_file);
char			*trim_white_lines(int fd);
int				parse_map(t_game_file *parsed_file, char **line, int fd);
int				set_map_settings(t_game_file *parsed_file);
char			**create_map(char **line, int fd);
char			**concat_lines(char **map, int line_index, char *line);
int				check_map(char **map);
int				parse_player_star(char **map, t_point *player_start,
					char *player_start_card);
int				invalid_map(char **map, int y, int map_height, int line_len);
int				check_around(char **map, int x, int y);
void			free_double_tab(char **tab);
#endif
