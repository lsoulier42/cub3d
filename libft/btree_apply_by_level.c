/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   btree_apply_by_level.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: louise <lsoulier@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/28 16:03:05 by louise            #+#    #+#             */
/*   Updated: 2020/09/28 16:03:07 by louise           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static void	btree_track(t_btree *node, void (*applyf)(void *item,
			int current_level, int is_first), int level, int *max_level)
{
	(*applyf)(node->item, level, *max_level < level);
	*max_level = *max_level < level ? level : *max_level;
	if (node->left || node->right)
		level++;
	if (node->left)
		btree_track(node->left, applyf, level, max_level);
	if (node->right)
		btree_track(node->right, applyf, level, max_level);
}

void		btree_apply_by_level(t_btree *root, void (*applyf)(void *item,
			int current_level, int is_first))
{
	int max_level;

	max_level = 0;
	btree_track(root, applyf, 1, &max_level);
}
