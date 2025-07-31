/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_is_sort.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: enricant <enricant@42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/22 21:56:30 by enricant          #+#    #+#             */
/*   Updated: 2025/07/30 14:52:48 by enricant         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_is_sort(int *tab, int length, int (*f)(int, int))
{
	int	i;

	i = 0;
	while (i < length - 1)
	{
		if (f(tab[i], tab[i + 1]) != 0)
			return (0);
		i++;
	}
	return (1);
}

/* *
#include <stdio.h>

int	my_func_sort(int a, int b)
{
	printf ("(%d,%d)\n", a, b);
	return (a-b);
}

int	main(void)
{
	int	tab1[]={1,2,3,4,6,5,7,8,9,10};
	int	tab2[]={1,2,3,4,5,6,7,8,9,10};

	printf ("%d\n",ft_is_sort(tab1, sizeof(tab1)/sizeof(int),my_func_sort));
	printf ("%d\n",ft_is_sort(tab2, sizeof(tab2)/sizeof(int),my_func_sort));
	return (0);
}
* */
