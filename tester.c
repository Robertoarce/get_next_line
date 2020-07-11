/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tester.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rarce <rarce@42.student.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/04 10:47:06 by rarce             #+#    #+#             */
/*   Updated: 2020/07/11 13:50:47 by titorium         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include <fcntl.h>
#include <stdio.h>
#include "get_next_line.h"

int main(int argc, char **argv)
{
	int fd;
	int r;
	char *l;
	(void)argc;
	
	fd = open(argv[1], O_RDONLY);
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
	close(fd);
	//while(1);
	return (0);
}
