/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bsq.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hventuri <hventuri@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/25 20:45:44 by enricant          #+#    #+#             */
/*   Updated: 2025/07/31 15:05:58 by enricant         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BSQ_H
# define BSQ_H

# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>
# include <fcntl.h>

typedef struct s_eval_coordinates
{
	int	x;
	int	y;
	int	width;
}	t_eval_coordinates;

typedef struct s_point
{
	int	x;
	int	y;
}	t_point;

typedef struct s_rectangle
{
	t_point	ul;
	t_point	br;
}	t_rectangle;

typedef struct s_map
{
	char		*name;
	int			file;
	char		*pland;
	int			width;
	int			height;
	char		empty;
	char		obstacle;
	char		busy;
	t_rectangle	*pbrectangle;
}	t_map;

# define BSQ_MAP_DEFAULT_FILENAME "map.out"
# define BSQ_MAP_DEFAULT_WIDTH 20
# define BSQ_MAP_DEFAULT_EMPTY '.'
# define BSQ_MAP_DEFAULT_OBSTACLE 'o'
# define BSQ_MAP_DEFAULT_BUSY 'x'

t_map	*open_map(char *filename);
t_map	*close_map(t_map *pmap);
t_map	*load_map(t_map *pmap);
int		find_biggest_rectangle_in_map(t_map *p);
int		ft_file_size(char *str);
int		plot_map_land(t_map *pmap);
int		read_to_endline(t_map *pm, char *bfi, int sz, char *bfo);
int		read_map_header(t_map *pmap, char *buffer_in);
int		read_map_land(t_map *pmap, char *buffer_in, int size);
int		ft_isspace3(char c);
int		ft_sizenbr(char *str);
int		ft_atoi(char *str);
int		ft_strlen(char *str);
int		ft_strcmp(char *str1, char *str2);
char	*ft_strdup(char *src);
char	*ft_strcpy(char *dest, char *src);
void	ft_putstr(char *str);
void	ft_memcpy(char *dest, char *src, int size);
void	ft_memset(char *dest, int size, char c);
void	ft_swap_structs(char *dest, char *src, int size);
#endif
