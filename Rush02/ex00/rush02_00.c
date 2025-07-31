/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rush02_00.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: enricant <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/25 20:57:20 by enricant          #+#    #+#             */
/*   Updated: 2025/07/26 18:16:51 by enricant         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rush02.h"

int	ft_file_size(char *str)
{
	char	buffer[4096];
	int		file;
	int		len;
	int		file_size;

	file_size = 0;
	file = open(str, O_RDONLY);
	if (file < 0)
		return (-1);
	while (1)
	{
		len = read(file, buffer, sizeof(buffer));
		if (len <= 0)
			break ;
		file_size += len;
	}
	close (file);
	return (file_size);
}

t_dictionary	*load_dictionary(t_dictionary *pdic)
{
	char		*buffer;
	int			size;
	int			i;

	size = ft_file_size(pdic->name);
	buffer = malloc(size + 1);
	if (!buffer || !size)
		return (0);
	if (read(pdic->file, buffer, size) <= 0)
		return (0);
	buffer[size] = 0;
	i = 0;
	while (i < size)
	{
		if (buffer[i] == '\n')
			buffer[i] = 0;
		i++;
	}
	i = 0;
	while (read_dictionary_entries(pdic, &buffer[i]) && buffer[i])
		i += ft_strlen(&buffer[i]) + 1;
	free(buffer);
	sort_dictionary_entries(pdic);
	return (pdic);
}

t_dictionary	*close_dictionary(t_dictionary *pdic)
{
	if (!pdic)
		return (0);
	if (pdic->file)
		close(pdic->file);
	pdic->file = 0;
	if (pdic->name)
		free(pdic->name);
	pdic->name = 0;
	free_dic_arr_entry(pdic);
	free(pdic);
	return (0);
}

t_dictionary	*open_dictionary(char *filename)
{
	t_dictionary	*pdic;
	int				file;

	file = open(filename, O_RDONLY);
	if (file < 0)
		return (0);
	pdic = malloc(sizeof(t_dictionary));
	if (!pdic)
	{
		close (file);
		return (0);
	}
	pdic->file = file;
	pdic->pentry = 0;
	pdic->size_arr_entries = 0;
	pdic->last_entry = -1;
	pdic->name = malloc(ft_strlen(filename) + 1);
	if (!pdic->name)
		return (close_dictionary(pdic));
	if (!ft_strcpy(pdic->name, filename))
		return (close_dictionary(pdic));
	return (pdic);
}
