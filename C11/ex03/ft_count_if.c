/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_count_if.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: enricant <enricant@42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/22 21:20:19 by enricant          #+#    #+#             */
/*   Updated: 2025/07/22 21:54:45 by enricant         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include <stdlib.h>

int	ft_count_if(char **tab, int length, int (*f)(char *))
{
	int	count;
	int	i;

	count = 0;
	i = 0;
	while (i < length)
	{
		if (f(tab[i]))
			count++;
		i++;
	}
	return (count);
}
/* *
#include <stdio.h>

int	my_func(char *str)
{
	printf ("%s\n", str);
	return (str[0] % 2);
}

int	main(void)
{
	char	*tabla[]={"1","3","5","7","9","0","8","6","4","2","0"};
	int	count;

	count = ft_count_if(tabla, sizeof(tabla)/sizeof(char *),my_func);
	printf ("Count=%d\n",count);
	return (0);
}
* */
