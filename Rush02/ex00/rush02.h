/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rush02.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hventuri <hventuri@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/25 20:45:44 by enricant          #+#    #+#             */
/*   Updated: 2025/07/30 17:18:59 by enricant         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef RUSH02_H
# define RUSH02_H

# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>
# include <fcntl.h>

typedef struct s_input_args
{
	char	*i_name;
	char	*i_number;
	char	*o_number;
}	t_input_args;

typedef struct s_dic_entry
{
	char	*nbr;
	char	*translation;
}	t_dic_entry;

typedef struct s_dictionary
{
	char		*name;
	int			file;
	t_dic_entry	*pentry;
	int			size_arr_entries;
	int			last_entry;
}	t_dictionary;

# define RUSH02_NUMBERS_DICT "numbers.dict"
# define RUSH02_MAX_ENTRIES	100

# define RUSH02_NUMBER		1
# define RUSH02_TRANSLATION	2

# define RUSH02_INI	0
# define RUSH02_END	1

# define RUSH02_NBR_TRX	"0"
# define RUSH02_NBR_ENG	"zero"
# define RUSH02_NBR_SPA	"cero"
# define RUSH02_NBR_FRN	"zéro"

t_dictionary	*open_dictionary(char *filename);
t_dictionary	*close_dictionary(t_dictionary *pdic);
t_dictionary	*load_dictionary(t_dictionary *pdic);
void			free_dic_arr_entry(t_dictionary *pdic);
void			sort_dictionary_entries(t_dictionary *p);
void			show_arr_entries(t_dictionary *p);
void			limpia_nbr(char *nbr);
int				insert_dic_entry(t_dictionary *pdic,
					char *nbr, char *translation);
int				ft_isspace3(char c);
int				read_args_from_input(t_input_args *piargs);
int				read_dictionary_entries(t_dictionary *p,
					char *n);
int				translate_nbr_to_dict_aux(t_dictionary *pdic,
					char *nbr, int *len, int *rango);
int				translate_nbr_to_dict_00s(t_dictionary *p,
					char *n);
int				translate_nbr_to_dict(t_dictionary *p,
					char *n);
int				translate_nbr_to_dict_generic(t_dictionary *p,
					char *n);
int				translate_nbr_to_dict_eng(t_dictionary *p,
					char *n);
int				translate_nbr_to_dict_spa(t_dictionary *p,
					char *n);
int				translate_nbr_to_dict_frn(t_dictionary *p,
					char *n);
int				count_zeros_from(char *nbr, int from);
int				count_zeros_from_end(char *nbr);
int				count_zeros_from_ini(char *nbr);
int				get_rango(t_dictionary *pdic, char *nbr);
int				ft_atoi(char *str);
int				ft_strlen(char *str);
int				ft_strcmp(char *str1, char *str2);
int				ft_strncmp(char *str1, char *str2, int n);
char			*ft_strdup(char *src);
char			*ft_strcpy(char *dest, char *src);
void			ft_putstr(char *str);
void			ft_memcpy(char *dest, char *src, int size);
void			ft_swap_structs(char *dest, char *src, int size);
#endif
