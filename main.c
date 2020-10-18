/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: louise <lsoulier@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/18 14:36:08 by louise            #+#    #+#             */
/*   Updated: 2020/10/18 19:35:38 by louise           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"
#include "libft.h"

int main(int argc, char **argv)
{
	t_game	*parsed_map;
	t_file	*cubmap;

	if (argc >= 2 && argc <= 3)
	{
		if (!(cubmap = check_file(argv[1])))
			return (0);
		if (ft_strncmp("cub", cubmap->ext, 3) != 0)
			return (destroy_file(cubmap));
		if (!(parsed_map = parse_file(cubmap)))
			return (destroy_file(cubmap));
		//suite
		close(cubmap->fd);
	}
	return (0);
}