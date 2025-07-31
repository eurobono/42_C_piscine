/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_list_foreach_if.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: enricant <enricant@42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/23 10:52:34 by enricant          #+#    #+#             */
/*   Updated: 2025/07/31 11:27:43 by enricant         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "ft_list.h"

void	ft_list_foreach_if(t_list *begin_list,
				void (*f)(void *),
				void *data_ref,	int (*cmp)())
{
	t_list	*plist;

	plist = begin_list;
	while (plist)
	{
		if (!(*cmp)(plist->data, data_ref))
			(*f)(plist->data);
		plist = plist->next;
	}
	return ;
}
