/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_test_show_tab.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: enricant <enricant@42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/17 22:32:58 by enricant          #+#    #+#             */
/*   Updated: 2025/07/24 12:36:13 by enricant         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_stock_str.h"
#include <unistd.h>
#include <stdio.h>

int	main(int argc, char **argv)
{
	struct s_stock_str	*pstockstr;

	pstockstr = ft_strs_to_tab(argc, argv);
	if (!pstockstr)
		return (1);
	ft_show_tab(pstockstr);
	ft_libera_stockstr(pstockstr);
	return (0);
}
