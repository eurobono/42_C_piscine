/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   btree_search_item.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: enricant <enricant@42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/23 10:52:34 by enricant          #+#    #+#             */
/*   Updated: 2025/07/24 16:22:14 by enricant         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "ft_btree.h"

void	*btree_search_item(t_btree *root, void *data_ref,
		int (*cmpf)(void *, void *))
{
	void	*result;

	if (!root || !cmpf)
		return (NULL);
	result = btree_search_item(root->left, data_ref, cmpf);
	if (result)
		return (result);
	if (cmpf(root->item, data_ref) == 0)
		return (root->item);
	return (btree_search_item(root->right, data_ref, cmpf));
}

/* *
#include <stdio.h>
#include <string.h>

int main()
{
    t_btree *root = NULL;

    btree_insert_data(&root, "cosita", (int (*)(void *, void *))strcmp);
    btree_insert_data(&root, "guapa", (int (*)(void *, void *))strcmp);
    btree_insert_data(&root, "rebonica", (int (*)(void *, void *))strcmp);

    char *target = "guapa";
    char *found = btree_search_item(root, target,
    			(int (*)(void *, void *))strcmp);

    if (found)
        printf("Found: %s\n", found);
    else
        printf("Not found.\n");

    return 0;
}
* */
