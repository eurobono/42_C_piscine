/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   do-op_functions.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: enricant <do-op@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/22 22:15:32 by enricant          #+#    #+#             */
/*   Updated: 2025/07/30 14:56:45 by enricant         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include <unistd.h>
#include "doop.h"

int	do_add(int a, int b)
{
	return (a + b);
}

int	do_sus(int a, int b)
{
	return (a - b);
}

int	do_div(int a, int b)
{
	if (!b)
	{
		ft_putstr("Stop : division by zero\n");
		errno = EPERM;
		return (0);
	}
	return (a / b);
}

int	do_mul(int a, int b)
{
	return (a * b);
}

int	do_mod(int a, int b)
{
	if (!b)
	{
		ft_putstr("Stop : modulo by zero\n");
		errno = EPERM;
		return (0);
	}
	return (a % b);
}
