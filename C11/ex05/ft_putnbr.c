/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: enricant <enricant@student.42madrid.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/09 17:57:20 by enricant          #+#    #+#             */
/*   Updated: 2025/07/16 16:34:41 by enricant         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include <unistd.h>

#define MAX_LENGTH	20

void	ft_putnbr(int nb)
{
	unsigned int	unb;
	char			c;

	if (nb < 0)
	{
		c = '-';
		write (1, &c, 1);
		unb = -1 * nb;
	}
	else
		unb = nb;
	c = '0' + unb % 10;
	if (unb >= 10)
		ft_putnbr (unb / 10);
	write (1, &c, 1);
	return ;
}

/* *
#include <stdio.h>

void	main(void)
{
	ft_putnbr(42); printf("\n");
	ft_putnbr(0); printf("\n");
	ft_putnbr(-12345); printf("\n");
	ft_putnbr(2147483647); printf("\n");
	ft_putnbr(-2147483647 - 1); printf("\n");
	ft_putnbr(2147483647); printf("\n");
	ft_putnbr(-2147483647); printf("\n");
	return ;
}
* */
