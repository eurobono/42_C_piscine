/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: enricant <enricant@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/25 20:51:38 by enricant          #+#    #+#             */
/*   Updated: 2025/07/31 16:38:11 by enricant         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "bsq.h"

int	main(int argc, char **argv)
{
	t_map			*pmap;
	int				i;

	i = 1;
	while (42)
	{
		if (argc > 1)
			pmap = open_map(argv[i]);
		else
			pmap = open_map(0);
		i++;
		if (!pmap)
			ft_putstr("map Error\n");
		else if (!load_map(pmap))
			ft_putstr("map Error\n");
		else if (find_biggest_rectangle_in_map(pmap))
			ft_putstr("map Error\n");
		close_map(pmap);
		if (i < argc)
			ft_putstr("\n");
		else
			break ;
	}
	return (0);
}
