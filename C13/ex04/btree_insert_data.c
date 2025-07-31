/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   btree_insert_data.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: enricant <enricant@42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/23 10:52:34 by enricant          #+#    #+#             */
/*   Updated: 2025/07/24 15:43:13 by enricant         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "ft_btree.h"

void	btree_insert_data(t_btree **root, void *item,
		int (*cmpf)(void *, void *))
{
	if (!root || !cmpf)
		return ;
	if (*root == NULL)
	{
		*root = btree_create_node(item);
		return ;
	}
	if (cmpf(item, (*root)->item) < 0)
		btree_insert_data(&((*root)->left), item, cmpf);
	else
		btree_insert_data(&((*root)->right), item, cmpf);
}

/* *

#include <stdio.h>
#include <string.h>

void print_str(void *item)
{
    printf("%s\n", (char *)item);
}

int main()
{
    t_btree *root = NULL;

    btree_insert_data(&root, "cosita", (int (*)(void *, void *))strcmp);
    btree_insert_data(&root, "guapa", (int (*)(void *, void *))strcmp);
    btree_insert_data(&root, "rebonica", (int (*)(void *, void *))strcmp);
    btree_apply_infix(root, print_str);
    return (0);
}
* */
