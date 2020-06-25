/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rarce <rarce@42.student.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/19 17:04:41 by rarce             #+#    #+#             */
/*   Updated: 2020/06/25 14:21:39 by roberto          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

void ft_putchar(char c)
{
	write(1,&c,1);
}

/*--------------------------------------------------------------------------------------------------------*/
/*--------------------------------------------------------------------------------------------------------*/

void	ft_putnbr(int nb)
{
	if (nb < 10 && nb >= 0)
	{
		ft_putchar(nb + '0');
	}
	else if (nb >= 10)
	{
		ft_putnbr(nb / 10);
		ft_putchar(nb % 10 + '0');
		if (nb < 0)
			ft_putchar('-');
	}
	else
	{
		ft_putchar('-');
		ft_putnbr(nb * -1);
	}
}

/*--------------------------------------------------------------------------------------------------------*/
/*--------------------------------------------------------------------------------------------------------*/

void ft_putstr(char *c)
{
	int counter = 0;
	while (c[counter] != '\0')
	{
		ft_putchar(c[counter]);
		counter++;
	}
}	

/*--------------------------------------------------------------------------------------------------------*/
/*--------------------------------------------------------------------------------------------------------*/

int		ft_strlen(char *tab)
{
	int counter;

	counter = 0;
	while (tab[counter] != '\0')
		counter++;
	return (counter);
}

/*--------------------------------------------------------------------------------------------------------*/
/*--------------------------------------------------------------------------------------------------------*/
char	*ft_strnew(int size)
{
	/* creates a ptr + calloc)*/
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

/*--------------------------------------------------------------------------------------------------------*/
/*--------------------------------------------------------------------------------------------------------*/

char	*ft_substr( char *tab, int size)
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

/*--------------------------------------------------------------------------------------------------------*/
/*--------------------------------------------------------------------------------------------------------*/

char *ft_strncpy(char *dst,char *src, int size)
{
	int counter;
	int start;

	if (size == -1)
		size = ft_strlen(src);
	counter = 0;
	start = 0;
	while(dst[start] != '\0')
		start++;
	while(size-- && src[counter] != '\0')
	{
		dst[start + counter] = src[counter];
		counter++;	
	}
	dst[start + counter] = '\0';
	return (dst);
}

/*--------------------------------------------------------------------------------------------------------*/
/*--------------------------------------------------------------------------------------------------------*/

int ft_findnl(char *tab)
{
	int counter;
	
	counter = 0;
	while (tab[counter] != '\0')
	{
		if (tab[counter] == '\n')
			return(counter);
		counter++;
	}
	return (-1);
}

/*--------------------------------------------------------------------------------------------------------*/
/*--------------------------------------------------------------------------------------------------------*/

/*
char *ft_strjoin(char **a, char *b, int cut_pos)
{
	char	*ptr;
	int		start;
	char	*ptrb;

*Joins a and b (until cut_pos) into a new str 
 *if A is missing: frees A + creates new A + adds B(until cut) + returns new A
 *if B is missing: returns A;
 *else:
 *	creates ptr = A +b(until cut) + free A + a = ptr  + return new A
 */
/*
	if(!*b )
		return (*a);
		
	start = ft_strlen(*a);
	if (!(ptr = ft_strnew(start + cut_pos)))
		return (NULL);

	ft_strncpy(&ptr, *a, start);
	ptrb = &ptr[start + 1];
	ft_strncpy(&ptrb, b, cut_pos);
	free (*a);
	*a = ptr;
	return (*a);
}*/
