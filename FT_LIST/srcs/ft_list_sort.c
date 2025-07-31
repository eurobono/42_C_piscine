/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_list_sort.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: enricant <enricant@42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/23 10:52:34 by enricant          #+#    #+#             */
/*   Updated: 2025/07/23 14:12:51 by enricant         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "ft_list.h"

void	ft_list_move_list_up(t_list *plist)
{
	t_list	*pnext;
	t_list	*paux;

	if (!plist->next)
		return ;
	pnext = plist->next;
	paux = pnext->next;
	pnext->next = plist;
	plist->next = paux;
}

void	ft_list_sort(t_list **begin_list, int (*cmp)())
{
	t_list	*plist;
	int		count;

	while (1)
	{
		count = 0;
		plist = begin_list[0];
		while (plist->next)
		{
			if ((*cmp)(plist->data, plist->next->data) > 0)
			{
				if (plist == begin_list[0])
					begin_list[0] = plist->next;
				ft_list_move_list_up(plist);
				count++;
			}
			plist = plist->next;
		}
		if (count)
			break ;
	}
	return ;
}
