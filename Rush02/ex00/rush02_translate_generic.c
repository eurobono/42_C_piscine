/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rush02_translate_generic.c                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hventuri <hventuri@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/26 14:58:21 by enricant          #+#    #+#             */
/*   Updated: 2025/07/27 21:30:09 by enricant         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rush02.h"

int	translate_nbr_to_dict_00s_eng_generic(t_dictionary *pdic,
		char *nbr, int *len, int *zeros)
{
	int		rango;
	char	*left;

	rango = get_rango(pdic, nbr);
	*len = ft_strlen(nbr);
	*zeros = count_zeros_from(pdic->pentry[rango].nbr, RUSH02_END);
	if (*zeros <= 0)
		return (1);
	left = malloc (*len - *zeros + 1);
	if (!left)
		return (1);
	ft_memcpy(left, nbr, *len - *zeros);
	left[*len - *zeros] = 0;
	translate_nbr_to_dict_generic(pdic, left);
	free (left);
	ft_putstr(pdic->pentry[rango].translation);
	ft_putstr(" ");
	return (0);
}

int	translate_nbr_to_dict_00s_generic(t_dictionary *pdic, char *nbr)
{
	int	zeros;
	int	len;

	if (translate_nbr_to_dict_00s_eng_generic(pdic, nbr, &len, &zeros))
		return (1);
	if (count_zeros_from(&nbr[len - zeros], RUSH02_END) != zeros)
		translate_nbr_to_dict_generic(pdic, &nbr[len - zeros]);
	return (0);
}

int	translate_nbr_to_dict_generic(t_dictionary *pdic, char *nbr)
{
	int	zeros;
	int	rango;
	int	len;
	int	i;

	zeros = count_zeros_from(nbr, RUSH02_INI);
	nbr = &nbr[zeros];
	rango = get_rango(pdic, nbr);
	if (rango < 0)
		return (1);
	len = ft_strlen(nbr);
	if (!len)
		return (1);
	if (len > 2)
		return (translate_nbr_to_dict_00s_generic(pdic, nbr));
	i = ft_atoi(nbr);
	ft_putstr(pdic->pentry[rango].translation);
	ft_putstr(" ");
	if (i <= 20 || nbr[1] == '0')
		return (0);
	return (translate_nbr_to_dict_generic(pdic, &nbr[1]));
}
