/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcapitalize.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: enricant <enricant@student.42madrid.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/10 13:00:00 by enricant          #+#    #+#             */
/*   Updated: 2025/07/17 15:38:30 by enricant         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include <unistd.h>

int	ft_isalpha(char c)
{
	if (c >= 'A' && c <= 'Z')
		return (1);
	if (c >= 'a' && c <= 'z')
		return (1);
	if (c >= '0' && c <= '9')
		return (1);
	return (0);
}

char	*ft_strcapitalize(char *str)
{
	int	i;
	int	j;

	i = 0;
	while (str[i])
	{
		j = i;
		while (ft_isalpha(str[i]) && str[i])
		{
			if (str[i] >= 'a' && str[i] <= 'z' && j == i)
				str[i] = str[i] - 32;
			else if (str[i] >= 'A' && str[i] <= 'Z' && j != i)
				str[i] = str[i] + 32;
			i++;
		}
		i++;
	}
	return (str);
}

/* *

#include <stdio.h>

int	main(int argc, char **argv)
{
	int	i;

	if (!argc)
		return 0;
	
	i = 0;
	while (i < argc)
	{
	printf ("\"%s\"\n", argv[i]);
	printf ("\"%s\"\n", ft_strcapitalize(argv[i]));
	i++;
	}
	return (0);
}
* */
