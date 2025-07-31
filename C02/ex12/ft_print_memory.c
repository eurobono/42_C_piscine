/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_memory.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: enricant <enricant@student.42madrid.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/10 13:00:00 by enricant          #+#    #+#             */
/*   Updated: 2025/07/17 17:12:28 by enricant         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include <unistd.h>

void	write_address_line(char *addr)
{
	unsigned long long	ll;
	char				buffer[20];
	int					i;

	ll = (unsigned long long)addr;
	i = 0;
	while (i < 16)
	{
		buffer[15 - i] = (char)(ll % 16);
		if (buffer[15 - i] > 9)
			buffer[15 - i] = buffer[15 - i] - 10 + 'a';
		else
			buffer[15 - i] = buffer[15 - i] + '0';
		ll = ll / 16;
		i++;
	}
	buffer[16] = ':';
	write (1, buffer, 16 + 1);
	return ;
}

void	write_hex_byte(char *addr)
{
	char	c;
	int		hexa;

	hexa = addr[0] / 16;
	if (hexa > 9)
		c = 'a' + hexa - 10;
	else
		c = '0' + hexa;
	write(1, &c, 1);
	hexa = addr[0] % 16;
	if (hexa > 9)
		c = 'a' + hexa - 10;
	else
		c = '0' + hexa;
	write(1, &c, 1);
	return ;
}

void	write_hex_line(char *addr, int length)
{
	char	c;
	int		i;

	i = 0;
	c = ' ';
	while (i < length)
	{
		write(1, &c, 1);
		write_hex_byte(&addr[i]);
		write_hex_byte(&addr[i + 1]);
		i += 2;
	}
	if (length < 16)
	{
		while (i < 16)
		{
			write(1, &c, 1);
			write(1, &c, 1);
			write(1, &c, 1);
			write(1, &c, 1);
			write(1, &c, 1);
			i += 2;
		}
	}
}

void	write_line(char *addr, unsigned int size)
{
	unsigned int	i;
	char			c;

	write_address_line(addr);
	write_hex_line(addr, size);
	c = ' ';
	write(1, &c, 1);
	i = 0;
	while (i < size)
	{
		if (addr[i] < 32 || addr[i] > 126)
			c = '.';
		else
			c = addr[i];
		write(1, &c, 1);
		i++;
	}
	c = '\n';
	write(1, &c, 1);
	return ;
}

void	*ft_print_memory(void *addr, unsigned int size)
{
	void	*addr_line;
	int		line_size;
	int		i;

	addr_line = addr;
	line_size = 16;
	i = size / line_size;
	while (i)
	{
		write_line(addr_line, line_size);
		addr_line += line_size;
		i--;
	}
	i = size % line_size;
	if (i)
	{
		write_line(addr_line, i);
	}
	return (addr);
}

/* *
int	main(int argc, char **argv)
{
	if (argc < 0)
		return (1);
	ft_print_memory(argv[0], 92);
	return (0);
}
* */
