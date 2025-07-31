/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_combn.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: enricant <enricant@student.42madrid.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/09 17:57:20 by enricant          #+#    #+#             */
/*   Updated: 2025/07/16 16:03:30 by enricant         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include <unistd.h>

void	pinta(int *v)
{
	char	buffer[5];

	buffer[0] = '0' + v[0];
	buffer[1] = '0' + v[1];
	write (1, buffer, 2);
	return ;
}

void	ft_print_combn(void)
{
	int	v[2];

	v[0] = 0;
	while (v[0] < 9)
	{
		v[1] = v[0] + 1;
		while (v[1] < 10)
		{
			if (v[1] > v[0])
			{
				pinta(v);
				if (!(v[0] == 8 && v[1] == 9))
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
	ft_print_combn();
	return ;
}
* */
