/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rarce <rarce@42.student.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/19 17:04:41 by rarce             #+#    #+#             */
/*   Updated: 2020/05/25 18:36:25 by rarce            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*ft_strnew(char *ptr, size_t size)
{
	int counter;
	
	if (!(ptr = (char *)malloc(sizeof(char) * (size +1))))
		return (NULL);
	counter = 0;
	while (counter < size + 1)
	{
		ptr[counter] = '\0';
		counter++;
	}
	return (ptr);
}

int		ft_strlen(char *s)
{
	int counter;

	counter = 0;
	while (s[counter] != '\0')
		counter++;
	return (counter);
}

char	*ft_strdup(char *dest, char *src)
{
	char	*ptr;
	int		counter;
	int		start;
	
	if (!(ptr = ft_strnew(ptr, ft_strlen(dest) + ft_strlen(src))))
		return (NULL);
	start = 0;
	while (dest[start] != '\0')
	{
		ptr[start] = dest[start];
		start++;
	}
	counter = 0;
	while (src[counter] != '\0')
	{
		ptr[start + counter] = src[counter];
		counter++;
	}
	ptr[start + counter] = '\0';
	return (ptr);
}

void ft_putstrn(char *s)
{
	int counter;

	counter = 0;
	while (counter < ft_strlen(s))
		write(1, &s[counter++], 1);
}
