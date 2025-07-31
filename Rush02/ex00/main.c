/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hventuri <hventuri@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/25 20:51:38 by enricant          #+#    #+#             */
/*   Updated: 2025/07/30 14:00:58 by enricant         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rush02.h"

int	parse_input_number(t_input_args *piargs)
{
	int	flag;
	int	i;

	if (!piargs)
		return (1);
	flag = 0;
	i = 0;
	while (piargs->i_number[i])
	{
		if (piargs->i_number[i] == ' ' && flag)
			return (1);
		else if ((piargs->i_number[i] != ' ')
			&& (piargs->i_number[i] < '0'
				|| piargs->i_number[i] > '9'))
			return (1);
		else if (piargs->i_number[i] >= '0'
			&& piargs->i_number[i] <= '9')
			flag = 1;
		i++;
	}
	return (0);
}

t_input_args	*free_arguments(t_input_args *pargs)
{
	if (!pargs)
		return (0);
	if (pargs->i_name)
		free(pargs->i_name);
	if (pargs->i_number)
		free(pargs->i_number);
	if (pargs->o_number)
		free(pargs->o_number);
	free(pargs);
	return (0);
}

t_input_args	*parse_arguments(t_input_args *piargs, int argc, char **argv)
{
	if (!piargs)
		return (0);
	piargs->i_name = (char *)0;
	piargs->i_number = (char *)0;
	piargs->o_number = (char *)0;
	if (argc == 1)
	{
		if (read_args_from_input(piargs))
			return (free_arguments(piargs));
	}
	else if (argc == 2)
	{
		piargs->i_name = ft_strdup(RUSH02_NUMBERS_DICT);
		piargs->i_number = ft_strdup(argv[1]);
	}
	else if (argc == 3)
	{
		piargs->i_name = ft_strdup(argv[1]);
		piargs->i_number = ft_strdup(argv[2]);
	}
	else
		return (free_arguments(piargs));
	limpia_nbr(piargs->i_number);
	return (piargs);
}

int	main(int argc, char **argv)
{
	t_input_args	*p_in_args;
	t_dictionary	*pdic;

	p_in_args = malloc(sizeof(t_input_args));
	p_in_args = parse_arguments(p_in_args, argc, argv);
	if (parse_input_number(p_in_args))
	{
		ft_putstr("Error\n");
		free_arguments(p_in_args);
		return (1);
	}
	pdic = open_dictionary(p_in_args->i_name);
	if (!pdic)
	{
		ft_putstr("Dict Error\n");
		free_arguments(p_in_args);
		return (1);
	}
	if (!load_dictionary(pdic))
		ft_putstr("Dict Error");
	else if (translate_nbr_to_dict(pdic, p_in_args->i_number))
		ft_putstr("Dict Error");
	ft_putstr("\n");
	close_dictionary(pdic);
	free_arguments(p_in_args);
	return (0);
}
