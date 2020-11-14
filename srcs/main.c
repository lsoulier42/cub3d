/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: louise <lsoulier@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/18 14:36:08 by louise            #+#    #+#             */
/*   Updated: 2020/11/14 17:13:07 by user42           ###   ########.fr       */
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
			vars = create_vars_struct(parsed_file);
			if (vars != NULL && create_window(vars) == 1 && create_images(vars) == 1)
			{
				event_mngt(vars);
				free_game_struct(vars);
			}
			free_parsed_file(parsed_file);
		}
	}
	else
		error_msg(ARG_ERROR);
	return (0);
}
