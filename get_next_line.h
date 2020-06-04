/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rarce <rarce@42.student.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/19 17:04:25 by rarce             #+#    #+#             */
/*   Updated: 2020/05/25 18:45:04 by rarce            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H


# ifndef		BUFFER_SIZE
#  define	BUFFER_SIZE 32
# endif
char *ft_strnew(char *ptr, size_t size);
int	ft_strlen(char *s);
char *ft_strdup(char *dest, char *src);
void ft_putstrn(char *s);
int	get_next_line(int fd, char **line);

#endif
