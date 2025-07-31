/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sorted_list_insert.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: enricant <enricant@42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/23 10:52:34 by enricant          #+#    #+#             */
/*   Updated: 2025/07/23 14:41:56 by enricant         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "ft_list.h"

void	ft_sorted_list_insert(t_list **begin_list, void *data, int (*cmp)())
{
	t_list	*plist;
	t_list	*pant;
	t_list	*pnew;

	pant = 0;
	plist = begin_list[0];
	while (plist)
	{
		if ((*cmp)(plist->data, data) > 0)
			break ;
		pant = plist;
		plist = plist->next;
	}
	if (!plist)
		return ;
	pnew = ft_create_elem(data);
	if (!pnew)
		return ;
	pnew->next = plist;
	if (pant)
		pant->next = pnew;
	else
		begin_list[0] = pnew;
	return ;
}
