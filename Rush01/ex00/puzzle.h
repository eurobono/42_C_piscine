/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   puzzle.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: enricant <enricant@42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/19 11:54:30 by enricant          #+#    #+#             */
/*   Updated: 2025/07/25 15:15:16 by enricant         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

typedef struct s_puzzle
{
	int	type;
	int	size;
	int	figures;
	int	*board;
	int	*constraints;
	int	solutions;
}	t_puzzle;

#define PUZZLE_TYPE_SKYSCRAPPERS 0
#define PUZZLE_TYPE_QUEENS 1

#define PUZZLE_UP 0
#define PUZZLE_DW 1
#define PUZZLE_LF 2
#define PUZZLE_RG 3

void		init_puzzle(t_puzzle *ppuzzle, int size, int type);
t_puzzle	*create_puzzle(int size, int type);
void		destroy_puzzle(t_puzzle *ppuzzle);
void		draw_board(t_puzzle *ppuzzle);
int			is_end_position(t_puzzle *ppuzzle, int x, int y, int f);
int			get_position(t_puzzle *ppuzzle, int x, int y);
void		set_position(t_puzzle *ppuzzle, int x, int y, int f);
void		solution_found(t_puzzle *pp, int *x, int *y);
int			validate_solution(t_puzzle *pp, int x, int y, int f);
int			validate_position(t_puzzle *pp, int x, int y);

void		ft_putstr(char *str);
int			ft_atoi(char *str);
