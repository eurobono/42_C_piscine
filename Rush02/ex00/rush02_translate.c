/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rush02_translate.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hventuri <hventuri@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/26 14:58:21 by enricant          #+#    #+#             */
/*   Updated: 2025/07/28 12:46:25 by enricant         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rush02.h"

int	count_zeros_from(char *nbr, int from)
{
	if (from == RUSH02_END)
		return (count_zeros_from_end(nbr));
	else if (from == RUSH02_INI)
		return (count_zeros_from_ini(nbr));
	return (0);
}

int	get_rango(t_dictionary *pdic, char *nbr)
{
	t_dic_entry	*p;
	int			i;

	p = pdic->pentry;
	i = 0;
	while (i <= pdic->last_entry)
	{
		if (ft_strlen(p[i].nbr) > ft_strlen(nbr))
			break ;
		else if (ft_strlen(p[i].nbr) == ft_strlen(nbr)
			&& ft_strcmp(p[i].nbr, nbr) > 0)
			break ;
		else if (ft_strlen(p[i].nbr) == ft_strlen(nbr)
			&& ft_strcmp(p[i].nbr, nbr) == 0)
			return (i);
		i++;
	}
	return (i - 1);
}

int	translate_nbr_to_dict_00s(t_dictionary *pdic, char *nbr)
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
	translate_nbr_to_dict(pdic, left);
	free (left);
	ft_putstr(pdic->pentry[rango].translation);
	ft_putstr(" ");
	if (count_zeros_from(&nbr[len - zeros], RUSH02_END) != zeros)
		translate_nbr_to_dict(pdic, &nbr[len - zeros]);
	return (0);
}

int	translate_nbr_to_dict_aux(t_dictionary *pdic, char *nbr,
		int *len, int *rango)
{
	int	zeros;

	zeros = count_zeros_from(nbr, RUSH02_INI);
	nbr = &nbr[zeros];
	*rango = get_rango(pdic, nbr);
	if (*rango < 0)
		return (1);
	*len = ft_strlen(nbr);
	if (!*len)
		return (1);
	return (0);
}

int	translate_nbr_to_dict(t_dictionary *pdic, char *nbr)
{
	int	rango;

	if (!pdic || !nbr)
		return (1);
	if (!ft_strlen(nbr))
		return (1);
	rango = get_rango(pdic, RUSH02_NBR_TRX);
	if (rango < 0)
		return (translate_nbr_to_dict_generic(pdic, nbr));
	if (!ft_strcmp(pdic->pentry[rango].translation, RUSH02_NBR_ENG))
		return (translate_nbr_to_dict_eng(pdic, nbr));
	else if (!ft_strcmp(pdic->pentry[rango].translation, RUSH02_NBR_SPA))
		return (translate_nbr_to_dict_spa(pdic, nbr));
	else if (!ft_strcmp(pdic->pentry[rango].translation, RUSH02_NBR_FRN))
		return (translate_nbr_to_dict_frn(pdic, nbr));
	else
		return (translate_nbr_to_dict_generic(pdic, nbr));
	return (0);
}
