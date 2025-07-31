/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: enricant <enrican@4i.fr>                   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/18 11:49:45 by enricant          #+#    #+#             */
/*   Updated: 2025/07/24 13:45:21 by enricant         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

int	ft_strncpy(char *dest, char *src, int nbr)
{
	int	i;

	i = 0;
	while (src[i] && nbr > 0)
	{
		dest[i] = src[i];
		i++;
		nbr--;
	}
	return (i);
}

int	ft_strlen(char *str)
{
	int	i;

	i = 0;
	while (str[i])
		i++;
	return (i);
}

char	*ft_strstr_index(char *str, char *to_find, int nbr)
{
	int	i;
	int	j;

	if (!to_find[0] || !nbr)
		return (NULL);
	i = 0;
	while (str[i])
	{
		j = 0;
		while (str[i] == to_find[j] && to_find[j])
		{
			i++;
			j++;
		}
		if (!to_find[j])
		{
			nbr--;
			if (nbr <= 0)
				return (&str[i - j]);
			j = 0;
		}
		i++;
	}
	return (NULL);
}

int	ft_count_sep(char *str, char *to_find)
{
	char	*straux;
	int		i;

	i = 0;
	while (1)
	{
		straux = ft_strstr_index(str, to_find, i + 1);
		if (!straux)
			break ;
		i++;
	}
	return (i);
}

char	**ft_split(char *str, char *charset)
{
	char	**pstr;
	int		nbr;
	int		i;

	nbr = ft_count_sep(str, charset);
	if (!nbr)
		return (0);
	pstr = malloc(sizeof(char *) * (nbr + 1));
	if (!pstr)
		return (0);
	i = 0;
	while (1)
	{
		pstr[i] = ft_strstr_index(str, charset, i + 1);
		if (!pstr[i])
			break ;
		i++;
	}
	pstr[i] = 0;
	return (pstr);
}

/* *
#include <stdio.h>

int	main(int argc, char **argv)
{
	char	**pstr;
	int		i;
	char	str[] = {"manolo estuvo todo loco y logro lo que queria"};
	char	sep[] = {"lo"};

	if (argc < 3)
	{
		printf ("%d\n", ft_count_sep(str, sep));
		pstr = ft_split(str, sep);
	}
	else
	{
		printf ("%d\n", ft_count_sep(argv[1], argv[2]));
		pstr = ft_split(argv[1], argv[2]);
	}
	if (!pstr)
		return (1);
	i = 0;
	while (pstr[i])
	{
		printf ("\"%s\"\n", pstr[i]);
		i++;
	}
	return (0);
}
* */
