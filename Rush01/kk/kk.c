/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   puzzle.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: enricant <enricant@42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/19 11:54:30 by enricant          #+#    #+#             */
/*   Updated: 2025/07/20 13:53:28 by enricant         ###   ########.fr       */
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
int			is_end_position(t_puzzle *ppuzzle, int x, int y);
int			get_position(t_puzzle *ppuzzle, int x, int y);
void		set_position(t_puzzle *ppuzzle, int x, int y, int f);
int			validate_solution(t_puzzle *pp, int x, int y, int f);
int			validate_position(t_puzzle *pp, int x, int y);

void		ft_putstr(char *str);
int			ft_atoi(char *str);
/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: enricant <enricant@student.42madrid.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/10 13:00:00 by enricant          #+#    #+#             */
/*   Updated: 2025/07/14 10:57:26 by enricant         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_isspace3(char c)
{
	char	*ws_c;
	int		i;

	ws_c = " \f\n\r\t\v\0";
	i = 0;
	while (ws_c[i])
	{
		if (ws_c[i] == c)
			return (1);
		i++;
	}
	return (0);
}

int	ft_atoi(char *str)
{
	int	nbr;
	int	signo;
	int	i;

	nbr = 0;
	signo = +1;
	i = 0;
	while (ft_isspace3(str[i]))
		i++;
	while (str[i] == '-' || str[i] == '+')
	{
		if (str[i] == '-')
			signo *= -1;
		i++;
	}
	while (str[i] >= '0' && str[i] <= '9')
	{
		nbr = nbr * 10 + (str[i] - '0');
		i++;
	}
	return (nbr * signo);
}

/* *
#include <stdio.h>

void	main(void)
{
	printf ("%d\n", ft_atoi(" ---+--+1234ab567"));
	return ;
}
* */
/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: enricant <enricant@student.42madrid.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/10 13:00:00 by enricant          #+#    #+#             */
/*   Updated: 2025/07/14 10:58:33 by enricant         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


void	ft_putstr(char *str)
{
	int	i;

	i = 0;
	while (str[i])
		write (1, &str[i++], 1);
	return ;
}

/* *
#include <stdio.h>

void	main(void)
{
	ft_putstr("hola calamarcito\n");
	return ;
}
* */
/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: enricant <enricant@42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/19 12:19:28 by enricant          #+#    #+#             */
/*   Updated: 2025/07/20 17:59:02 by enricant         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

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

int	main(void)
{
	t_puzzle	*ppuzzle;
	int			size;
	char		*str;

	str = "4 3 2 1 1 2 2 2 4 3 2 1 1 2 2 2";
	size = 4;
	ppuzzle = create_puzzle(size, PUZZLE_TYPE_SKYSCRAPPERS);
	if (!ppuzzle)
	{
		ft_putstr ("Error\n");
		return (1);
	}
	if (get_constraints(ppuzzle, str))
	{
		ft_putstr ("Error\n");
		return (1);
	}
	play_puzzle(ppuzzle);
	destroy_puzzle(ppuzzle);
	return (0);
}
/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   puzzle_skyscrapper-01.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: enricant <enricant@42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/19 12:02:57 by enricant          #+#    #+#             */
/*   Updated: 2025/07/20 14:02:55 by enricant         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

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

int	is_end_position(t_puzzle *ppuzzle, int x, int y)
{
	if (x != ppuzzle->size - 1 && y != ppuzzle->size - 1)
		return (0);
	return (1);
}
/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   puzzle_skyscrapper-02.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: enricant <enricant@42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/19 12:02:57 by enricant          #+#    #+#             */
/*   Updated: 2025/07/20 19:14:33 by enricant         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

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

int	validate_position_fig(t_puzzle *ppuzzle, int x, int y, int fig)
{
	int	aux_fig;
	int	i;

	i = fig;
	while (i <= ppuzzle->figures)
	{
		aux_fig = get_position(ppuzzle, x, y);
		set_position(ppuzzle, x, y, i);
		if (validate_position(ppuzzle, x, y))
			return (1);
		set_position(ppuzzle, x, y, aux_fig);
		i++;
	}
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
	if (is_end_position(ppuzzle, x, y))
	{
		draw_board(ppuzzle);
		return (0);
	}
	return (1);
}

void	solution_found(t_puzzle *pp, int *pcol, int *prow, int *pfig)
{
	if (*pcol < pp->size - 1)
		*pcol = *pcol + 1;
	else if (*prow < pp->size - 1)
	{
		*prow = *prow + 1;
		*pcol = 0;
	}
	else
		draw_board(pp);
	*pfig = 1;
}

int	validate_solution(t_puzzle *pp, int x, int y, int f)
{
	int	j;
	int	k;

	if (!check_ini_validate_solution(pp, x, y, f))
		return (0);
	j = y;
	k = x;
	while (j < pp->size)
	{
		while (k < pp->size)
		{
			if (validate_position_fig(pp, k, j, f))
			{
				solution_found(pp, &k, &j, &f);
				validate_solution (pp, k, j, 1);
			}
			else if (f < pp->figures)
            	validate_solution (pp, k, j, f + 1);
			k++;
		}
		k = 0;
		j++;
	}
	return (0);
}
/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   puzzle_skyscrapper-03.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: enricant <enricant@42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/20 11:47:59 by enricant          #+#    #+#             */
/*   Updated: 2025/07/20 14:40:06 by enricant         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


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
