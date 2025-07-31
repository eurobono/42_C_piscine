/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hventuri <hventuri@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/26 13:26:12 by enricant          #+#    #+#             */
/*   Updated: 2025/07/30 14:32:01 by enricant         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

int	ft_memcmp(char *dest, char *src, int size)
{
	while (size--)
	{
		if (*dest != *src)
			return (*dest - *src);
		dest++;
		src++;
	}
	return (0);
}

void	ft_memset(char *str, int size, char c)
{
	while (size--)
		*str++ = c;
	return ;
}

void	ft_memcpy(char *dest, char *src, int size)
{
	if (!dest || !src)
		return ;
	while (size--)
		*dest++ = *src++;
	return ;
}

void	ft_swap_structs(char *dest, char *src, int size)
{
	char	*aux;

	aux = (char *)malloc(size);
	if (!aux)
		return ;
	ft_memcpy (aux, dest, size);
	ft_memcpy (dest, src, size);
	ft_memcpy (src, aux, size);
	free (aux);
}
