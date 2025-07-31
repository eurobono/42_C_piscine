/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rush02_translate_spa01.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hventuri <hventuri@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/26 14:58:21 by enricant          #+#    #+#             */
/*   Updated: 2025/07/30 18:18:19 by enricant         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rush02.h"

int	translate_nbr_to_dict_00s_spa_bis_header(t_dictionary *pdic,
		char *nbr, int *len, int *zeros)
{
	char	*left;

	if (*zeros <= 0)
		return (1);
	left = malloc (*len - *zeros + 1);
	if (!left)
		return (1);
	ft_memcpy(left, nbr, *len - *zeros);
	left[*len - *zeros] = 0;
	if (*zeros > 4
		&& (*len - *zeros > 0 && left[*len - *zeros - 1] == '1'))
		left[*len - *zeros - 1] = 'A';
	translate_nbr_to_dict_spa(pdic, left);
	free (left);
	return (0);
}

int	translate_nbr_to_dict_00s_spa_bis(t_dictionary *pdic,
		char *nbr, int *len, int *zeros)
{
	int		rango;

	rango = get_rango(pdic, nbr);
	*len = ft_strlen(nbr);
	*zeros = count_zeros_from(pdic->pentry[rango].nbr, RUSH02_END);
	if (translate_nbr_to_dict_00s_spa_bis_header(pdic, nbr, len, zeros))
		return (1);
	ft_putstr(pdic->pentry[rango].translation);
	if ((*zeros >= 4 && *len == *zeros + 1 && (nbr[*len - *zeros - 1] == '1'))
		|| (*zeros == 3))
		ft_putstr(" ");
	else
		ft_putstr("es ");
	return (0);
}

int	translate_nbr_to_dict_00s_spa(t_dictionary *pdic, char *nbr)
{
	int		zeros;
	int		len;

	if (translate_nbr_to_dict_00s_spa_bis(pdic, nbr, &len, &zeros))
		return (1);
	if (count_zeros_from(&nbr[len - zeros], RUSH02_END) != zeros)
		translate_nbr_to_dict_spa(pdic, &nbr[len - zeros]);
	return (0);
}
