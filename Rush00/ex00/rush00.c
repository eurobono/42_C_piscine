/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rush00.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: enricant <enricant@student.42madrid.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/10 13:00:00 by enricant          #+#    #+#             */
/*   Updated: 2025/07/13 11:22:28 by enricant         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	ft_putchar(char c);

void	pinta_elemento_fila(char *str)
{
	int		j;

	j = 0;
	while (str[j])
	{
		ft_putchar(str[j]);
		j++;
	}
	return ;
}

void	pinta_fila(char *str[], int ancho)
{
	int	i;

	if (ancho >= 1)
		pinta_elemento_fila(str[0]);
	i = 2;
	while (i < ancho)
	{
		pinta_elemento_fila(str[1]);
		i++;
	}
	if (ancho > 1)
		pinta_elemento_fila(str[2]);
	ft_putchar('\n');
	return ;
}

void	rellena_rectangulo(char	*rectangulo[])
{
	rectangulo[0] = "o\0";
	rectangulo[1] = "-\0";
	rectangulo[2] = "o\0";
	rectangulo[3] = "|\0";
	rectangulo[4] = " \0";
	rectangulo[5] = "|\0";
	rectangulo[6] = "o\0";
	rectangulo[7] = "-\0";
	rectangulo[8] = "o\0";
}

int	rush(int x, int y)
{
	char	*rectangulo[9];
	int		i;

	rellena_rectangulo(rectangulo);
	if (x <= 0 || y <= 0)
		return (1);
	if (y >= 1)
		pinta_fila(&rectangulo[0], x);
	i = 2;
	while (i < y)
	{
		pinta_fila(&rectangulo[3], x);
		i++;
	}
	if (y > 1)
		pinta_fila(&rectangulo[6], x);
	return (0);
}
