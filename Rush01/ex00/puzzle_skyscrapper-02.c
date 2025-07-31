/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   puzzle_skyscrapper-02.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: enricant <enricant@42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/19 12:02:57 by enricant          #+#    #+#             */
/*   Updated: 2025/07/25 15:13:22 by enricant         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "puzzle.h"

int	validate_position_fig(t_puzzle *ppuzzle, int x, int y, int fig)
{
	int	aux_fig;

	aux_fig = get_position(ppuzzle, x, y);
	set_position(ppuzzle, x, y, fig);
	if (validate_position(ppuzzle, x, y))
	{
		solution_found(ppuzzle, &x, &y);
		validate_solution (ppuzzle, x, y, 1);
		set_position(ppuzzle, x, y, aux_fig);
		return (1);
	}
	set_position(ppuzzle, x, y, aux_fig);
	return (0);
}

int	check_ini_validate_solution(t_puzzle *ppuzzle, int x, int y, int fig)
{
	if (fig < 0 || fig > ppuzzle->figures)
		return (0);
	if (x < 0 || y < 0)
		return (0);
	if (x >= ppuzzle->size || y >= ppuzzle->size)
		return (0);
	if (is_end_position(ppuzzle, x, y, fig))
	{
		draw_board(ppuzzle);
		return (0);
	}
	return (1);
}

void	solution_found(t_puzzle *pp, int *pcol, int *prow)
{
	if (*pcol < pp->size - 1)
		*pcol = *pcol + 1;
	else if (*prow < pp->size - 1)
	{
		*prow = *prow + 1;
		*pcol = 0;
	}
}

int	validate_solution(t_puzzle *pp, int x, int y, int f)
{
	int	j;
	int	k;
	int	l;

	if (!check_ini_validate_solution(pp, x, y, f))
		return (0);
	j = y;
	k = x;
	while (j < pp->size)
	{
		while (k < pp->size)
		{
			l = f;
			while (l <= pp->figures)
			{
				validate_position_fig(pp, k, j, l);
				l++;
			}
			k++;
		}
		k = 0;
		j++;
	}
	return (0);
}
