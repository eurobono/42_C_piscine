/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_recursive_factorial.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: enricant <enricant@42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/15 12:32:34 by enricant          #+#    #+#             */
/*   Updated: 2025/07/15 17:36:14 by enricant         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_recursive_factorial(int nb)
{
	if (nb < 0)
	{
		return (0);
	}
	else if (nb == 0)
	{
		return (1);
	}
	else
	{
		return (nb * ft_recursive_factorial(nb - 1));
	}
}

/* *
#include <stdio.h>
#include <stdlib.h>

int	main(int argc, char **argv)
{
	int	num;
	int	resultado;

	if (argc < 2)
		return (1);
	num = atoi (argv[1]);
	resultado = ft_recursive_factorial(num);
	if (resultado == 0 && num < 0)
		printf("%d! no está definido (argumento inválido).\n", num);
	else
		printf("%d! = %d\n", num, resultado);
	return (0);
}
* */
