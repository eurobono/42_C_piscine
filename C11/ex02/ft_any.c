/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_any.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: enricant <enricant@42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/22 21:20:19 by enricant          #+#    #+#             */
/*   Updated: 2025/07/22 22:13:14 by enricant         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include <stdlib.h>

int	ft_any(char **tab, int (*f)(char *))
{
	int		i;
	int		any;

	any = 0;
	i = 0;
	while (tab[i])
	{
		if (f(tab[i]))
			any++;
		i++;
	}
	if (any)
		return (1);
	return (0);
}
/* *
#include <stdio.h>

int	my_func(char *str)
{
	printf ("%s\n", str);
	return (1);
}

int	main(void)
{
	char	*tabla[] = {"Hola", "Adios", "Buenos dias", 0};

	printf ("Result = %d\n", ft_any(tabla, my_func));
	return (0);
}
* */
