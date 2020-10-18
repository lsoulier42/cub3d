/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_stradd.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: louise <lsoulier@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/07 00:12:51 by louise            #+#    #+#             */
/*   Updated: 2020/10/07 00:18:29 by louise           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_addsuffix(char *str_to_free, char *str_to_add)
{
	char *definite_str;

	definite_str = ft_strjoin(str_to_free, str_to_add);
	free(str_to_free);
	return (definite_str);
}
