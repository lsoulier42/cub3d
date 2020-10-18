/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putfloat.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: louise <lsoulier@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/07 00:09:16 by louise            #+#    #+#             */
/*   Updated: 2020/10/07 00:09:57 by louise           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_putfloat(float nb)
{
	int		first_part;
	int		precision;
	int		i;

	first_part = (int)nb;
	nb -= first_part;
	precision = 6;
	i = -1;
	ft_putnbr(first_part);
	write(1, ".", 1);
	while (++i < precision)
	{
		nb *= 10;
		first_part = (int)nb;
		nb -= first_part;
		if (i == precision - 1 && (int)(nb * 10) > 4 && precision != 6)
			first_part++;
		ft_putnbr(first_part);
	}
}
