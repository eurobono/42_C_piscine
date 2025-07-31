/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sort_params.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: enricant <enricant@42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/15 16:58:43 by enricant          #+#    #+#             */
/*   Updated: 2025/07/23 17:48:40 by enricant         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdlib.h>
#include <string.h>

int	ft_strcmp(char *s1, char *s2)
{
	int		i;

	i = 0;
	while (s1[i] && s2[i])
	{
		if (s1[i] != s2[i])
			return (s1[i] - s2[i]);
		i++;
	}
	return (s1[i] - s2[i]);
}

void	ft_putstr(char *str)
{
	while (*str)
		write (1, str++, 1);
	return ;
}

void	ft_qsort(char **argv, int argc, int size, int (*cmp)(char *, char*))
{
	char	*str;
	int		i;
	int		count;

	while (42)
	{
		count = 0;
		i = 0;
		while (i < argc - 1)
		{
			if ((*cmp)(argv[i], argv[i + 1]) > 0)
			{
				str = argv[i];
				argv[i] = argv[i + 1];
				argv[i + 1] = str;
				count++;
			}
			i++;
		}
		if (!count)
			return ;
	}
	size = sizeof(char *);
}

int	main(int argc, char **argv)
{
	int	i;

	ft_qsort(&argv[1], argc - 1, sizeof (char *), ft_strcmp);
	i = 1;
	while (i < argc)
	{
		ft_putstr(argv[i]);
		ft_putstr("\n");
		i++;
	}
	return (0);
}
