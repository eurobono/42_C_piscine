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
#include <unistd.h>

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
