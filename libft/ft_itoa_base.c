/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa_base.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: louise <lsoulier@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/02 23:13:08 by louise            #+#    #+#             */
/*   Updated: 2020/10/10 02:22:19 by louise           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	count_char_base(long long n, int len)
{
	int			nb_char;
	long long	nb;

	nb_char = n < 0 ? 2 : 1;
	nb = n < 0 ? -(long long)n : n;
	while (nb / len != 0)
	{
		nb_char++;
		nb /= len;
	}
	return (nb_char);
}

char		*ft_itoa_base(long long n, char *base)
{
	char		*str;
	int			nb_char;
	long long	abs_n;
	int			len;

	len = ft_strlen(base);
	nb_char = count_char_base(n, len);
	abs_n = n < 0 ? -(long long)n : n;
	if (!(str = (char*)malloc(sizeof(char) * (nb_char + 1))))
		return (NULL);
	str[nb_char] = '\0';
	while (--nb_char > 0)
	{
		str[nb_char] = base[abs_n % len];
		abs_n /= len;
	}
	str[0] = n < 0 ? '-' : base[abs_n % len];
	return (str);
}
