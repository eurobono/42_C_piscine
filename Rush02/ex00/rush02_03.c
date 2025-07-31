/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rush02_03.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hventuri <hventuri@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/27 15:27:48 by hventuri          #+#    #+#             */
/*   Updated: 2025/07/28 12:45:21 by enricant         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rush02.h"

int	count_zeros_from_end(char *nbr)
{
	int	len;
	int	count;
	int	i;

	len = ft_strlen(nbr);
	count = 0;
	i = len - 1;
	while (nbr[i] == '0' && i >= 0)
	{
		count ++;
		i--;
	}
	return (count);
}

int	count_zeros_from_ini(char *nbr)
{
	int	len;
	int	count;
	int	i;

	len = ft_strlen(nbr);
	count = 0;
	i = 0;
	while (nbr[i] == '0')
	{
		count ++;
		i++;
	}
	if (count == len)
		count--;
	return (count);
}

void	limpia_nbr(char *nbr)
{
	char	*src;
	int		i;
	int		zeros;

	src = nbr;
	i = 0;
	while (ft_isspace3(nbr[i]))
		i++;
	if (i)
		ft_strcpy(nbr, &nbr[i]);
	zeros = count_zeros_from(nbr, RUSH02_INI);
	if (zeros)
		ft_strcpy(nbr, &nbr[zeros]);
	i = 0;
	while (nbr[i] >= 32 && nbr[i] <= 126)
		i++;
	if (i)
		nbr[i] = 0;
}
