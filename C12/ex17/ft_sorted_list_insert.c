/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sorted_list_insert.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: enricant <enricant@42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/23 10:52:34 by enricant          #+#    #+#             */
/*   Updated: 2025/07/23 14:51:51 by enricant         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "ft_list.h"

void	ft_sorted_list_insert_aux(t_list **begin_list,
					t_list *pnew, int (*cmp)())
{
	t_list	*plist;
	t_list	*pant;

	pant = 0;
	plist = begin_list[0];
	while (plist)
	{
		if ((*cmp)(plist->data, pnew->data) > 0)
			break ;
		pant = plist;
		plist = plist->next;
	}
	if (!plist)
		return ;
	if (!pnew)
		return ;
	pnew->next = plist;
	if (pant)
		pant->next = pnew;
	else
		begin_list[0] = pnew;
	return ;
}

void	ft_sorted_list_merge(t_list **begin_list1, t_list *begin_list2,
				int (*cmp)())
{
	t_list	*plist;

	plist = begin_list2;
	while (plist)
	{
		ft_sorted_list_insert_aux(begin_list1, plist, cmp);
		plist = plist->next;
	}
	return ;
}
