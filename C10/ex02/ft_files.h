/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_files.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: enricant <enricant@42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/30 07:27:59 by enricant          #+#    #+#             */
/*   Updated: 2025/07/30 09:33:30 by enricant         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#ifndef FT_FILES_H
# define FT_FILES_H

# include <fcntl.h>
# include <unistd.h>
# include <errno.h>
# include <string.h>
# include <stdio.h>
# include <stdlib.h>

# define FT_FILES_BUF_SIZE 29958

extern char	*basename(const char *name);

char		*ft_read_file_to_buffer(int fd, int *total_size);
void		ft_memcpy(char *dest, char *src, int size);
void		ft_putstr_fd(char *str, int file);
void		ft_print_error(char *prog_name, char *filename);
void		ft_print_header(char *filename);
int			ft_atoi(char *str);
int			ft_strcmp(char *s1, char *s2);

#endif
