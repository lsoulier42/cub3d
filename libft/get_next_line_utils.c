/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: louise <lsoulier@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/26 21:16:18 by louise            #+#    #+#             */
/*   Updated: 2020/10/19 22:38:16 by louise           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int			set_begin_line(char *buff, char **line_begin)
{
	int		i;
	int		offset;
	int		nb_char;

	i = -1;
	offset = 0;
	nb_char = 0;
	if (*buff)
	{
		while (buff[offset] != '\n' && offset < BUFFER_SIZE)
			offset++;
		offset++;
		while (buff[offset + nb_char] != '\n' && buff[offset + nb_char]
				&& (offset + nb_char) < BUFFER_SIZE)
			nb_char++;
	}
	if (!(*line_begin = (char*)malloc(sizeof(char) * (nb_char + 1))))
		return (0);
	while (++i < nb_char)
		(*line_begin)[i] = buff[offset + i];
	(*line_begin)[i] = '\0';
	return (buff[offset + nb_char] == '\n' ? offset : 0);
}

char		*join_buff(char *line, char *buff, int buff_len)
{
	char	*new;
	int		i;
	int		j;
	int		line_len;

	i = -1;
	j = -1;
	line_len = 0;
	while (line[line_len])
		line_len++;
	if (!(new = (char*)malloc(sizeof(char) * (line_len + buff_len + 1))))
		return (NULL);
	while (++i < line_len)
		new[i] = line[i];
	free(line);
	while (++j < buff_len)
		new[i + j] = buff[j];
	new[i + j] = '\0';
	return (new);
}

int			move_buff(char (*buff)[BUFFER_SIZE], int offset)
{
	int i;
	int j;

	i = -1;
	j = -1;
	while (offset + ++i < BUFFER_SIZE)
		(*buff)[i] = (*buff)[offset + i];
	while (i < BUFFER_SIZE)
		(*buff)[i++] = '\0';
	while ((*buff)[++j])
		if ((*buff)[j] == '\n')
			return (1);
	return (0);
}

int			read_file(int fd, char (*buff)[BUFFER_SIZE], char **line)
{
	int i;
	int read_val;

	while ((read_val = read(fd, *buff, BUFFER_SIZE)) != 0)
	{
		if (read_val == -1)
			return (-1);
		i = 0;
		while ((*buff)[i] != '\n' && i < read_val)
			i++;
		*line = join_buff(*line, *buff, i);
		if (read_val != BUFFER_SIZE)
			(*buff)[read_val] = '\0';
		if (i != BUFFER_SIZE && i != read_val)
			return (1);
	}
	return (0);
}

t_list_file	*get_or_put_buffer(int fd, t_list_file **first)
{
	t_list_file	*current;
	t_list_file	*previous;

	current = *first;
	previous = NULL;
	while (current)
	{
		if (current->fd == fd)
			return (current);
		previous = current;
		current = current->next;
	}
	if (!(current = (t_list_file*)malloc(sizeof(t_list_file))))
		return (NULL);
	current->fd = fd;
	*(current->buff) = '\0';
	current->next = NULL;
	if (!previous)
		*first = current;
	else
		previous->next = current;
	return (current);
}
