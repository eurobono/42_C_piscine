/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_hexdump.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: enricant <enricant@42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/30 12:56:50 by enricant          #+#    #+#             */
/*   Updated: 2025/07/31 11:42:29 by enricant         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_files.h"

void	print_hex_line(char *buf, int size,
			unsigned int offset, int *count);

void	process_file(char *prog, char *filename, unsigned int *offset)
{
	char	buf[32];
	int		len;
	int		file;
	int		count;

	file = open(filename, O_RDONLY);
	if (file < 0)
	{
		ft_print_error(prog, filename);
		return ;
	}
	ft_memset(buf, sizeof(buf), 0);
	count = 0;
	len = read(file, buf, 16);
	while (len > 0)
	{
		print_hex_line(buf, len, *offset, &count);
		*offset += len;
		len = read(file, buf, 16);
	}
	close(file);
}

int	main(int argc, char **argv)
{
	char	end[9];
	int		offset;
	int		i;

	if (argc < 3 || ft_strcmp(argv[1], "-C") != 0)
	{
		ft_putstr_fd("Usage: ./ft_hexdump -C <file1> [file2...]\n",
			STDERR_FILENO);
		return (1);
	}
	offset = 0;
	i = 2;
	while (i < argc)
		process_file(argv[0], argv[i++], (unsigned int *)&offset);
	i = 7;
	while (i >= 0)
	{
		end[7 - i] = HEX_BASE[(offset >> (i * 4)) & 0xF];
		i--;
	}
	end[8] = '\n';
	write(STDOUT_FILENO, end, 9);
	return (0);
}
