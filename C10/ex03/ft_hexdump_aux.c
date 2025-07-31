/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_hexdump_aux.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: enricant <enricant@42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/30 12:56:50 by enricant          #+#    #+#             */
/*   Updated: 2025/07/30 19:26:33 by enricant         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_files.h"

void	print_hex_line_ascii(char *buf, int size, char *hex, int *offset)
{
	int		i;
	int		j;
	char	c;

	j = *offset;
	hex[j++] = '|';
	i = 0;
	while (i < size)
	{
		c = buf[i];
		if (c < 32 || c > 126)
			c = '.';
		hex[j++] = c;
		i++;
	}
	hex[j++] = '|';
	*offset = j;
}

void	print_hex_line_hex(char *buf, int size, char *hex, int *offset)
{
	int	i;
	int	j;

	j = *offset;
	i = 0;
	while (i < 16)
	{
		if (i < size)
		{
			hex[j++] = HEX_BASE[buf[i] >> 4];
			hex[j++] = HEX_BASE[buf[i] & 0xF];
		}
		else
		{
			hex[j++] = ' ';
			hex[j++] = ' ';
		}
		if (i % 2)
			hex[j++] = ' ';
		i++;
	}
	*offset = j;
}

void	print_hex_line(char *buf, int size,
		unsigned int offset, int *count)
{
	char	hex[80];
	int		i;
	int		j;

	if (offset > 0 && !ft_memcmp(buf, &buf[16], 16))
	{
		ft_strcpy(hex, "*\n");
		if (!*count)
			write (STDOUT_FILENO, hex, 2);
		*count = *count + 1;
		return ;
	}
	*count = 0;
	ft_memcpy(&buf[16], buf, 16);
	j = 0;
	i = 7;
	while (i >= 0)
		hex[j++] = HEX_BASE[(offset >> (i-- *4)) & 0xF];
	hex[j++] = ' ';
	hex[j++] = ' ';
	print_hex_line_hex(buf, size, hex, &j);
	print_hex_line_ascii(buf, size, hex, &j);
	hex[j++] = '\n';
	write (STDOUT_FILENO, hex, j);
}
