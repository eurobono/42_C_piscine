/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_comb.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: enricant <enricant@student.42madrid.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/09 17:57:20 by enricant          #+#    #+#             */
/*   Updated: 2025/07/10 10:57:55 by enricant         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include <unistd.h>
#include <stdio.h>
#include <string.h>

#define DIGITOS 10	/* binario=2, decimal=10 */
#define LENGTH 3	/* siempre menor de 64 */

void	pinta(char *str)
{
	char	buffer[5];
	int		i;

	i = 0;
	while (str[i])
	{
		write (1, &str[i], 1);
		i++;
	}
	buffer[0] = ',';
	buffer[1] = ' ';
	write (1, buffer, 2);
	return ;
}

int	is_end(char *str, int index, int length)
{
	int	i;

	if (((index + 1) >= length) && ((str[length - 1] - '0' + 1) >= DIGITOS))
	{
		i = 0;
		while (i < length)
			if (str[i++] != '9')
				return (0);
		return (1);
	}
	return (0);
}

void	bp(char *str, int index, int length)
{
	int	i;

	if (index == length)
	{
		if (is_end(str, index, length))
			printf ("%s\n", str);
		else
			printf ("%s , ", str);
		return ;
	}
	str[index] = '0';
	i = 0;
	while (i++ < DIGITOS)
	{
		bp (str, index + 1, length);
		str[index]++;
	}
	return ;
}

void	ft_print_comb(void)
{
	char	cadena[66];

	memset (cadena, 0, 66);
	bp (cadena, 0, LENGTH);
	return ;
}

void	main(void)
{
	if ((LENGTH < 1) || (LENGTH > 64))
	{
		printf ("ERROR: LENGTH must be in between 1 and 64\n");
		return ;
	}
	ft_print_comb();
	return ;
}
