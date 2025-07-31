/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rush02_translate_frn.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hventuri <hventuri@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/26 14:58:21 by enricant          #+#    #+#             */
/*   Updated: 2025/07/27 21:29:48 by enricant         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rush02.h"

int	translate_nbr_to_dict_00s_frn(t_dictionary *pdic, char *nbr)
{
	int		rango;
	int		zeros;
	int		len;
	char	*left;

	rango = get_rango(pdic, nbr);
	len = ft_strlen(nbr);
	zeros = count_zeros_from(pdic->pentry[rango].nbr, RUSH02_END);
	if (zeros <= 0)
		return (1);
	left = malloc (len - zeros + 1);
	if (!left)
		return (1);
	ft_memcpy(left, nbr, len - zeros);
	left[len - zeros] = 0;
	translate_nbr_to_dict_frn(pdic, left);
	free (left);
	ft_putstr(pdic->pentry[rango].translation);
	ft_putstr(" ");
	if (count_zeros_from(&nbr[len - zeros], RUSH02_END) != zeros)
		translate_nbr_to_dict_frn(pdic, &nbr[len - zeros]);
	return (0);
}

int	translate_nbr_to_dict_frn(t_dictionary *pdic, char *nbr)
{
	int	rango;
	int	len;
	int	i;

	if (translate_nbr_to_dict_aux(pdic, nbr, &len, &rango))
		return (1);
	if (len == 4 && nbr[0] == '1')
	{
		ft_putstr("mille");
		if (!ft_strcmp(nbr, "1000"))
			return (0);
		ft_putstr(" ");
		return (translate_nbr_to_dict_frn(pdic, &nbr[1]));
	}
	else if (len > 2)
		return (translate_nbr_to_dict_00s_frn(pdic, nbr));
	i = ft_atoi(nbr);
	ft_putstr(pdic->pentry[rango].translation);
	ft_putstr(" ");
	if (i <= 30 || nbr[1] == '0')
		return (0);
	ft_putstr("y ");
	return (translate_nbr_to_dict_frn(pdic, &nbr[1]));
}
