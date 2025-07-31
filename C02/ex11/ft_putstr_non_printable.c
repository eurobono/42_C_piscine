/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putstr_non_printable.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: enricant <enricant@student.42madrid.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/10 13:00:00 by enricant          #+#    #+#             */
/*   Updated: 2025/07/17 15:39:42 by enricant         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include <unistd.h>

void	ascii_to_hex(char c, char *str)
{
	int	h;
	int	l;

	str[0] = '\\';
	h = c / 16;
	l = c % 16;
	if (h > 9)
		str[1] = 'a' + h - 10;
	else
		str[1] = '0' + (char)h;
	if (l > 9)
		str[2] = 'a' + l - 10;
	else
		str[2] = '0' + (char)l;
	return ;
}

void	ft_putstr_non_printable(char *str)
{
	char	arr[3];
	int		i;

	i = 0;
	while (str[i])
	{
		if (str[i] < 32 || str[i] > 126)
		{
			ascii_to_hex(str[i], arr);
			write(1, arr, 3);
		}
		else
		{
			write(1, &str[i], 1);
		}
		i++;
	}
	return ;
}
/* *
void	main(void)
{
	char	buffer[100]={"Coucou\ntu vas bien ?"};
	ft_putstr_non_printable(buffer);
}
* */
