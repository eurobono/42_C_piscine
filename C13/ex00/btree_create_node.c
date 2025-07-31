/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   btree_create_node.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: enricant <enricant@42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/23 10:52:34 by enricant          #+#    #+#             */
/*   Updated: 2025/07/23 17:13:51 by enricant         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "ft_btree.h"

t_btree	*btree_create_node(void *item)
{
	t_btree	*pbtree;

	pbtree = malloc(sizeof(t_btree));
	if (!pbtree)
		return (0);
	pbtree->item = item;
	return (pbtree);
}
