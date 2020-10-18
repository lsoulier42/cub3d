/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   btree_level_count.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: louise <lsoulier@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/28 16:05:51 by louise            #+#    #+#             */
/*   Updated: 2020/09/28 16:05:53 by louise           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	btree_prefix(t_btree *node, int level)
{
	int level_right;
	int level_left;

	level_right = level;
	level_left = level;
	if (node)
	{
		level++;
		if (node->left)
			level_left = btree_prefix(node->left, level);
		if (node->right)
			level_right = btree_prefix(node->right, level);
	}
	return (level_right > level_left ? level_right : level_left);
}

int			btree_level_count(t_btree *root)
{
	int max_level;

	max_level = btree_prefix(root, 1);
	return (max_level);
}
