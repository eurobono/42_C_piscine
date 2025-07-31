/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_recursive_power.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: enricant <enricant@42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/15 12:57:41 by enricant          #+#    #+#             */
/*   Updated: 2025/07/15 17:35:30 by enricant         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_recursive_power(int nb, int power)
{
	if (power < 0)
		return (0);
	else if (power == 0)
		return (1);
	else
		return (nb * ft_recursive_power(nb, power - 1));
}

/* *
#include <stdio.h>
#include <stdlib.h>

int	main(int argc, char **argv)
{
	int	nb;
	int	power;

	if (argc < 3)
		return (1);
	nb = atoi(argv[1]);
	power = atoi(argv[2]);
	printf ("%d ^ %d = %d\n", nb, power, ft_recursive_power(nb, power));
	return (0);
}
* */
