/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rush02_01.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: enricant <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/25 20:57:20 by enricant          #+#    #+#             */
/*   Updated: 2025/07/28 12:12:47 by enricant         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rush02.h"

void	sort_dictionary_entries(t_dictionary *pdic)
{
	t_dic_entry	*p;
	int			i;
	int			count;

	p = pdic->pentry;
	while (42)
	{
		count = 0;
		i = 0;
		while (i < pdic->last_entry - 1)
		{
			if (ft_strlen(p[i].nbr) > ft_strlen(p[i + 1].nbr)
				|| (ft_strlen(p[i].nbr) == ft_strlen(p[i + 1].nbr)
					&& ft_strcmp(p[i].nbr, p[i + 1].nbr) > 0))
			{
				ft_swap_structs ((char *)&p[i],
					(char *)&p[i + 1], sizeof(t_dic_entry));
				count++;
			}
			i++;
		}
		if (!count)
			return ;
	}
}

int	cut_dic_entry_line(char *str, int type)
{
	int		len;

	len = 0;
	while (str[len])
	{
		if (type == RUSH02_NUMBER)
		{
			if (str[len] < '0' || str[len] > '9')
			{
				if (str[len] == ':' || str[len] == ' ')
					break ;
				else if (str[len] < 32 || str[len] > 126)
					return (0);
			}
		}
		else if (type == RUSH02_TRANSLATION)
		{
			if (!str[len])
				break ;
		}
		else
			return (0);
		len++;
	}
	return (len);
}

int	read_dictionary_entries(t_dictionary *pdic, char *buffer)
{
	int		len;
	int		i;
	int		count;

	len = cut_dic_entry_line(buffer, RUSH02_NUMBER);
	if (!len)
		return (0);
	count = 0;
	i = len;
	while (buffer[i] == ':' || buffer[i] == ' ')
	{
		if (buffer[i] == ':')
			count++;
		i++;
	}
	if (count != 1)
		return (0);
	if (!cut_dic_entry_line(&buffer[i], RUSH02_TRANSLATION))
		return (0);
	insert_dic_entry(pdic, buffer, &buffer[i]);
	pdic->pentry[pdic->last_entry].nbr[len] = 0;
	limpia_nbr(pdic->pentry[pdic->last_entry].nbr);
	return (1);
}

int	insert_dic_entry(t_dictionary *pdic, char *nbr, char *translation)
{
	t_dic_entry	*pentry;
	int			size;

	if (pdic->last_entry + 1 >= pdic->size_arr_entries)
	{
		size = pdic->size_arr_entries / RUSH02_MAX_ENTRIES;
		pentry = malloc(sizeof(t_dic_entry) * (size + 1)
				* RUSH02_MAX_ENTRIES);
		if (!pentry)
			return (1);
		if (pdic->pentry)
		{
			ft_memcpy ((char *)pentry, (char *)pdic->pentry,
				pdic->size_arr_entries * sizeof(t_dic_entry));
			free(pdic->pentry);
		}
		pdic->pentry = pentry;
		pdic->size_arr_entries = (size + 1) * RUSH02_MAX_ENTRIES;
	}
	pdic->last_entry++;
	pdic->pentry[pdic->last_entry].nbr = ft_strdup(nbr);
	pdic->pentry[pdic->last_entry].translation = ft_strdup(translation);
	return (0);
}

void	free_dic_arr_entry(t_dictionary *pdic)
{
	int	i;

	if (!pdic)
		return ;
	if (pdic->pentry)
	{
		i = 0;
		while (i <= pdic->last_entry)
		{
			if (pdic->pentry[i].nbr)
				free(pdic->pentry[i].nbr);
			if (pdic->pentry[i].translation)
				free(pdic->pentry[i].translation);
			i++;
		}
		free(pdic->pentry);
	}
	pdic->size_arr_entries = 0;
	pdic->last_entry = 0;
	pdic->pentry = 0;
}
