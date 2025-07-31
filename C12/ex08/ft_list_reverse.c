/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_list_reverse.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: enricant <enricant@42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/23 10:52:34 by enricant          #+#    #+#             */
/*   Updated: 2025/07/23 16:13:27 by enricant         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "ft_list.h"

void	ft_list_reverse(t_list **begin_list)
{
	t_list	*pcurrent;
	t_list	*pfollowing;
	t_list	*paux;

	pcurrent = begin_list[0];
	pfollowing = pcurrent->next;
	pcurrent->next = 0;
	while (pfollowing)
	{
		paux = pfollowing->next;
		pfollowing->next = pcurrent;
		pcurrent = pfollowing;
		pfollowing = paux;
	}
	begin_list[0] = pcurrent;
	return ;
}
