/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   btree_apply_by_level.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: enricant <enricant@42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/23 10:52:34 by enricant          #+#    #+#             */
/*   Updated: 2025/07/25 11:05:21 by enricant         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "ft_btree.h"

typedef struct s_queue_node
{
	struct s_queue_node	*next;
	t_btree				*node;
	int					level;
}	t_queue_node;

void	enqueue(t_queue_node **head, t_btree *node, int level)
{
	t_queue_node	*new;
	t_queue_node	*tmp;

	new = malloc(sizeof(t_queue_node));
	if (!new)
		return ;
	new->node = node;
	new->level = level;
	new->next = NULL;
	if (!*head)
		*head = new;
	else
	{
		tmp = *head;
		while (tmp->next)
			tmp = tmp->next;
		tmp->next = new;
	}
}

t_queue_node	*dequeue(t_queue_node **head)
{
	t_queue_node	*node;

	if (!*head)
		return (NULL);
	node = *head;
	*head = node->next;
	return (node);
}

void	btree_apply_by_level_aux(t_queue_node **pqueue, int *current_level,
		t_btree *root,
		void (*applyf)(void *item, int level, int is_first_elem))
{
	t_queue_node	*qnode;
	t_btree			*node;
	int				level;
	int				is_first;

	qnode = dequeue(pqueue);
	node = qnode->node;
	level = qnode->level;
	is_first = (level != *current_level);
	*current_level = level;
	applyf(node->item, level, is_first);
	if (node->left)
		enqueue(pqueue, node->left, level + 1);
	if (node->right)
		enqueue(pqueue, node->right, level + 1);
	free(qnode);
}

void	btree_apply_by_level(t_btree *root,
		void (*applyf)(void *item, int level, int is_first_elem))
{
	t_queue_node	*queue;
	int				cur_level;

	if (!root || !applyf)
		return ;
	queue = NULL;
	enqueue(&queue, root, 0);
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

void print_node(void *item, int level, int is_first_elem)
{
	printf("Tree level %02d\"%s\": \"%s\"\n",
		level, is_first_elem ? "ROOT" : "", (char *)item);
}

int main()
{
	t_btree	*root;

	root = NULL;

	btree_insert_data(&root, "jose", (int (*)(void *, void *))strcmp);
	btree_insert_data(&root, "enrique", (int (*)(void *, void *))strcmp);
	btree_insert_data(&root, "cantero", (int (*)(void *, void *))strcmp);
	btree_insert_data(&root, "diaz", (int (*)(void *, void *))strcmp);

	btree_apply_by_level(root, print_node);
	btree_free(root, 0);

return 0;
}
* */
