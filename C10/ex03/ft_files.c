/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_files.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: enricant <enricant@42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/30 08:40:36 by enricant          #+#    #+#             */
/*   Updated: 2025/07/30 09:30:44 by enricant         ###   ########.fr       */
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

char	*ft_read_new_buffer(int fd, int *total_size, char *buffer)
{
	char	tmp[1024];
	char	*new_buffer;
	int		bytes_read;

	*total_size = 0;
	bytes_read = read(fd, tmp, sizeof(tmp));
	while (bytes_read > 0)
	{
		new_buffer = malloc(*total_size + bytes_read);
		if (!new_buffer)
			return (0);
		ft_memcpy(new_buffer, buffer, *total_size);
		ft_memcpy(new_buffer + *total_size, tmp, bytes_read);
		free(buffer);
		buffer = new_buffer;
		*total_size += bytes_read;
		bytes_read = read(fd, tmp, sizeof(tmp));
	}
	return (buffer);
}

char	*ft_read_file_to_buffer(int fd, int *total_size)
{
	char	*buffer;
	char	*new_buffer;

	buffer = malloc(1);
	if (!buffer)
		return (0);
	new_buffer = ft_read_new_buffer(fd, total_size, buffer);
	if (!new_buffer)
	{
		free(buffer);
		return (0);
	}
	return (new_buffer);
}

void	ft_print_header(char *filename)
{
	write(STDOUT_FILENO, "==> ", 4);
	ft_putstr_fd(filename, STDOUT_FILENO);
	write(STDOUT_FILENO, " <==\n", 5);
}
