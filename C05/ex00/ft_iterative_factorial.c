/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_iterative_factorial.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: enricant <enricant@42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/15 12:22:14 by enricant          #+#    #+#             */
/*   Updated: 2025/07/17 20:55:21 by enricant         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_iterative_factorial(int nb)
{
	int	factorial;
	int	i;

	factorial = 1;
	i = 1;
	while (i <= nb)
	{
		factorial *= i;
		i++;
	}
	return (factorial);
}

/* *
#include <stdio.h>
#include <stdlib.h>

int	main(int argc, char **argv)
{
	int	nb;

	if (argc < 2)
	{
		printf ("ERROR: arg1 = numero del que calcular factorial\n");
		return (1);
	}
	nb = atoi (argv[1]);
	printf ("%02d! = %03d\n", nb, ft_iterative_factorial(nb));
	return (0);
}
* */
