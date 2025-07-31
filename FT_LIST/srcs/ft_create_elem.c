/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_create_elem.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: enricant <enricant@42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/23 10:52:34 by enricant          #+#    #+#             */
/*   Updated: 2025/07/31 11:13:28 by enricant         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "ft_list.h"

void	ft_init_elem(t_list *plist, t_list *next, void *data)
{
	if (!plist)
		return ;
	plist->next = next;
	plist->data = data;
	return ;
}

t_list	*ft_create_elem(void *data)
{
	t_list	*plist;

	plist = malloc(sizeof(t_list));
	if (!plist)
		return (0);
	ft_init_elem(plist, 0, data);
	return (plist);
}
