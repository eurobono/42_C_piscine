/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ten_queens_puzzle.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: enricant <enricant@42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/15 14:14:49 by enricant          #+#    #+#             */
/*   Updated: 2025/07/17 20:56:22 by enricant         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

#define N 10

int	ft_draw_solutions(int *solutions)
{
	char	c;
	int		i;

	i = 0;
	while (i < N)
	{
		c = solutions[i] + '0';
		write (1, &c, 1);
		i++;
	}
	c = '\n';
	write (1, &c, 1);
	return (1);
}

int	ft_abs(int nb)
{
	if (nb < 0)
		return (nb * -1);
	else
		return (nb);
}

int	ft_is_valid_position(int *solutions, int row, int column)
{
	int	i;

	i = 0;
	while (i < row)
	{
		if (solutions[i] == column)
			return (0);
		if (ft_abs(solutions[i] - column) == ft_abs(i - row))
			return (0);
		i++;
	}
	return (1);
}

int	ft_solve_puzzle(int *solutions, int row)
{
	int	total;
	int	column;

	if (row == N)
		return (ft_draw_solutions (solutions));
	total = 0;
	column = 0;
	while (column < N)
	{
		if (ft_is_valid_position(solutions, row, column))
		{
			solutions[row] = column;
			total += ft_solve_puzzle(solutions, row + 1);
		}
		column++;
	}
	return (total);
}

int	ft_ten_queens_puzzle(void)
{
	int	solutions[N];
	int	i;

	i = 0;
	while (i < N)
		solutions[i++] = 0;
	return (ft_solve_puzzle(solutions, 0));
}

/* *

#include <stdio.h>

// Programa principal solo para prueba
int	main(void)
{
	printf ("Número total de soluciones: %d\n", ft_ten_queens_puzzle());
	return (0);
}

* */
