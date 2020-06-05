/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rarce <rarce@42.student.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/19 17:04:41 by rarce             #+#    #+#             */
/*   Updated: 2020/06/04 17:44:53 by rarce            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

void ft_putchar(char c)
{
	write(1, &c, 1);
}

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
	while(tab[counter] != '\0' && tab != NULL)
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
