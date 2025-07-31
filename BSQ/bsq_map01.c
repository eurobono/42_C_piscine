/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bsq_map01.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: enricant <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/25 20:57:20 by enricant          #+#    #+#             */
/*   Updated: 2025/07/30 16:28:28 by enricant         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "bsq.h"

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

int	plot_map_land(t_map *pmap)
{
	int	j;

	j = 0;
	while (j < pmap->height)
	{
		write (1, &pmap->pland[j * pmap->width], pmap->width);
		ft_putstr("\n");
		j++;
	}
	return (0);
}

int	read_to_endline(t_map *pmap, char *buffer_in,
		int size_in, char *buffer_out)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (buffer_in[i] && i < size_in && j < pmap->width)
	{
		if (!ft_isspace3(buffer_in[i]))
		{
			if (buffer_in[i] != pmap->empty
				&& buffer_in[i] != pmap->obstacle)
				return (-1);
			buffer_out[j] = buffer_in[i];
			j++;
		}
		i++;
	}
	if (j != pmap->width)
		return (-1);
	while ((!buffer_in[i] || ft_isspace3(buffer_in[i]))
		&& i <= size_in)
		i++;
	return (i);
}

int	read_map_header(t_map *pmap, char *buffer_in)
{
	int		i;

	i = ft_atoi(buffer_in);
	if (i < 1)
		return (0);
	pmap->width = i;
	pmap->height = i;
	i = ft_sizenbr(buffer_in);
	if (ft_strlen(&buffer_in[i]) < 4)
		return (0);
	pmap->empty = buffer_in[i++];
	pmap->obstacle = buffer_in[i++];
	pmap->busy = buffer_in[i++];
	if (pmap->empty == pmap->obstacle
		|| pmap->empty == pmap->busy
		|| pmap->obstacle == pmap->busy)
		return (0);
	if (pmap->width * pmap->height <= 0)
		return (0);
	pmap->pland = malloc(pmap->width * pmap->height);
	if (!pmap->pland)
		return (0);
	ft_memset(pmap->pland, pmap->width * pmap->height, pmap->empty);
	return (i);
}

int	read_map_land(t_map *pmap, char *buffer_in, int size)
{
	char	*buffer_out;
	int		i;
	int		j;
	int		k;

	buffer_out = pmap->pland;
	if (!pmap->pland)
	{
		pmap->pland = malloc(pmap->width * pmap->height);
		if (!pmap->pland)
			return (1);
	}
	i = 0;
	k = 0;
	while (i < size && k < pmap->height)
	{
		j = read_to_endline(pmap, &buffer_in[i], size - i,
				buffer_out);
		if (j < 0)
			return (1);
		i += j;
		buffer_out += pmap->width;
		k++;
	}
	return (0);
}
