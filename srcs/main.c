/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: louise <lsoulier@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/18 14:36:08 by louise            #+#    #+#             */
/*   Updated: 2020/11/28 16:42:23 by user42           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"
#include "parsing.h"

int	main(int argc, char **argv)
{
	t_mlx_vars	vars;
	int			save_opt;

	save_opt = 0;
	if (argc == 2 || argc == 3)
	{
		if (argc == 3 && ft_strnstr(argv[2], "--save", 6) != NULL)
			save_opt = 1;
		if (save_opt || argc == 2)
		{
			if (!load_config_file(&vars.parsed_file, argv[1]))
				return (0);
			if (!create_game_struct(&vars, save_opt))
			{
				exit_game(&vars);
				return (0);
			}
			event_mngt(&vars);
		}
	}
	if (argc < 2 || (argc == 3 && !save_opt) || argc > 3)
		error_msg(ARG_ERROR);
	return (0);
}
