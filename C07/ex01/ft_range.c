/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_range.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: enricant <enricant@42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/15 18:16:59 by enricant          #+#    #+#             */
/*   Updated: 2025/07/15 18:35:37 by enricant         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

int	*ft_range(int min, int max)
{
	int	*range;
	int	size;
	int	i;

	if (min >= max)
		return (0);
	size = max - min;
	range = malloc(size * sizeof (int));
	if (!range)
		return (0);
	i = 0;
	while (i < size)
	{
		range[i] = min + i;
		i++;
	}
	return (range);
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

	if (argc < 3)
		return (1);
	min = atoi(argv[1]);
	max = atoi(argv[2]);
	range = ft_range (min, max);
	if (!range)
		printf ("Error parametroos range\n");
	else
	{
		printf ("%d - %d\n", min, max);
		i = 0;
		while (i < (max - min))
			printf("%d\n", range[i++]);
		free (range);
		range = 0;
	}
	return (0);
}
* */
