/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rush02_translate_spa.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hventuri <hventuri@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/26 14:58:21 by enricant          #+#    #+#             */
/*   Updated: 2025/07/30 18:02:40 by enricant         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rush02.h"

int	translate_nbr_to_dict_00s_spa(t_dictionary *pdic, char *nbr);

int	translate_nbr_spa_rule_1000s(t_dictionary *pdic, char *nbr)
{
	ft_putstr("mil");
	if (!ft_strcmp(nbr, "1000"))
	{
		ft_putstr(" ");
		return (0);
	}
	ft_putstr(" ");
	return (translate_nbr_to_dict_spa(pdic, &nbr[1]));
}

int	translate_nbr_spa_rule_100s(t_dictionary *pdic, char *nbr, int rango)
{
	ft_putstr(pdic->pentry[rango].translation);
	if (!ft_strcmp(nbr, "100"))
	{
		ft_putstr(" ");
		return (0);
	}
	if (nbr[0] == '1')
		ft_putstr("to");
	ft_putstr(" ");
	return (translate_nbr_to_dict_spa(pdic, &nbr[1]));
}

int	translate_nbr_to_dict_spa(t_dictionary *pdic, char *nbr)
{
	int	rango;
	int	len;
	int	i;

	if (translate_nbr_to_dict_aux(pdic, nbr, &len, &rango))
		return (1);
	if (len == 4 && nbr[0] == '1')
		return (translate_nbr_spa_rule_1000s(pdic, nbr));
	else if (len == 3)
		return (translate_nbr_spa_rule_100s(pdic, nbr, rango));
	else if (len > 3)
		return (translate_nbr_to_dict_00s_spa(pdic, nbr));
	if (len == 1 && nbr[1] == 'A')
	{
		ft_putstr("un ");
		return (0);
	}
	ft_putstr(pdic->pentry[rango].translation);
	ft_putstr(" ");
	i = ft_atoi(nbr);
	if (i <= 30 || nbr[1] == '0')
		return (0);
	ft_putstr("y ");
	return (translate_nbr_to_dict_spa(pdic, &nbr[1]));
}
