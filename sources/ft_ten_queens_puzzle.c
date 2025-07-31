/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ten_queens_puzzle.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: enricant <enricant@student.42madrid.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/10 13:00:00 by enricant          #+#    #+#             */
/*   Updated: 2025/07/14 11:49:52 by enricant         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include <unistd.h>

#define N 10

void	imprimir_tablero(int tablero[N][N])
{
	char	digit;
	int		i;
	int		j;

	i = 0;
	while (i < N)
	{
		j = 0;
		while (j < N)
		{
			digit = '0' + tablero[i][j];
			write (1, &digit, 1);
			j++;
		}
		digit = '\n';
		write (1, &digit, 1);
		i++;
	}
}

int	es_seguro(int tablero[N][N], int fila, int columna)
{
	int	i;
	int	j;

	i = 0;
	while (i < fila)
		if (tablero[i++][columna] == 1)
			return (0);
	i = fila;
	j = columna;
	while (i >= 0 && j >= 0)
		if (tablero[i--][j--] == 1)
			return (0);
	i = fila;
	j = columna;
	while (i >= 0 && j < N)
		if (tablero[i--][j++] == 1)
			return (0);
	return (1);
}

int	resolver_ocho_reinas(int tablero[N][N], int fila)
{
	int	columna;

	if (fila >= N)
		return (1);
	columna = 0;
	while (columna < N)
	{
		if (es_seguro(tablero, fila, columna))
		{
			tablero[fila][columna] = 1;
			if (resolver_ocho_reinas(tablero, fila + 1))
				return (1);
		}
		tablero [fila][columna] = 0;
		columna++;
	}
	return (0);
}

int	ft_ten_queens_puzzle(void)
{
	int	tablero[N][N];
	int	i;
	int	j;

	i = 0;
	while (i < N)
	{
		j = 0;
		while (j < N)
		{
			tablero[i][j] = 0;
			j++;
		}
		i++;
	}
	if (resolver_ocho_reinas(tablero, 0) == 0)
	{
		write (1, "No hay solución\n", 16);
		return (0);
	}
	imprimir_tablero(tablero);
	return (1);
}

/* */
int	main(void)
{
	ft_ten_queens_puzzle();
	return (0);
}
/* */
