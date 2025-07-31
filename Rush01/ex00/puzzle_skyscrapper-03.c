/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   puzzle_skyscrapper-03.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: enricant <enricant@42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/20 11:47:59 by enricant          #+#    #+#             */
/*   Updated: 2025/07/20 22:21:04 by enricant         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "puzzle.h"

int	get_position(t_puzzle *ppuzzle, int x, int y)
{
	return (ppuzzle->board[y * ppuzzle->size + x]);
}

void	set_position(t_puzzle *ppuzzle, int x, int y, int figure)
{
	if (figure < 0 || figure > ppuzzle->figures)
		return ;
	ppuzzle->board[y * ppuzzle->size + x] = figure;
}

int	validate_line(t_puzzle *ppuzzle, int *pini, int inc, int max_view)
{
	int	count;
	int	actual;
	int	i;

	count = 0;
	actual = 0;
	i = 0;
	while (i < ppuzzle->size)
	{
		if (!*pini)
			count++;
		else if (actual <= *pini)
		{
			actual = *pini;
			count++;
		}
		pini += inc;
		i++;
	}
	if (count == max_view)
		return (1);
	return (0);
}

int	validate_position(t_puzzle *ppuzzle, int x, int y)
{
	int	*pini;
	int	inc;
	int	max_view;

	pini = &ppuzzle->board[y * ppuzzle->size];
	inc = +1;
	max_view = ppuzzle->constraints[PUZZLE_LF * ppuzzle->size + y];
	if (!validate_line(ppuzzle, pini, inc, max_view))
		return (0);
	pini = &ppuzzle->board[(y + 1) * ppuzzle->size - 1];
	inc = -1;
	max_view = ppuzzle->constraints[PUZZLE_RG * ppuzzle->size + y];
	if (!validate_line(ppuzzle, pini, inc, max_view))
		return (0);
	pini = &ppuzzle->board[0 * ppuzzle->size + x];
	inc = ppuzzle->size;
	max_view = ppuzzle->constraints[PUZZLE_UP * ppuzzle->size + x];
	if (!validate_line(ppuzzle, pini, inc, max_view))
		return (0);
	pini = &ppuzzle->board[(ppuzzle->size - 1) * ppuzzle->size + x];
	inc = -1 * ppuzzle->size;
	max_view = ppuzzle->constraints[PUZZLE_DW * ppuzzle->size + x];
	if (!validate_line(ppuzzle, pini, inc, max_view))
		return (0);
	return (1);
}
