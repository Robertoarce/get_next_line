/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rarce <rarce@42.student.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/19 17:04:25 by rarce             #+#    #+#             */
/*   Updated: 2020/07/06 17:52:07 by titorium         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE	4800
# endif

# define SUCCESS		0
# define FAILURE		-1
# define TRUE			1
# define FALSE			0

# include <unistd.h>
# include <stdlib.h>

int		get_next_line(int fd, char **line);
int		ft_strlen(char *tab);
char	*ft_strnew(int size);
char	*ft_substr(char *tab, int size);
char	*ft_strjoin(char **fd_backup, char *b, int cut_pos);
int		ft_findnl(char *tab);
char	*ft_strncpy(char *dst, char *src, int size);
#endif
