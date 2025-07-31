/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sqrt.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: enricant <enricant@42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/15 13:16:50 by enricant          #+#    #+#             */
/*   Updated: 2025/07/15 17:34:59 by enricant         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_sqrt_calc(int nb)
{
	long long	cuadrado;
	int			raiz;
	int			izquierda;
	int			derecha;
	int			medio;

	raiz = 0;
	izquierda = 1;
	derecha = nb;
	while (izquierda <= derecha)
	{
		medio = izquierda + (derecha - izquierda) / 2;
		cuadrado = (long long)medio * medio;
		if (cuadrado == nb)
			return (medio);
		else if (cuadrado < nb)
		{
			raiz = medio;
			izquierda = medio + 1;
		}
		else
			derecha = medio - 1;
	}
	return (raiz);
}

int	ft_sqrt(int nb)
{
	int	raiz;

	if (nb <= 0)
		return (0);
	raiz = ft_sqrt_calc(nb);
	if ((long long)raiz * raiz == nb)
		return (raiz);
	return (0);
}

/* *
#include <stdio.h>
#include <stdlib.h>

int	main(int argc, char **argv)
{
	int	nb;

	if (argc < 2)
		return (-1);
	nb = atoi(argv[1]);
	printf ("sqrt(%d)=%d\n", nb, ft_sqrt(nb));
	return (0);
}
* */
