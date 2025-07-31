/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_map.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: enricant <enricant@42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/22 21:20:19 by enricant          #+#    #+#             */
/*   Updated: 2025/07/29 17:55:10 by enricant         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include <stdlib.h>

int	*ft_map(int *tab, int length, int (*f)(int))
{
	int	*ptab;
	int	i;

	ptab = malloc(sizeof(int) * length);
	if (!tab)
		return (0);
	i = 0;
	while (i < length)
	{
		ptab[i] = f(ptab[i]);
		i++;
	}
	return (ptab);
}
/* *
#include <stdio.h>

int	my_func(int nbr)
{
	printf ("%d\n", nbr);
}

int	main(void)
{
	int	tabla[]={1,3,5,7,9,0,8,6,4,2,0};
	int	*ptab;

	ptab = ft_map(tabla, sizeof(tabla)/sizeof(int),my_func);
	if  (!ptab)
		printf ("NULL pTAB\n");
	else
		free (ptab);
	return (0);
}
* */
