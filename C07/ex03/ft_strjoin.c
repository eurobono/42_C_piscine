/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: enricant <enricant@42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/16 12:18:32 by enricant          #+#    #+#             */
/*   Updated: 2025/07/16 13:29:09 by enricant         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

int	ft_strlen(char *src)
{
	int	i;

	if (!src)
		return (0);
	i = 0;
	while (src[i])
		i++;
	return (i);
}

char	*ft_strcat(char *dest, char *src)
{
	int	i;
	int	j;

	if (!dest || !src)
		return (dest);
	i = 0;
	while (dest[i])
		i++;
	j = 0;
	while (src[j])
	{
		dest[i] = src[j];
		i++;
		j++;
	}
	dest[i] = 0;
	return (dest);
}

char	*ft_strjoin(int size, char **strs, char *sep)
{
	char	*strjoin;
	int		i;
	int		length;

	if (!strs)
		return (0);
	length = 0;
	i = 0;
	while (i < size)
		length += ft_strlen(strs[i++]);
	length += ft_strlen(sep) * size + 1;
	strjoin = malloc(length);
	if (!strjoin)
		return (0);
	strjoin[0] = 0;
	i = 0;
	while (i < size)
	{
		strjoin = ft_strcat(strjoin, strs[i]);
		if (i < size - 1)
			strjoin = ft_strcat(strjoin, sep);
		i++;
	}
	return (strjoin);
}

/* *
#include <stdio.h>

void	test_strjoin(int size, char **strs, char *sep)
{
	char	*strjoin;

	strjoin = ft_strjoin(size, strs, sep);
	if (strjoin)
	{
		printf ("str_join(");
		if (strs)
			printf ("sz=%d, strs=\"%s\", sep=\"%s\" ", size, strs[0], sep);
		else
			printf ("sz=%d, strs=NULL, sep=%s ", size, sep);
		printf (") = %s\n", strjoin);
		free (strjoin);
	}
	return ;
}

int	main(void)
{
	char	*strs1[] = {"A", "Q", "U", "A", "R", "I", "U", "S"};
	char	*strs2[] = {"AQUA", "RIU", "S"};
	char	*strs3[] = {""};
	char	*strs4[] = {"AQUA", 0, "RIU", "S", ""};
	char	*strs5[] = {"AQ", "UA", "RI", "US", " ", "for", "", " ", "ever"};

	test_strjoin(sizeof(strs1) / sizeof(char *), strs1, "1");
	test_strjoin(sizeof(strs2) / sizeof(char *), strs2, "2");
	test_strjoin(sizeof(strs3) / sizeof(char *), strs3, "3");
	test_strjoin(sizeof(strs4) / sizeof(char *), strs4, "4");
	test_strjoin(sizeof(strs5) / sizeof(char *), strs5, "5");
	test_strjoin(0, strs1, 0);
	test_strjoin(0, 0, 0);
	return (0);
}
* */
