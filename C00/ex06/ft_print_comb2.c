/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_comb2.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: enricant <enricant@student.42madrid.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/09 17:57:20 by enricant          #+#    #+#             */
/*   Updated: 2025/07/16 15:56:55 by enricant         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include <unistd.h>

void	pinta(int *v)
{
	char	buffer[5];

	buffer[0] = '0' + v[0] / 10;
	buffer[1] = '0' + v[0] % 10;
	buffer[2] = ' ';
	buffer[3] = '0' + v[1] / 10;
	buffer[4] = '0' + v[1] % 10;
	write (1, buffer, 5);
	return ;
}

void	ft_print_comb2(void)
{
	int	v[2];

	v[0] = 0;
	while (v[0] < 99)
	{
		v[1] = v[0] + 1;
		while (v[1] < 100)
		{
			if (v[1] > v[0])
			{
				pinta(v);
				if (!(v[0] == 98 && v[1] == 99))
					write (1, (char *)", ", 2);
			}
			v[1]++;
		}
		v[0]++;
	}
	return ;
}

/* *
void	main(void)
{
	ft_print_comb2();
	return ;
}
* */
