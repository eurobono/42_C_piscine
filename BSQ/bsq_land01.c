/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bsq_land01.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: enricant <enricant@42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/29 10:23:29 by enricant          #+#    #+#             */
/*   Updated: 2025/07/31 16:39:48 by enricant         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "bsq.h"

int	fits_outside_biggest(t_map *pmap, t_eval_coordinates *pcoordinates,
		int width_biggest)
{
	if (pmap->pbrectangle->ul.x <= pcoordinates->x
		&& pcoordinates->x <= pmap->pbrectangle->br.x
		&& pmap->pbrectangle->ul.y <= pcoordinates->y
		&& pcoordinates->y <= pmap->pbrectangle->br.y)
	{
		pcoordinates->x = pmap->pbrectangle->br.x + 1;
		pcoordinates->width = 0;
		return (0);
	}
	width_biggest++;
	return (1);
}

int	fits_left(t_map *pmap, t_eval_coordinates *pcoordinates,
		int width_biggest)
{
	if (pcoordinates->x + width_biggest >= pmap->pbrectangle->ul.x
		&& pcoordinates->x < pmap->pbrectangle->ul.x
		&& pmap->pbrectangle->ul.y <= pcoordinates->y
		&& pcoordinates->y <= pmap->pbrectangle->br.y)
	{
		pcoordinates->x = pmap->pbrectangle->br.x + 1;
		pcoordinates->width = 0;
		return (0);
	}
	return (1);
}

int	fits_right(t_map *pmap, t_eval_coordinates *pcoordinates, int width_biggest)
{
	if (pcoordinates->x + width_biggest >= pmap->width)
	{
		pcoordinates->x = 0;
		pcoordinates->y++;
		pcoordinates->width = 0;
		return (0);
	}
	return (1);
}

int	fits_bottom(t_map *pmap, t_eval_coordinates *pcoordinates,
		int width_biggest)
{
	if (pcoordinates->y + width_biggest >= pmap->width)
	{
		pcoordinates->x = pmap->width;
		pcoordinates->y = pmap->width;
		pcoordinates->width = 0;
		return (0);
	}
	return (1);
}

int	fits_coordinates(t_map *pmap, t_eval_coordinates *pcoordinates,
		int width_biggest)
{
	int					count;

	count = 1;
	while (count)
	{
		count = 0;
		if (!fits_outside_biggest(pmap, pcoordinates, width_biggest))
			count++;
		if (!fits_right(pmap, pcoordinates, width_biggest))
			count++;
		if (!fits_left(pmap, pcoordinates, width_biggest))
			count++;
		if (!fits_bottom(pmap, pcoordinates, width_biggest))
			break ;
	}
	return (1);
}
