/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tester.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rarce <rarce@42.student.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/04 10:47:06 by rarce             #+#    #+#             */
/*   Updated: 2020/06/25 13:56:02 by roberto          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include <fcntl.h>
#include <stdio.h>
#include "get_next_line.h"

int main()
{
	int fd;
	int r;
	char *l;

	fd = open("44", O_RDONLY);
	while((r = get_next_line(fd, &l))> 0)
	{
		printf("%d |%s\n", r, l);
		free(l);
	}
	if (r == -1)
		l = NULL;
	printf("%d |%s\n", r, l);
	if (l)
		free(l);
	//while(1);
	return (0);
}
