/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   puzzle_skyscrapper.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: enricant <enricant@42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/19 12:02:57 by enricant          #+#    #+#             */
/*   Updated: 2025/07/19 13:27:08 by enricant         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "puzzle.h"

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
	{
		ppuzzle->board[i] = 0;
		i++;
	}
	i = 0;
	array_size = size * 4;
	while (i < array_size)
	{
		ppuzzle->constraints[i] = 0;
		i++;
	}
	return ;
}

t_puzzle	*create_puzzle(int size, int type)
{
	t_puzzle	*ppuzzle;

	if (size < 0)
		return (0);
	if (type != PUZZLE_TYPE_SKYSCRAPPERS)
		return (0);
	ppuzzle = malloc(sizeof(t_puzzle));
	if (!ppuzzle)
		return (0);
	ppuzzle->constraints = malloc(sizeof(int) * 4 * size);
	if (!ppuzzle->constraints)
	{
		free (ppuzzle);
		return (0);
	}
	init_puzzle(ppuzzle, size, type);
	return (ppuzzle);
}

void	draw_position(t_puzzle *ppuzzle)
{
	if (!ppuzzle)
		return ;
	return ;
}

int	is_end_position(t_puzzle *ppuzzle, int x, int y, int fig)
{
	if (x != ppuzzle->size - 1 && y != ppuzzle->size - 1)
		return (0);
	if (fig != ppuzzle->figures)
		return (0);
	return (1);
}

int	validate_solution(t_puzzle *ppuzzle, int x, int y, int fig)
{
	if (x < 0 || y < 0)
		return (0);
	if (x >= ppuzzle->size || y >= ppuzzle->size)
		return (0);
	if (fig < 0)
		return (0);
	if (is_end_position(ppuzzle, x, y, fig))
	{
		draw_position(ppuzzle);
		return (0);
	}
	return (1);
}

int	validate_position_bp(t_puzzle *ppuzzle, int x, int y, int fig)
{
	int	i;
	int	j;
	int	k;

	if (!validate_solution(ppuzzle, x, y, fig))
		return (0);
	i = fig + 1;
	while (i <= ppuzzle->figures)
	{
		j = x;
		while (i < ppuzzle->size)
		{
			k = y;
			while (k < ppuzzle->size)
			{
				if (!validate_position_bp(ppuzzle, j, k, i))
					return (0);
				ppuzzle->board[y * ppuzzle->size + x] = fig;
				k++;
			}
			j++;
		}
		i++;
	}
	return (1);
}
