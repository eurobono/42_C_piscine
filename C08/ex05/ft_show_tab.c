/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_show_tab.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: enricant <enricant@42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/17 22:32:58 by enricant          #+#    #+#             */
/*   Updated: 2025/07/24 16:36:42 by enricant         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_stock_str.h"
#include <unistd.h>

void	ft_putstr_nl(char *str)
{
	char	c;

	while (*str)
	{
		write(1, str, 1);
		str++;
	}
	c = '\n';
	write (1, &c, 1);
}

void	ft_putnbr(int nb)
{
	unsigned int	unb;
	char			c;

	if (nb < 0)
	{
		c = '-';
		write (1, &c, 1);
		unb = -1 * nb;
	}
	else
		unb = nb;
	c = '0' + unb % 10;
	if (unb >= 10)
		ft_putnbr (unb / 10);
	write (1, &c, 1);
	return ;
}

void	ft_show_tab(struct s_stock_str *par)
{
	char	c;

	if (!par)
		return ;
	while (par->str)
	{
		ft_putstr_nl(par->str);
		ft_putnbr(par->size);
		c = '\n';
		write (1, &c, 1);
		ft_putstr_nl(par->copy);
		par++;
	}
}

/* *
#include <stdio.h>
struct s_stock_str	*ft_strs_to_tab(int argc, char **argv);
void			ft_libera_stockstr(struct s_stock_str *);

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
* */
