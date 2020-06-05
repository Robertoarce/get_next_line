	/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rarce <rarce@42.student.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/19 17:04:25 by rarce             #+#    #+#             */
/*   Updated: 2020/06/04 17:53:57 by rarce            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# ifndef	BUFFER_SIZE
#  define	BUFFER_SIZE 32
# endif

# include <unistd.h>
# include <stdlib.h>

int		get_next_line(int fd, char **line);
void	ft_putstr(char *s);
void	ft_putstrn(char *s, int n);
int		ft_strlen(char *tab);
char	*ft_newstr(char *tab, int size);
void	*ft_strcpy(char *dst, char *src, int n);

void	ft_putnbr(int nb);

#endif
