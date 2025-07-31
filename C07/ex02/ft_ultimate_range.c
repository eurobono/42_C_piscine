/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ultimate_range.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: enricant <enricant@42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/15 18:16:59 by enricant          #+#    #+#             */
/*   Updated: 2025/07/15 19:38:44 by enricant         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

int	ft_ultimate_range(int **range, int min, int max)
{
	int	*pint;
	int	size;
	int	i;

	if (min >= max)
	{
		*range = 0;
		return (0);
	}
	size = max - min;
	pint = malloc(size * sizeof (int));
	if (!pint)
		return (-1);
	i = 0;
	while (i < size)
	{
		pint[i] = min + i;
		i++;
	}
	*range = pint;
	return (size);
}

/* *
#include <stdio.h>
#include <string.h>

int	main(int argc, char **argv)
{
	int	min;
	int	max;
	int	*range;
	int	i;
	int	size;

	if (argc < 3)
		return (1);
	min = atoi(argv[1]);
	max = atoi(argv[2]);
	size = ft_ultimate_range (&range, min, max);
	if (size <= 0)
		printf ("Error parametroos range\n");
	else
	{
		printf ("%d - %d = %d\n", min, max, size);
		i = 0;
		while (i < size)
			printf("%d\n", range[i++]);
		free (range);
		range = 0;
	}
	return (0);
}
* */
