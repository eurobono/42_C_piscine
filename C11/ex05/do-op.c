/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   do-op.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: enricant <do-op@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/22 22:15:32 by enricant          #+#    #+#             */
/*   Updated: 2025/07/30 14:56:03 by enricant         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include <unistd.h>
#include "doop.h"

void	init_oper_tab(t_doop *tdoop)
{
	tdoop[0].s_op = "+";
	tdoop[0].f_op = do_add;
	tdoop[1].s_op = "-";
	tdoop[1].f_op = do_sus;
	tdoop[2].s_op = "/";
	tdoop[2].f_op = do_div;
	tdoop[3].s_op = "*";
	tdoop[3].f_op = do_mul;
	tdoop[4].s_op = "%";
	tdoop[4].f_op = do_mod;
	tdoop[5].s_op = 0;
	tdoop[5].f_op = 0;
}

int	check_input_arguments(int argc, char **argv)
{
	char	*str;

	str = argv[0];
	if (argc != 4)
		return (1);
	if (argc != 4)
	{
		ft_putstr("0\n");
		return (1);
	}
	return (0);
}

int	main(int argc, char **argv)
{
	t_doop	tdoop[6];
	int		i;
	int		ret;

	if (check_input_arguments(argc, argv))
		return (1);
	init_oper_tab(tdoop);
	i = 0;
	while (tdoop[i].s_op)
	{
		if (!ft_strcmp(tdoop[i].s_op, argv[2]))
		{
			ret = tdoop[i].f_op(ft_atoi(argv[1]),
					ft_atoi(argv[3]));
			if (errno)
				return (1);
			ft_putnbr(ret);
			ft_putstr("\n");
			return (0);
		}
		i++;
	}
	ft_putstr("0\n");
	return (1);
}
