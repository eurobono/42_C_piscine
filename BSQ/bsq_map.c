/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bsq_map.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: enricant <enricant@42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/29 10:23:29 by enricant          #+#    #+#             */
/*   Updated: 2025/07/29 21:21:21 by enricant         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "bsq.h"

t_map	*close_map(t_map *pmap)
{
	if (!pmap)
		return (0);
	if (pmap->file && pmap->name)
		close (pmap->file);
	if (pmap->name)
		free(pmap->name);
	if (pmap->pland)
		free(pmap->pland);
	if (pmap->pbrectangle)
		free(pmap->pbrectangle);
	ft_memset((char *)pmap, sizeof(t_map), 0);
	free (pmap);
	return (0);
}

t_map	*load_map(t_map *pmap)
{
	char		buffer[4096];
	int			size;
	int			i;

	size = read(pmap->file, buffer, sizeof(buffer) - 1);
	if (size < 5)
		return (0);
	buffer[size] = 0;
	i = read_map_header(pmap, buffer);
	if (i < 5 || !pmap->pland)
		return (0);
	read_map_land(pmap, &buffer[i], size - i);
	return (pmap);
}

t_map	*open_map(char *filename)
{
	t_map	*pmap;
	int		file;

	if (!filename)
		file = STDIN_FILENO;
	else
		file = open(filename, O_RDONLY);
	if (file < 0)
		return (0);
	pmap = malloc(sizeof(t_map));
	if (!pmap)
	{
		close (file);
		return (0);
	}
	ft_memset((char *)pmap, sizeof(t_map), 0);
	pmap->file = file;
	pmap->name = ft_strdup(filename);
	if (pmap->name)
		ft_strcpy(pmap->name, filename);
	return (pmap);
}
