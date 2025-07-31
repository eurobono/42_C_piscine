/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_base.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: enricant <enricant@student.42madrid.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/10 13:00:00 by enricant          #+#    #+#             */
/*   Updated: 2025/07/14 18:34:47 by enricant         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include <unistd.h>

int	valid_base(char *base)
{
	int		base_length;
	int		i;
	int		j;

	base_length = 0;
	while (base[base_length])
	{
		if (base[base_length] == '+' || base[base_length] == '-')
			return (0);
		base_length++;
	}
	if (base_length <= 1)
		return (0);
	i = 0;
	while (i < base_length)
	{
		j = i + 1;
		while (j < base_length)
		{
			if (base[i] == base[j++])
				return (0);
		}
		i++;
	}
	return (base_length);
}

void	pinta_putnbr_base(int nb, char *base, int base_length)
{
	char	buffer[100];
	int		i;

	i = 20;
	while (nb >= base_length)
	{
		buffer[i] = base[nb % base_length];
		nb /= base_length;
		i--;
	}
	buffer[i] = base[nb % base_length];
	i--;
	write(1, &buffer[i + 1], 20 - i);
}

void	ft_putnbr_base(int nb, char *base)
{
	char	signo;
	int		base_length;

	base_length = valid_base(base);
	if (!base_length)
		return ;
	if (nb < 0)
	{
		signo = '-';
		nb *= -1;
	}
	else if (nb > 0)
		signo = '+';
	else
	{
		write (1, &base[0], 1);
		signo = '\n';
		write (1, &signo, 1);
		return ;
	}
	write (1, &signo, 1);
	pinta_putnbr_base(nb, base, base_length);
	signo = '\n';
	write (1, &signo, 1);
	return ;
}

/* *
void	main(void)
{
	ft_putnbr_base(42, "0123456789");
	ft_putnbr_base(42, "01");
	ft_putnbr_base(42, "0123456789ABCDEF");
	ft_putnbr_base(42, "poniguay");
        ft_putnbr_base(-42, "0123456789");
        ft_putnbr_base(-42, "01");
        ft_putnbr_base(-42, "0123456789ABCDEF");
        ft_putnbr_base(-42, "poniguay");
	return ;
}
* */
