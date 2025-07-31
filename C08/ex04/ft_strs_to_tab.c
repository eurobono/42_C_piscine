/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strs_to_tab.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: enricant <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/17 21:57:46 by enricant          #+#    #+#             */
/*   Updated: 2025/07/24 10:15:17 by enricant         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "ft_stock_str.h"

int	ft_strlen(char *str)
{
	int	i;

	i = 0;
	while (str[i])
		i++;
	return (i);
}

void	ft_libera_stockstr(struct s_stock_str *pstockstr)
{
	int	i;

	if (!pstockstr)
		return ;
	i = 0;
	while (pstockstr[i].str)
	{
		if (pstockstr[i].copy)
			free (pstockstr[i].copy);
		i ++;
	}
	free (pstockstr);
	return ;
}

int	ft_init_stockstr(struct s_stock_str *pstockstr, char *str)
{
	int		j;

	pstockstr->size = ft_strlen(str);
	pstockstr->str = 0;
	pstockstr->copy = malloc(pstockstr->size + 1);
	if (!pstockstr->copy)
		return (1);
	pstockstr->str = str;
	j = 0;
	while (pstockstr->str[j])
	{
		pstockstr->copy[j] = pstockstr->str[j];
		j++;
	}
	pstockstr->copy[j] = 0;
	return (0);
}

struct s_stock_str	*ft_strs_to_tab(int ac, char **av)
{
	struct s_stock_str	*pstockstr;
	int					i;

	pstockstr = malloc(sizeof(struct s_stock_str) * (ac + 1));
	if (!pstockstr)
		return (NULL);
	i = 0;
	while (i < ac)
	{
		if (ft_init_stockstr(&pstockstr[i], av[i]))
		{
			ft_libera_stockstr(pstockstr);
			return (NULL);
		}
		i++;
	}
	pstockstr[i].str = 0;
	return (pstockstr);
}

/* *

#include <stdio.h>

int	main(int argc, char **argv)
{
	struct s_stock_str	*pstockstr;
	int					i;

	pstockstr = ft_strs_to_tab(argc, argv);
	if (!pstockstr)
		return (1);
	i = 0;
	while (pstockstr[i].str)
	{
		printf ("\"%s\" %02d\n\"%s\"\n", pstockstr[i].str,
			pstockstr[i].size, pstockstr[i].copy);
		i++;
	}
	ft_libera_stockstr(pstockstr);
	return (0);
}
* */
