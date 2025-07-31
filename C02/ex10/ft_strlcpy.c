/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: enricant <enricant@student.42madrid.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/10 13:00:00 by enricant          #+#    #+#             */
/*   Updated: 2025/07/16 17:20:32 by enricant         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include <unistd.h>

unsigned int	ft_strlcpy(char *dest, char *src, unsigned int size)
{
	unsigned int	i;
	int				r;

	i = 0;
	while (i < size && src[i])
	{
		dest[i] = src[i];
		i++;
	}
	r = i;
	while (i <= size)
		dest[i++] = 0;
	return (r);
}

/* *
#include <stdio.h>

void	test_ft_strlcpy(char *dest,char *src,int size)
{
	int	len;

	len = ft_strlcpy(dest, src, size);
	printf ("ft_strlcpy(\"%s\",\"%s\",%d) = %d\n",dest, src, size, len);
	return ;
}

int	main(int argc, char ** argv)
{
	char	buffer[100];
	int		i;

	i = 0;
	while (i < argc)
	{
		test_ft_strlcpy(buffer, argv[i], 10);
		i++;
	}
	return (0);
}
* */
