/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   puzzle_skyscrapper-01.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: enricant <enricant@42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/19 12:02:57 by enricant          #+#    #+#             */
/*   Updated: 2025/07/25 15:11:09 by enricant         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "puzzle.h"

void	destroy_puzzle(t_puzzle *ppuzzle)
{
	if (!ppuzzle)
		return ;
	if (ppuzzle->board)
		free (ppuzzle->board);
	ppuzzle->board = 0;
	if (ppuzzle->constraints)
		free (ppuzzle->constraints);
	ppuzzle->constraints = 0;
	free (ppuzzle);
}

void	init_puzzle(t_puzzle *ppuzzle, int size, int type)
{
	int	i;
	int	array_size;

	if (!ppuzzle)
		return ;
	if (!ppuzzle->board)
		return ;
	ppuzzle->type = type;
	ppuzzle->size = size;
	if (ppuzzle->type == PUZZLE_TYPE_SKYSCRAPPERS)
		ppuzzle->figures = ppuzzle->size;
	else
		ppuzzle->figures = 0;
	i = 0;
	array_size = size * size;
	while (i < array_size)
		ppuzzle->board[i++] = 0;
	i = 0;
	array_size = size * 4;
	while (i < array_size)
		ppuzzle->constraints[i++] = 0;
}

t_puzzle	*create_puzzle(int size, int type)
{
	t_puzzle	*ppuzzle;

	if (size <= 0)
		return (0);
	if (type != PUZZLE_TYPE_SKYSCRAPPERS)
		return (0);
	ppuzzle = malloc(sizeof(t_puzzle));
	if (!ppuzzle)
		return (0);
	ppuzzle->board = malloc(sizeof(int) * size * size);
	if (!ppuzzle->board)
	{
		destroy_puzzle(ppuzzle);
		return (0);
	}
	ppuzzle->constraints = malloc(sizeof(int) * 4 * size);
	if (!ppuzzle->constraints)
	{
		destroy_puzzle(ppuzzle);
		return (0);
	}
	init_puzzle(ppuzzle, size, type);
	return (ppuzzle);
}

void	draw_board(t_puzzle *ppuzzle)
{
	char	c;
	int		x;
	int		y;

	if (!ppuzzle)
		return ;
	ppuzzle->solutions++;
	y = 0;
	while (y < ppuzzle->size)
	{
		x = 0;
		while (x < ppuzzle->size)
		{
			c = ppuzzle->board[y * ppuzzle->size + x] + '0';
			write (1, &c, 1);
			if (x == ppuzzle->size - 1)
				c = '\n';
			else
				c = ' ';
			write (1, &c, 1);
			x++;
		}
		y++;
	}
}

int	is_end_position(t_puzzle *ppuzzle, int x, int y, int f)
{
	if (x != ppuzzle->size - 1 && y != ppuzzle->size - 1
		&& f != ppuzzle->figures)
		return (0);
	return (1);
}
