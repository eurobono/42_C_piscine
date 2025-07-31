/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bsq_land.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: enricant <enricant@42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/29 10:23:29 by enricant          #+#    #+#             */
/*   Updated: 2025/07/31 16:39:49 by enricant         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "bsq.h"

int	fits_coordinates(t_map *pmap, t_eval_coordinates *pcoordinates,
		int width_biggest);

int	adjust_coordinates(t_map *pmap, int *x, int *y, int *width)
{
	t_eval_coordinates	coordinates;
	int					width_biggest;

	if (!pmap || !pmap->pbrectangle)
		return (1);
	coordinates.x = *x;
	coordinates.y = *y;
	coordinates.width = *width;
	width_biggest = pmap->pbrectangle->br.x - pmap->pbrectangle->ul.x + 1;
	fits_coordinates(pmap, &coordinates, width_biggest);
	*x = coordinates.x;
	*y = coordinates.y;
	*width = coordinates.width;
	return (1);
}

int	book_biggest_rectangle_in_land(t_map *pmap)
{
	int	i;
	int	j;

	if (!pmap || !pmap->pbrectangle || !pmap->pland)
		return (0);
	j = pmap->pbrectangle->ul.y;
	while (j <= pmap->pbrectangle->br.y)
	{
		i = pmap->pbrectangle->ul.x;
		while (i <= pmap->pbrectangle->br.x)
		{
			pmap->pland[j * pmap->width + i] = pmap->busy;
			i++;
		}
		j++;
	}
	return (0);
}

int	found_space_for_rectangle(t_map *pmap, int *x, int *y, int width)
{
	if (!pmap->pbrectangle)
	{
		pmap->pbrectangle = malloc(sizeof(t_rectangle));
		if (!pmap->pbrectangle)
			return (1);
		ft_memset((char *)pmap->pbrectangle, sizeof(t_rectangle), 0);
	}
	if (pmap->pbrectangle->br.x - pmap->pbrectangle->ul.x + 1 >= width)
		return (1);
	pmap->pbrectangle->ul.x = *x;
	pmap->pbrectangle->ul.y = *y;
	pmap->pbrectangle->br.x = *x + width - 1;
	pmap->pbrectangle->br.y = *y + width - 1;
	return (0);
}

int	does_fit_rectangle(t_map *pmap, int x, int y, int width)
{
	int	aux_x;
	int	aux_y;

	if (!pmap || !pmap->pland
		|| x + width > pmap->width || y + width > pmap->height)
		return (0);
	aux_x = x;
	aux_y = y;
	while (y < aux_y + width)
	{
		x = aux_x;
		while (x < aux_x + width)
		{
			if (pmap->pland[y * pmap->width + x] != pmap->empty)
				return (0);
			x++;
		}
		y++;
	}
	return (1);
}

int	find_biggest_rectangle_in_map(t_map *pmap)
{
	int	x;
	int	y;
	int	width;

	y = 0;
	while (y < pmap->height)
	{
		x = 0;
		while (x < pmap->width)
		{
			width = pmap->width;
			while (width >= 0 && adjust_coordinates(pmap, &x, &y, &width))
			{
				if (does_fit_rectangle(pmap, x, y, width))
					found_space_for_rectangle(pmap,
						&x, &y, width);
				width--;
			}
			x++;
		}
		y++;
	}
	book_biggest_rectangle_in_land(pmap);
	plot_map_land(pmap);
	return (0);
}
