/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_addprefix.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: louise <lsoulier@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/07 00:20:03 by louise            #+#    #+#             */
/*   Updated: 2020/10/07 00:21:28 by louise           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_addprefix(char *str_to_add, char *str_to_free)
{
	char *definite_str;

	definite_str = ft_strjoin(str_to_add, str_to_free);
	free(str_to_free);
	return (definite_str);
}
