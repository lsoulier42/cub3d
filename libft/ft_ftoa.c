/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ftoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: louise <lsoulier@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/07 00:10:13 by louise            #+#    #+#             */
/*   Updated: 2020/10/07 00:22:13 by louise           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_ftoa(float nb)
{
	int		first_part;
	int		precision;
	int		i;
	char	*data;

	first_part = (int)nb;
	nb -= first_part;
	precision = 6;
	i = -1;
	data = ft_itoa(first_part);
	data = ft_addsuffix(data, ".");
	while (++i < precision)
	{
		nb *= 10;
		first_part = (int)nb;
		nb -= first_part;
		if (i == precision - 1 && (int)(nb * 10) > 4 && precision != 6)
			first_part++;
		data = ft_addsuffix(data, ft_itoa(first_part));
	}
	return (data);
}
