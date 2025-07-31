/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_list_push_strs.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: enricant <enricant@42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/23 10:52:34 by enricant          #+#    #+#             */
/*   Updated: 2025/07/31 11:24:31 by enricant         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "ft_list.h"

t_list	*ft_list_push_strs(int size, char **strs)
{
	t_list	*plist;
	t_list	*begin_list;

	if (!strs)
		return (0);
	begin_list = ft_create_elem(*strs++);
	if (!begin_list)
		return (0);
	while (*strs)
	{
		plist = ft_create_elem(*strs++);
		if (plist)
		{
			plist->next = begin_list;
			begin_list = plist;
		}
	}
	size++;
	return (begin_list);
}
