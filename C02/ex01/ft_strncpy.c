/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: enricant <enricant@student.42madrid.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/10 13:00:00 by enricant          #+#    #+#             */
/*   Updated: 2025/07/15 13:36:50 by enricant         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include <unistd.h>

char	*ft_strncpy(char *dest, char *src, unsigned int n)
{
	unsigned int	i;
	int				j;

	i = 0;
	j = n;
	while (src[i] && j)
	{
		dest[i] = src[i];
		i++;
		j--;
	}
	while (i < n)
	{
		dest[i] = 0;
		i++;
	}
	return (dest);
}
