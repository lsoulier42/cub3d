/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: louise <lsoulier@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/24 23:41:24 by louise            #+#    #+#             */
/*   Updated: 2020/09/27 22:46:11 by louise           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H
# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 32
# endif
# include <stdlib.h>
# include <sys/types.h>
# include <sys/uio.h>
# include <unistd.h>

typedef struct	s_list_file
{
	char				buff[BUFFER_SIZE];
	int					fd;
	struct s_list_file	*next;
}				t_list_file;
int				set_begin_line(char *buff, char **line_begin);
char			*join_buff(char *line, char *buff, int buff_len);
int				move_buff(char (*buff)[BUFFER_SIZE], int offset);
int				read_file(int fd, char (*buff)[BUFFER_SIZE], char **line);
t_list_file		*get_or_put_buffer(int fd, t_list_file **first);
int				get_next_line(int fd, char **line);
#endif
