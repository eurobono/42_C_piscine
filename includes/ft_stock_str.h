/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_stock_str.h                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: enricant <enricant@42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/24 09:37:07 by enricant          #+#    #+#             */
/*   Updated: 2025/07/24 16:39:50 by enricant         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#ifndef FT_STOCK_STR_H
# define FT_STOCK_STR_H

typedef struct s_stock_str
{
	int		size;
	char	*str;
	char	*copy;
}	t_stock_str;
/*
struct s_stock_str	*ft_strs_to_tab(int ac, char **av);
int					ft_init_stockstr(struct s_stock_str *p,
						char *str);
void				ft_libera_stockstr(struct s_stock_str *pss);
void				ft_show_tab(struct s_stock_str *pss);
*/

#endif
