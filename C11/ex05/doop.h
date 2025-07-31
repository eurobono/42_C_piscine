/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   do-op.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: enricant <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/22 22:18:28 by enricant          #+#    #+#             */
/*   Updated: 2025/07/30 14:55:32 by enricant         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#ifndef DOOP_H
# define DOOP_H

# include <errno.h>

typedef struct s_doop
{
	char	*s_op;
	int		(*f_op)(int, int);
}	t_doop;

void	ft_putstr(char *str);
void	ft_putnbr(int nbr);
int		ft_strcmp(char *s1, char *s2);
int		ft_atoi(char *str);
int		do_add(int a, int b);
int		do_sus(int a, int b);
int		do_div(int a, int b);
int		do_mul(int a, int b);
int		do_mod(int a, int b);

#endif
