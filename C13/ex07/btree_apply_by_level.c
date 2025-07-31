/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   btree_apply_by_level.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: enricant <enricant@42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/23 10:52:34 by enricant          #+#    #+#             */
/*   Updated: 2025/07/25 13:39:39 by enricant         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "ft_btree.h"

void	queue_insert(t_btree **head, t_btree *node, long level)
{
	t_btree	*new;
	t_btree	*tmp;

	new = malloc(sizeof(t_btree));
	if (!new)
		return ;
	new->left = node;
	new->item = (void *)level;
	new->right = NULL;
	if (!*head)
		*head = new;
	else
	{
		tmp = *head;
		while (tmp->right)
			tmp = tmp->right;
		tmp->right = new;
	}
}

t_btree	*queue_remove(t_btree **head)
{
	t_btree	*node;

	if (!*head)
		return (NULL);
	node = *head;
	*head = node->right;
	return (node);
}

void	btree_apply_by_level_aux(t_btree **pqueue, int *current_level,
		t_btree *root,
		void (*applyf)(void *item, int level, int is_first_elem))
{
	t_btree	*qnode;
	t_btree	*node;
	long	level;
	int		is_first;

	qnode = queue_remove(pqueue);
	node = qnode->left;
	level = (long)qnode->item;
	is_first = (level != *current_level);
	*current_level = level;
	applyf(node->item, level, is_first);
	if (node->left)
		queue_insert(pqueue, node->left, level + 1);
	if (node->right)
		queue_insert(pqueue, node->right, level + 1);
	free(qnode);
	root = (void *)0;
}

void	btree_apply_by_level(t_btree *root,
		void (*applyf)(void *item, int level, int is_first_elem))
{
	t_btree	*queue;
	int		cur_level;

	if (!root || !applyf)
		return ;
	queue = NULL;
	queue_insert(&queue, root, 0);
	cur_level = -1;
	while (queue)
		btree_apply_by_level_aux(&queue, &cur_level, root, applyf);
}

void	btree_free(t_btree *root, void (*freef)(void *))
{
	if (!root)
		return ;
	btree_free(root->left, freef);
	btree_free(root->right, freef);
	if (freef)
		freef(root->item);
	free(root);
}

/* *
#include <stdio.h>
#include <string.h>

void	print_node(void *item, int level, int is_first_elem)
{
	printf("Tree level %02d \"%s\": \"%s\"\n",
		level, is_first_elem ? "ROOT" : "", (char *)item);
}

int	main(void)
{
	t_btree	*root;

	root = NULL;
	btree_insert_data(&root, "jose", (int (*)(void *, void *))strcmp);
	btree_insert_data(&root, "enrique", (int (*)(void *, void *))strcmp);
	btree_insert_data(&root, "cantero", (int (*)(void *, void *))strcmp);
	btree_insert_data(&root, "diaz", (int (*)(void *, void *))strcmp);
	btree_insert_data(&root, "jose", (int (*)(void *, void *))strcmp);
	btree_insert_data(&root, "enrique", (int (*)(void *, void *))strcmp);
	btree_insert_data(&root, "cantero", (int (*)(void *, void *))strcmp);
	btree_insert_data(&root, "diaz", (int (*)(void *, void *))strcmp);
	btree_insert_data(&root, "juan", (int (*)(void *, void *))strcmp);
	btree_insert_data(&root, "ramirez", (int (*)(void *, void *))strcmp);
	btree_insert_data(&root, "vazquez", (int (*)(void *, void *))strcmp);
	btree_insert_data(&root, "cantero", (int (*)(void *, void *))strcmp);
	btree_apply_by_level(root, print_node);
	btree_free(root, 0);
	return (0);
}
* */
