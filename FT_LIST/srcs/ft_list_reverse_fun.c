/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_list_reverse_fun.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: enricant <enricant@42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/23 10:52:34 by enricant          #+#    #+#             */
/*   Updated: 2025/07/23 14:22:49 by enricant         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "ft_list.h"

void	ft_list_reverse_fun(t_list *begin_list)
{
	t_list	*plist;
	t_list	*pant;
	t_list	*paux;

	pant = 0;
	plist = begin_list;
	while (plist)
	{
		paux = plist->next;
		plist->next = pant;
		pant = plist;
		plist = paux;
	}
	return ;
}
