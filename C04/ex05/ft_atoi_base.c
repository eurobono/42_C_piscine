/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi_base.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: enricant <enricant@student.42madrid.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/10 13:00:00 by enricant          #+#    #+#             */
/*   Updated: 2025/07/14 10:59:17 by enricant         ###   ########.fr       */
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

int	get_vbase(char digit, char *base, int base_length)
{
	int		i;

	i = 0;
	while (i < base_length)
	{
		if (digit == base[i])
			return (i);
		i++;
	}
	return (-1);
}

int	ft_atoi_base_clean(char *str, char *base, int base_length)
{
	int		vbase;
	int		nbr;
	int		i;

	nbr = 0;
	vbase = 0;
	i = 0;
	while (1)
	{
		vbase = get_vbase(str[i], base, base_length);
		if (vbase < 0)
			break ;
		nbr = nbr * base_length + vbase;
		i++;
	}
	return (nbr);
}

int	ft_atoi_base(char *str, char *base)
{
	int		base_length;
	int		signo;
	int		i;

	base_length = valid_base(base);
	if (!base_length)
		return (0);
	i = 0;
	while (ft_isspace3(str[i]))
		i++;
	signo = +1;
	while (str[i] == '-' || str[i] == '+')
	{
		if (str[i] == '-')
			signo *= -1;
		i++;
	}
	return (ft_atoi_base_clean(&str[i], base, base_length) * signo);
}

/* *
#include <stdio.h>

void	main(void)
{
	printf ("%d\n",ft_atoi_base("42", "0123456789"));
	printf ("%d\n",ft_atoi_base("101010", "01"));
	printf ("%d\n",ft_atoi_base("2A", "0123456789ABCDEF"));
	printf ("%d\n",ft_atoi_base("un", "poniguay"));
	printf ("%d\n",ft_atoi_base("+42", "0123456789"));
	printf ("%d\n",ft_atoi_base("-42", "0123456789"));
	printf ("%d\n",ft_atoi_base("0", "0123456789"));
	return ;
}
* */
