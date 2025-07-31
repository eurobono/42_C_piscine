/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_tail.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: enricant <enricant@42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/30 08:40:16 by enricant          #+#    #+#             */
/*   Updated: 2025/07/30 09:39:54 by enricant         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_files.h"

void	print_tail(char *content, int total_size, int tail_size)
{
	if (tail_size > total_size)
		tail_size = total_size;
	write(STDOUT_FILENO, content + (total_size - tail_size), tail_size);
}

void	read_content_print_tail(int fd, int *total_size, int tail_size)
{
	char	*content;

	content = ft_read_file_to_buffer(fd, total_size);
	if (content)
	{
		print_tail(content, *total_size, tail_size);
		free(content);
	}
}

int	main_print_tail(int argc, char **argv, int tail_size)
{
	int		total_size;
	int		fd;
	int		i;

	i = 3;
	while (i < argc)
	{
		fd = open(argv[i], O_RDONLY);
		if (fd < 0)
		{
			ft_print_error(argv[0], argv[i]);
			continue ;
		}
		if (argc > 4)
		{
			if (i != 3)
				write(STDOUT_FILENO, "\n", 1);
			ft_print_header(argv[i]);
		}
		read_content_print_tail(fd, &total_size, tail_size);
		close(fd);
		i++;
	}
	return (0);
}

int	main(int argc, char **argv)
{
	int		tail_size;

	if (argc < 4 || ft_strcmp(argv[1], "-c") != 0)
	{
		ft_putstr_fd("Usage: ./ft_tail -c <bytes> <file1> [file2...]\n",
			STDERR_FILENO);
		return (1);
	}
	tail_size = ft_atoi(argv[2]);
	if (tail_size < 0)
		tail_size = 0;
	main_print_tail(argc, argv, tail_size);
	return (0);
}
