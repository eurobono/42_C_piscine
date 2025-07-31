/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   btree_level_count.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: enricant <enricant@42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/23 10:52:34 by enricant          #+#    #+#             */
/*   Updated: 2025/07/24 16:21:33 by enricant         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "ft_btree.h"

int	btree_level_count(t_btree *root)
{
	int	left_depth;
	int	right_depth;
	int	count;

	if (!root)
		return (0);
	left_depth = btree_level_count(root->left);
	right_depth = btree_level_count(root->right);
	if (left_depth > right_depth)
		count = left_depth;
	else
		count = right_depth;
	return (1 + count);
}

/* *
#include <stdio.h>
#include <string.h>

int main()
{
	t_btree	*root;

	root = NULL;
	btree_insert_data(&root, "Madrid", (int (*)(void *, void *))strcmp);
	btree_insert_data(&root, "Malaga", (int (*)(void *, void *))strcmp);
	btree_insert_data(&root, "Barcelona", (int (*)(void *, void *))strcmp);
	btree_insert_data(&root, "Valladolid", (int (*)(void *, void *))strcmp);
	btree_insert_data(&root, "Cadiz", (int (*)(void *, void *))strcmp);
	btree_insert_data(&root, "Zaragoza", (int (*)(void *, void *))strcmp);
	btree_insert_data(&root, "Betis", (int (*)(void *, void *))strcmp);
	btree_insert_data(&root, "Sevilla", (int (*)(void *, void *))strcmp);
	printf("Tree size:%02d\n", btree_level_count(root));
	return 0;
}
* */
