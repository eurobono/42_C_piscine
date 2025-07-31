/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_iterative_power.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: enricant <enricant@42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/15 12:48:48 by enricant          #+#    #+#             */
/*   Updated: 2025/07/15 17:35:53 by enricant         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_iterative_power(int nb, int power)
{
	int	resultado;
	int	i;

	if (power < 0)
		return (0);
	else if (power == 0)
		return (1);
	resultado = 1;
	i = 0;
	while (i < power)
	{
		resultado *= nb;
		i++;
	}
	return (resultado);
}

/* *
#include <stdio.h>
#include <stdlib.h>

int	main(int argc, char	**argv)
{
	int	nb;
	int	power;

	if (argc < 3)
		return (1);
	nb = atoi(argv[1]);
	power = atoi(argv[2]);
	printf ("%d ^ %d = %d\n", nb, power, ft_iterative_power(nb, power));
	return (0);
}
* */
