/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_convert_base.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: enricant <enricant@42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/17 10:15:30 by enricant          #+#    #+#             */
/*   Updated: 2025/07/24 13:44:12 by enricant         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

int	ft_atoi_base(char *nbr, char *base_from);

int	get_base_len(char *base_to)
{
	int	size;
	int	i;
	int	j;

	i = 0;
	while (base_to[i])
	{
		if (base_to[i] < 32 || base_to[i] > 126)
			return (0);
		else
		{
			j = 0;
			while (base_to[j])
			{
				if (i != j && base_to[i] == base_to[j])
					return (0);
				j++;
			}
		}
		i++;
	}
	size = 0;
	while (base_to[size])
		size++;
	return (size);
}

int	get_size_nbr_base(int nbr, char *base_to)
{
	int	size;
	int	base_len;
	int	i;
	int	sign;

	base_len = get_base_len(base_to);
	if (!base_len)
		return (0);
	sign = +1;
	if (nbr < 0)
	{
		sign = -1;
		nbr *= -1;
	}
	i = 1;
	size = nbr;
	while (size >= base_len)
	{
		size /= base_len;
		i++;
	}
	size = i + 1;
	if (sign < 0)
		size++;
	return (size);
}

char	*get_number_to_base(int nbr, char *base_to)
{
	char	*return_number;
	int		size;
	int		base_len;
	int		sign;

	size = get_size_nbr_base(nbr, base_to);
	if (!size)
		return (0);
	base_len = get_base_len(base_to);
	sign = +1;
	if (nbr < 0)
	{
		nbr *= -1;
		sign = -1;
	}
	return_number = malloc(size);
	return_number[--size] = 0;
	while (size--)
	{
		return_number[size] = base_to[nbr % base_len];
		nbr /= base_len;
	}
	if (sign < 0)
		return_number[0] = '-';
	return (return_number);
}

char	*ft_convert_base(char *nbr, char *base_from, char *base_to)
{
	char	*return_number;
	int		nbr_to_return;

	if (!nbr || !base_from || !base_to)
		return (0);
	if (!get_base_len(base_from) || !get_base_len(base_to))
		return (0);
	nbr_to_return = ft_atoi_base(nbr, base_from);
	return_number = get_number_to_base(nbr_to_return, base_to);
	return (return_number);
}
/* *
#include <stdio.h>

void	test_convert_base(char *nbr, char *base_from, char *base_to)
{
	char	*str;

	printf ("convert \"%s\" from \"%s\" to \"%s\" = ",
		nbr, base_from, base_to);
	str = ft_convert_base(nbr, base_from, base_to);
	if (!str)
		printf ("\"%s\"\n", "ERROR");
	else
	{
		printf ("\"%s\"\n", str);
		free (str);
	}
}

int	main(void)
{
	test_convert_base ("42", "0123456789", "0123456789");
	test_convert_base ("101010", "01", "0123456789");
	test_convert_base ("2A", "0123456789ABCDEF", "0123456789");
	test_convert_base ("un", "poniguay", "0123456789");
	test_convert_base ("+42", "0123456789", "0123456789");
	test_convert_base ("-42", "0123456789", "0123456789");
	test_convert_base ("0", "0123456789", "0123456789");
	test_convert_base ("0", "00123456789", "0123456789");
	test_convert_base ("0", 0, "0123456789");
	test_convert_base ("0", 0, 0);
	test_convert_base (0, 0, 0);
	return (0);
}
* */
