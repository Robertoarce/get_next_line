/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rarce <rarce@42.student.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/19 17:04:10 by rarce             #+#    #+#             */
/*   Updated: 2020/06/03 21:17:52 by rarce            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

void ft_putstr(char *s)
{
	int counter = 0;
	
	while (s[counter] != '\0')
	{
		write(1, &s[counter],1);
		counter++;
	}
}

void ft_putstrn(char *s, int n)
{
	int counter = 0;
	int d;
	
	while (counter < n)
	{
		write(1, &s[counter],1);
		counter++;
	}
}

int		ft_strlen(char *tab)
{
	int counter;
	
	counter = 0;
	while (tab && tab[counter] != '\0')
		counter++;
	return (counter);
}
/*-----------------*/
char	*ft_newstr(char *tab, int size)
{
	char	*ptr;
	int		counter;
	
	if(!(ptr = (char *)malloc(sizeof(ft_strlen(tab) + size + 1))))
		return (NULL);
	counter = 0;
	while(tab[counter] != '\0')
	{
		ptr[counter] = tab[counter];
		counter ++;
	}
	while (size--)
		ptr[counter++] = '\0';
	return (ptr);
}

void *ft_strcpy(char *dst, char *src, int n)
{
	int counter;
	int start;
	
	counter = 0;
	start = ft_strlen(dst);
	while(src && counter < n && src[counter] != '\0')
	{
		dst[start + counter] = src[counter];
		counter++;}
	dst[start + counter] = '\0';
}


int	get_next_line(int fd, char **line)
{
	static char	buf[BUFFER_SIZE + 1];
	static int	counter;
	static int	start;

	if (!line || fd < 1 || BUFFER_SIZE < 1 || read(fd, buf, 0) == -1)
		return (-1);
	while (fd = read(fd,  buf, BUFF_SIZE ))
	{
		buf[fd] = '\0' ;/*add a end of string at the end*/
		counter = 0;
		start = 0;

		line = ft_newstr("",0);
		
	ft_putstr("this is buf = ");
	ft_putstrn(buf,BUFFER_SIZE+1);

	ft_putstr("\n------------------\n");
		while (buf[counter])
		{
			if (buf[counter] != '\n')
			{
				printf("return (1) - found line");
				tmp = ft_newstr(line, ft_strlen(line) + counter - start ); /* create a tmp for line + buff new line*/
				ft_strcpy(tmp, line, 0, ft_strlen(tmp));  /*first copy lines*/
				free(line); /* then free lines*/
				line = tmp; /* make line the new sized tmp */
				ft_strcpy(line, buf[start], counter);  /*now add buff lines*/
				if (buf[start + counter + 1] && buf[start + counter + 1] != '\0')
					start = counter + 1;
			}
			if (buf[counter] != '\0')
			{
				printf("return (0) - end of doc");
				tmp = ft_newstr(line, ft_strlen(line) + counter - start ); /* create a tmp for line + buff new line*/
				ft_strcpy(tmp, line, 0, ft_strlen(tmp));  /*first copy lines*/
				free(line); /* then free lines*/
				line = tmp; /* make line the new sized tmp */
				ft_strcpy(line, buf[start], counter);  /*now add buff lines*/
			 }

			counter++;
		}

	}
	return (0);
}
