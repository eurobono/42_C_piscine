/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_display_file.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: enricant <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/30 19:05:41 by enricant          #+#    #+#             */
/*   Updated: 2025/07/31 11:38:00 by enricant         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_files.h" 

void	ft_puterror(char *str)
{
	while (*str)
		write(2, str++, 1);
}

void	ft_display_file(char *filename)
{
	int		file;
	int		size;
	char	buffer[FT_FILES_BUF_SIZE];

	file = open(filename, O_RDONLY);
	if (file < 0)
	{
		ft_puterror("Cannot read file.\n");
		return ;
	}
	size = 1;
	while (size > 0)
	{
		size = read(file, buffer, FT_FILES_BUF_SIZE);
		write(1, buffer, size);
	}
	close(file);
}

int	main(int argc, char **argv)
{
	if (argc < 2)
	{
		ft_puterror("File name missing.\n");
		return (1);
	}
	else if (argc > 2)
	{
		ft_puterror("Too many arguments.\n");
		return (1);
	}
	ft_display_file(argv[1]);
	return (0);
}
