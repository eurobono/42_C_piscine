/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_cat.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: enricant <enricant@42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/30 09:41:36 by enricant          #+#    #+#             */
/*   Updated: 2025/07/31 10:39:03 by enricant         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_files.h"

void	ft_putstr_fd(char *str, int file)
{
	while (*str)
		write(file, str++, 1);
}

void	ft_print_error(char *prog_name, char *filename)
{
	ft_putstr_fd(basename(prog_name), STDERR_FILENO);
	ft_putstr_fd(": ", STDERR_FILENO);
	ft_putstr_fd(filename, STDERR_FILENO);
	ft_putstr_fd(": ", STDERR_FILENO);
	ft_putstr_fd(strerror(errno), STDERR_FILENO);
	write(STDERR_FILENO, "\n", 1);
}

int	ft_display_file(char *progname, char *filename)
{
	char	buffer[FT_FILES_BUF_SIZE];
	int		size;
	int		file;

	file = open(filename, O_RDONLY);
	if (file < 0)
	{
		ft_print_error(progname, filename);
		return (1);
	}
	size = read(file, buffer, FT_FILES_BUF_SIZE);
	while (size > 0)
	{
		write(STDOUT_FILENO, buffer, size);
		size = read(file, buffer, FT_FILES_BUF_SIZE);
	}
	close(file);
	return (0);
}

int	main(int argc, char **argv)
{
	char	buffer[FT_FILES_BUF_SIZE];
	int		size;
	int		i;

	if (argc == 1)
	{
		size = read(STDIN_FILENO, buffer, FT_FILES_BUF_SIZE);
		while (size > 0)
		{
			write(STDOUT_FILENO, buffer, size);
			size = read(STDIN_FILENO, buffer, FT_FILES_BUF_SIZE);
		}
	}
	else
	{
		i = 1;
		while (i < argc)
			ft_display_file(argv[0], argv[i++]);
	}
	return (0);
}
