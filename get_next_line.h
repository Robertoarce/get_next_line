/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rarce <rarce@42.student.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/19 17:04:25 by rarce             #+#    #+#             */
/*   Updated: 2020/06/22 18:43:05 by rarce            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 32
# endif

# define SUCCESS 1
# define FAILURE 0
# define TRUE 1
# define FALSE 0

# include <unistd.h>
# include <stdlib.h>

int		get_next_line(int fd, char **line);
int		ft_strlen(char *tab);
char	*ft_strnew(int size);
char	*ft_substr( char *tab, int size);
char	*ft_strjoin(char **fd_backup, char *b, int cut_pos);
int		ft_findnl(char *tab);
void	ft_strncpy(char **dst,char *src, int size);
	

#endif
