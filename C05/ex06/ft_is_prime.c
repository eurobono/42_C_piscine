/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_is_prime.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: enricant <enricant@42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/15 13:52:00 by enricant          #+#    #+#             */
/*   Updated: 2025/07/15 17:34:18 by enricant         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_is_prime(int nb)
{
	int	i;

	if (nb <= 1)
		return (0);
	else if (nb == 2)
		return (1);
	i = 2;
	while (i < nb)
	{
		if (nb % i == 0)
			return (0);
		i++;
	}
	return (1);
}

/* *
#include <stdio.h>
#include <stdlib.h>

int	main(int argc, char **argv)
{
	int	nb;

	if (argc < 2)
		return (1);
	nb = atoi(argv[1]);
	printf ("%d is prime = %d\n", nb, ft_is_prime(nb));
	return (0);
}

* */
