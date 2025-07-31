/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: enricant <enricant@42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/15 18:06:06 by enricant          #+#    #+#             */
/*   Updated: 2025/07/23 17:04:41 by enricant         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

int	ft_strlen(char *src)
{
	int	i;

	i = 0;
	while (*src++)
		i++;
	return (i);
}

char	*ft_strcpy(char *dest, char *src)
{
	char	*tmp;

	tmp = dest;
	while (*src)
		*dest++ = *src++;
	*dest = 0;
	return (tmp);
}

char	*ft_strdup(char *src)
{
	char	*dest;
	int		length;

	length = ft_strlen(src);
	dest = malloc(length + 1);
	if (!dest)
		return (NULL);
	return (ft_strcpy(dest, src));
}

/* *
#include <stdio.h>

int	main(void)
{
	char	*dest;

	dest = ft_strdup("membrillo, del bueno\0 que sabe a queso");
	if (dest)
	{
		printf ("%s\n", dest);
		free (dest);
		dest = 0;
	}
	return (0);
}
* */
