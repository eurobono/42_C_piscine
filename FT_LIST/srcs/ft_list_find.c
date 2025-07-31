/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_list_find.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: enricant <enricant@42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/23 10:52:34 by enricant          #+#    #+#             */
/*   Updated: 2025/07/23 13:35:21 by enricant         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "ft_list.h"

t_list	*ft_list_find(t_list *begin_list, void *data_ref, int (*cmp)())
{
	t_list	*plist;

	plist = begin_list;
	while (plist)
	{
		if (!(*cmp)(plist->data, data_ref))
			return (plist);
		plist = plist->next;
	}
	return (0);
}
