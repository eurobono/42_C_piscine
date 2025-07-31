/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: enricant <enrican@4i.fr>                   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/18 11:49:45 by enricant          #+#    #+#             */
/*   Updated: 2025/07/29 08:59:38 by enricant         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include <stdlib.h>

int	is_sep(char c, char *charset)
{
	while (*charset)
		if (c == *charset++)
			return (1);
	return (0);
}

int	word_count(char *str, char *charset)
{
	int	count;
	int	found;

	count = 0;
	found = 0;
	while (*str)
	{
		if (is_sep(*str, charset))
			found = 0;
		else if (!found)
		{
			found = 1;
			count++;
		}
		str++;
	}
	return (count);
}

char	*word_dup(char *start, char *end)
{
	char	*str;
	int		len;
	int		i ;

	len = end - start;
	str = (char *)malloc(len + 1);
	if (!str)
		return (0);
	i = 0;
	while (i < len)
	{
		str[i] = start[i];
		i++;
	}
	str[len] = '\0';
	return (str);
}

char	**ft_split(char *str, char *charset)
{
	char	**result;
	char	*start;
	int		words;
	int		i ;

	words = word_count(str, charset);
	result = (char **)malloc((words + 1) * sizeof(char *));
	if (!result)
		return (0);
	i = 0;
	while (*str)
	{
		while (*str && is_sep(*str, charset))
			str++;
		if (*str)
		{
			start = str;
			while (*str && !is_sep(*str, charset))
				str++;
			result[i++] = word_dup(start, str);
		}
	}
	result[i] = 0;
	return (result);
}

/* *
#include <stdio.h>

int	main(int argc, char **argv)
{
	char	*str;
	char	*charset;
	char	**pres;
	int		i;

	str = "Hola membrillos,,aqui;estoy  con las-pruebas del algodon";
	charset = ",;- ";
	if (argc > 1)
		str = argv[1];
	if (argc > 2)
		charset = argv[2];
	pres = ft_split(str, charset);
	if (!pres)
		return (1);
	i = 0;
	while (pres[i])
	{
		printf("[%s]\n", pres[i]);
		free(pres[i]);
		i++;
	}
	free(pres);
	return (0);
}
* */
