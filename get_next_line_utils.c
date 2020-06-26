/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rarce <rarce@42.student.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/19 17:04:41 by rarce             #+#    #+#             */
/*   Updated: 2020/06/26 18:46:17 by roberto          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

int		ft_strlen(char *tab)
{
	int counter;

	counter = 0;
	while (tab[counter] != '\0')
		counter++;
	return (counter);
}

char	*ft_strnew(int size)
{
	char	*ptr;
	int		counter;

	counter = 0;
	if (!(ptr = (char *)malloc(sizeof(char) * (size + 1))))
		return (NULL);
	while (counter < size)
	{
		ptr[counter] = '\0';
		counter++;
	}
	ptr[counter] = '\0';
	return (ptr);
}

char	*ft_substr(char *tab, int size)
{
	int		counter;
	char	*ptr;

	ptr = ft_strnew(size);
	counter = 0;
	while (size--)
	{
		ptr[counter] = tab[counter];
		counter++;
	}
	ptr[counter] = '\0';
	return (ptr);
}

char	*ft_strncpy(char *dst, char *src, int size)
{
	int counter;
	int start;

	if (size == -1)
		size = ft_strlen(src);
	counter = 0;
	start = 0;
	while (dst[start] != '\0')
		start++;
	while (size-- && src[counter] != '\0')
	{
		dst[start + counter] = src[counter];
		counter++;
	}
	dst[start + counter] = '\0';
	return (dst);
}

int		ft_findnl(char *tab)
{
	int counter;

	counter = 0;
	while (tab[counter] != '\0')
	{
		if (tab[counter] == '\n')
			return (counter);
		counter++;
	}
	return (-1);
}
