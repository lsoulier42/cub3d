/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: louise <lsoulier@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/18 14:36:08 by louise            #+#    #+#             */
/*   Updated: 2020/11/20 20:01:48 by user42           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"
#include "libft.h"

int	main(int argc, char **argv)
{
	t_game_file	*parsed_file;
	t_mlx_vars	*vars;

	if (argc >= 2 && argc <= 3)
	{
		parsed_file = parse_file(argv[1]);
		if (!parsed_file)
			error_msg(PARSING_ERROR);
		else
		{
			if (load_game(&vars, parsed_file))
				event_mngt(vars);
			if (vars)
				free_game_struct(vars);
			free_parsed_file(parsed_file);
		}
	}
	else
		error_msg(ARG_ERROR);
	return (0);
}
