/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_find_next_prime.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: enricant <enricant@42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/15 14:04:11 by enricant          #+#    #+#             */
/*   Updated: 2025/07/15 17:34:00 by enricant         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	is_prime(int num)
{
	int	i;

	if (num <= 1)
		return (0);
	i = 2;
	while (i * i <= num)
	{
		if (num % i == 0)
			return (0);
		i++;
	}
	return (1);
}

int	ft_find_next_prime(int nb)
{
	if (nb <= 1)
		return (2);
	while (1)
	{
		if (is_prime(nb))
			return (nb);
		nb++;
	}
}

/* *
#include <stdio.h>
#include <stdlib.h>

int	main(int argc, char **argv)
{
	int	nb;

	if (argc < 2)
		return (1);
	nb = atoi (argv[1]);
	printf ("next prime to %d is %d\n", nb, ft_find_next_prime(nb));
	return (0);
}
* */
