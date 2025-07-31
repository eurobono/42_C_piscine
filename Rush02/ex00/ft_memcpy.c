/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hventuri <hventuri@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/26 13:26:12 by enricant          #+#    #+#             */
/*   Updated: 2025/07/27 15:38:51 by hventuri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

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
