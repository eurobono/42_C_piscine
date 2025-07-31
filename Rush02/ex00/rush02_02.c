/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rush02_02.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hventuri <hventuri@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/26 14:54:07 by enricant          #+#    #+#             */
/*   Updated: 2025/07/27 20:26:04 by enricant         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rush02.h"

char	*next_word(char *buffer, int *ini, int *fin)
{
	char	*str;
	int		i;
	int		j;

	i = 0;
	while (buffer[i] && ft_isspace3(buffer[i]))
		i++;
	j = i;
	while (buffer[j] && !ft_isspace3(buffer[j]))
		j++;
	if (j == i)
		return (0);
	str = &buffer[i];
	*ini = i;
	*fin = j;
	return (str);
}

int	check_args_from_input(t_input_args *piargs, char *aux1, char *aux2)
{
	if (!aux2)
	{
		piargs->i_name = ft_strdup(RUSH02_NUMBERS_DICT);
		piargs->i_number = ft_strdup(aux1);
	}
	else
	{
		piargs->i_name = ft_strdup(aux1);
		piargs->i_number = ft_strdup(aux2);
	}
	return (0);
}

int	read_args_from_input(t_input_args *piargs)
{
	char	buffer[100];
	int		i;
	int		j;
	char	*aux1;
	char	*aux2;

	ft_putstr("Enter arguments: ");
	i = read(STDIN_FILENO, buffer, 80);
	buffer[i] = 0;
	aux1 = next_word(buffer, &i, &j);
	if (!aux1)
		return (1);
	aux2 = 0;
	if (buffer[j])
	{
		buffer[j++] = 0;
		aux2 = next_word(&buffer[j], &i, &j);
		if (aux2)
			aux2[j] = 0;
	}
	return (check_args_from_input(piargs, aux1, aux2));
}

void	show_arr_entries(t_dictionary *pdic)
{
	int	i;

	i = 0;
	while (i <= pdic->last_entry)
	{
		printf ("INSERT (%d): \"%s\":\"%s\"\n",
			i,
			pdic->pentry[i].nbr,
			pdic->pentry[i].translation);
		i++;
	}
}
