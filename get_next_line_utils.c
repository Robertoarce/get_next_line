/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rarce <rarce@42.student.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/19 17:04:41 by rarce             #+#    #+#             */
/*   Updated: 2020/06/09 18:27:57 by roberto          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

int		ft_strlen(char *tab)
{
	int counter;

	counter = 0;
	while (tab && tab[counter] != '\0')
		counter++;
	return (counter);
}

char	*ft_newstr(char *tab, int size)
{
	char	*ptr;
	int		counter;

	if (!(ptr = (char *)malloc(sizeof(ft_strlen(tab) + size + 1))))
		return (NULL);
	counter = 0;
	while (tab[counter] != '\0' && tab != NULL)
	{
		ptr[counter] = tab[counter];
		counter++;
	}
	while (size-- + 1)
		ptr[counter++] = '\0';
	return (ptr);
}

void	*ft_strcpy(char *dst, char *src, int n)
{
	int counter;
	int start;

	counter = 0;
	start = ft_strlen(dst);
	while (src && counter < n && src[counter] != '\0')
	{
		dst[start + counter] = src[counter];
		counter++;
	}
	dst[start + counter] = '\0';
	return (0);
}

int		bla(char **line, int counter, int start, char *buf)
{
	char *tmp;

	if (!(tmp = ft_newstr(*line, ft_strlen(*line) + counter - start)))
		return (-1);
	if (buf[counter] == '\n')
		ft_strcpy(*line, &buf[start], counter - start);
	else
		ft_strcpy(*line, &buf[start], counter - start - 1);
	free(tmp);
	if (buf[counter + 1] != '\0')
		start = counter + 1;
	return (start);
}

void	init(char *buf, char **line, int *counter, int *start)
{
	buf[0] = '\0';
	*line = ft_newstr("", 0);
	*counter = 0;
	*start = 0;
}
