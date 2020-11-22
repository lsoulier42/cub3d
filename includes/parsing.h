/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lsoulier <lsoulier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/22 13:30:56 by lsoulier          #+#    #+#             */
/*   Updated: 2020/11/22 14:17:30 by user42           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PARSING_H
# define PARSING_H
# include "libft.h"
# include "constants.h"
# include "cub3d.h"
# define NOT_WALL "02NSWE"
# define CARD_CHARSET "NSEW"
# define CONFIG_CHARSET "RNSWEFC"

t_game_file		*load_config_file(char *path);
int				check_cub_file(char *path);
int 			check_extension_file(char *path, char *ext);
t_game_file		*init_parsed_file(void);
int				parse_config_file(t_game_file *parsed_file, int fd);
int				parse_settings(t_game_file *parsed_file, char *line);
int 			parse_resolution(t_game_file *parsed_file, char *line);
int				set_win_res(char *line, t_dimension *win_res);
int				parse_textures(t_game_file *parsed_file, char *line);
int				set_texture_path(char *line, char **text_path);
int				parse_colors(t_game_file *parsed_file, char *line);
char 			*trim_spaces(char *str);
int				set_background_color(char *line, int *color);
int 			check_background(int floor_color, int ceiling_color);
int 			check_color_format(char *line);
int				parse_map(t_game_file *parsed_file, char **line, int fd);
char			**create_map(char **line, int fd);
char			**realloc_map(char **data, int prev_size, int new_size);
int				check_map(char **map);
int				parse_player_start(t_game_file *parsed_file);
#endif
