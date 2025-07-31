/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: enricant <enricant@student.42madrid.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/09 17:57:20 by enricant          #+#    #+#             */
/*   Updated: 2025/07/14 16:03:25 by enricant         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include <unistd.h>

#define MAX_LENGTH	20

void	ft_putnbr(int nb)
{
	unsigned int	unb;
	char			buffer[MAX_LENGTH + 1];
	int				i;

	if (nb < 0)
	{
		buffer [0] = '-';
		write (1, &buffer[0], 1);
		nb *= -1;
	}
	unb = nb;
	i = 1;
	buffer[MAX_LENGTH] = 0;
	while (unb / 10 > 0)
	{
		buffer[MAX_LENGTH - i] = '0' + unb % 10;
		unb = unb / 10;
		i++;
	}
	buffer[MAX_LENGTH - i] = '0' + unb % 10;
	write (1, &buffer[MAX_LENGTH - i], i);
	return ;
}

/* *
#include <stdio.h>

void	main(void)
{
	ft_putnbr(42); printf("\n");
	ft_putnbr(0); printf ("\n");
	ft_putnbr(-12345); printf ("\n");
	ft_putnbr(2147483647); printf ("\n");
	ft_putnbr(-2147483647 - 1); printf ("\n");
	ft_putnbr(2147483647 + 1); printf ("\n");
	ft_putnbr(-2147483647); printf ("\n");
	return ;
}
* */
