/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_comb.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: enricant <enricant@student.42madrid.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/09 17:57:20 by enricant          #+#    #+#             */
/*   Updated: 2025/07/14 09:55:54 by enricant         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include <unistd.h>

#define LENGTH 3	/* siempre mayor de 1 */

void	pinta(char *str, int length)
{
	char	buffer[2];

	write (1, str, length);
	if (!(str[length - 1] == '9' && str[0] == '9' - length + 1))
	{
		buffer[0] = ',';
		buffer[1] = ' ';
		write(1, buffer, 2);
	}
	return ;
}

void	bp(char *str, int index, int length)
{
	if (index == length)
	{
		pinta (str, length);
		return ;
	}
	str[index] = str[index - 1] + 1;
	while (str[index] <= '9')
	{
		bp (str, index + 1, length);
		str[index]++;
	}
	return ;
}

void	ft_print_comb(void)
{
	char	cadena[LENGTH + 1 + 1];

	cadena[0] = '0' - 1;
	cadena[LENGTH + 1] = 0;
	bp (&cadena[1], 0, LENGTH);
	return ;
}

/*
void	main(void)
{
	if (LENGTH < 1)
	{
		write (1, "ERROR\n", 6);
		return ;
	}
	ft_print_comb();
	return ;
}
* */
