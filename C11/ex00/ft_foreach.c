/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_foreach.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: enricant <enricant@42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/22 20:56:54 by enricant          #+#    #+#             */
/*   Updated: 2025/07/22 21:19:17 by enricant         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

void	ft_foreach(int *tab, int length, void (f)(int))
{
	int	i;

	i = 0;
	while (i < length)
	{
		f(tab[i]);
		i++;
	}
}
/* *
#include <stdio.h>

void	ft_putnbr(int nbr);

int	main(int argc, char **argv)
{
	int	tab_int[]={1,2,3,4,5,6,7,8,9,0,9,8,7,6,5,4,3,2,1,0};

	ft_foreach(tab_int, sizeof(tab_int)/sizeof(int),ft_putnbr);
}
* */
