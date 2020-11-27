/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lsoulier <lsoulier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/22 13:30:56 by lsoulier          #+#    #+#             */
/*   Updated: 2020/11/27 20:14:47 by user42           ###   ########.fr       */
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

typedef struct	s_parsing_color
{
	int r;
	int g;
	int b;
}				t_parsing_color;

int				load_config_file(t_game_file *parsed_file, char *path);
int				check_cub_file(char *path);
int				check_extension_file(char *path, char *ext);
void			init_parsed_file(t_game_file *parsed_file);
int				parse_config_file(t_game_file *parsed_file, int fd);
int				parse_settings(t_game_file *parsed_file, int fd);
int				parse_resolution(t_game_file *parsed_file, char *line);
int				set_win_res(char *line, t_dimension *win_res);
int				parse_textures(t_game_file *parsed_file, char *line);
int				set_texture_path(char *line, char **text_path);
int				parse_colors(t_game_file *parsed_file, char *line);
int				check_color_format(char *line);
char			*trim_spaces(char *str);
int				line_is_whitespace(char *str);
char			*trim_white_lines(int fd);
int				set_background_colors(char *line, int *color);
int				atoi_color(char *line, int index);
void			check_missing_settings(t_game_file *parsed_file);
int				parse_map(t_game_file *parsed_file, char **line, int fd);
char			**create_map(char **line, int fd);
char			**realloc_map(char **data, int prev_size, int new_size);
int				check_map(char **map);
int				parse_player_star(char **map, t_point *player_start,
					char *player_start_card);
int				invalid_map(char **map, int y, int map_height, int line_len);
int				set_map_settings(t_game_file *parsed_file, char **map);
void			free_alloc_map(char **map);
int				detect_res(char *line, t_dimension *win_res);
char			**create_res_tab(char *line);
void			free_res_tab(char **values);
#endif
