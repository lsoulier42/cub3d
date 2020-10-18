/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: louise <lsoulier@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/24 23:46:57 by louise            #+#    #+#             */
/*   Updated: 2020/09/27 22:47:31 by louise           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

int			get_next_line(int fd, char **line)
{
	static t_list_file	*first = NULL;
	t_list_file			*current;
	int					offset;
	int					ret;

	if (fd < 0 || !line)
		return (-1);
	current = get_or_put_buffer(fd, &first);
	if (!(offset = set_begin_line(current->buff, line)))
		return (read_file(fd, &(current->buff), line));
	else
	{
		ret = move_buff(&(current->buff), offset);
		if (ret == 0)
			free(current);
		return (ret);
	}
}
