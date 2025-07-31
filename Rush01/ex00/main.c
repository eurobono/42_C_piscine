/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: enricant <enricant@42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/19 12:19:28 by enricant          #+#    #+#             */
/*   Updated: 2025/07/20 22:21:55 by enricant         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include <stdio.h>
#include "puzzle.h"

void	draw_constraints(t_puzzle *ppuzzle)
{
	char	c;
	int		i;

	i = 0;
	while (i < 4 * ppuzzle->size)
	{
		c = ppuzzle->constraints[i] + '0';
		write (1, &c, 1);
		if (i % ppuzzle->size == ppuzzle->size - 1)
			c = '\n';
		else
			c = ' ';
		write (1, &c, 1);
		i ++;
	}
}

void	init_constraints(t_puzzle *ppuzzle)
{
	int	i;

	i = 0;
	while (i < ppuzzle->size)
	{
		ppuzzle->constraints[i] = 0;
		i ++;
	}
	i = 0;
	while (i < ppuzzle->size)
	{
		ppuzzle->constraints[i] = 0;
		i ++;
	}
}

int	get_constraints(t_puzzle *ppuzzle, char *constraints)
{
	int	i;
	int	count;
	int	size;
	int	nbr;

	init_constraints(ppuzzle);
	i = 0;
	count = 0;
	size = 4 * ppuzzle->size;
	while (count < size)
	{
		nbr = constraints[i] - '0';
		if (nbr <= 0 || nbr > ppuzzle->figures)
			return (1);
		ppuzzle->constraints[count] = nbr;
		count++;
		i += 2;
	}
	return (0);
}

void	play_puzzle(t_puzzle *ppuzzle)
{
	validate_solution(ppuzzle, 0, 0, 1);
	if (!ppuzzle->solutions)
		ft_putstr("Error\n");
}

int	main(int argc, char **argv)
{
	t_puzzle	*ppuzzle;
	int			size;

	if (argc < 2)
	{
		ft_putstr ("Error\n");
		return (1);
	}
	size = 4;
	if (argc > 2)
		size = ft_atoi(argv[2]);
	ppuzzle = create_puzzle(size, PUZZLE_TYPE_SKYSCRAPPERS);
	if (!ppuzzle)
	{
		ft_putstr ("Error\n");
		return (1);
	}
	if (get_constraints(ppuzzle, argv[1]))
	{
		ft_putstr ("Error\n");
		return (1);
	}
	play_puzzle(ppuzzle);
	destroy_puzzle(ppuzzle);
	return (0);
}
