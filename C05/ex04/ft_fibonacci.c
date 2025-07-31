/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_fibonacci.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: enricant <enricant@42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/15 13:06:06 by enricant          #+#    #+#             */
/*   Updated: 2025/07/15 17:35:15 by enricant         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_fibonacci(int index)
{
	if (index < 0)
		return (-1);
	else if (index == 0)
		return (0);
	else if (index == 1)
		return (1);
	return (ft_fibonacci(index - 1) + ft_fibonacci(index - 2));
}

/* *
#include <stdio.h>
#include <stdlib.h>

int	main(int argc, char **argv)
{
	int	nb;

	if (argc < 2)
		return (-1);
	nb = atoi(argv[1]);
	printf ("Fibo %d = %d\n", nb, ft_fibonacci(nb));
	return (0);
}
* */
