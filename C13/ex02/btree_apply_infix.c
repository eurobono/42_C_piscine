/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   btree_apply_infix.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: enricant <enricant@42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/23 10:52:34 by enricant          #+#    #+#             */
/*   Updated: 2025/07/24 15:41:41 by enricant         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "ft_btree.h"

void	btree_apply_infix(t_btree *root, void (*applyf)(void *))
{
	if (!root || !applyf)
		return ;
	btree_apply_infix(root->left, applyf);
	applyf(root->item);
	btree_apply_infix(root->right, applyf);
}

/* *
#include <stdio.h>

void print_str(void *item)
{
    printf("%s\n", (char *)item);
}

void    init_node(t_btree *node, void *item,
                struct s_btree *left, struct s_btree *right)
{
        node->item = item;
        node->left = left;
        node->right = right;
}

int main()
{
    t_btree node3;
    t_btree node2;
    t_btree node1;

    init_node(&node3, "node 3", NULL, NULL);
    init_node(&node2, "node 2", NULL, NULL);
    init_node(&node1, "node 1", &node2, &node3);

    btree_apply_infix(&node1, print_str);
    return (0);
}
* */
