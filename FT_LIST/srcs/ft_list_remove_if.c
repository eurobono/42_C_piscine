/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_list_remove_if.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: enricant <enricant@42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/23 10:52:34 by enricant          #+#    #+#             */
/*   Updated: 2025/07/23 13:47:09 by enricant         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "ft_list.h"

void	ft_list_remove_if(t_list **begin_list, void *data_ref,
				int (*cmp)(), void (*free_fct)(void *))
{
	t_list	*plist;
	t_list	*pant;

	pant = 0;
	plist = begin_list[0];
	while (plist)
	{
		if (!(*cmp)(plist->data, data_ref))
		{
			if (pant)
				pant->next = plist->next;
			(*free_fct)(plist->data);
			free(plist);
		}
		else
			pant = plist;
		plist = plist->next;
	}
	return ;
}
