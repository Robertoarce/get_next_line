/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tester.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rarce <rarce@42.student.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/04 10:47:06 by rarce             #+#    #+#             */
/*   Updated: 2020/06/04 16:47:27 by rarce            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>
#include <limits.h>
#include "get_next_line.h"

int	main(void)
{
	int		i;
	int		fd;
	char	*line;
	int		ret;
	
	printf("BUFFER_SIZE = %d\n", BUFFER_SIZE);
	fd = open("42", O_RDONLY);
	i = 0;
	while ((ret = get_next_line(fd, &line)) == 1)
	{
		printf("%3d : %s \n", ++i, line);
		free(line);
	}
	if (ret == -1)
		printf("error\n");
	else if (ret == 0)
	{
		printf("at EOF: [%s]\n", line);
		free(line);
		printf("EOF\n");
	}
	close(fd);
	return (0);
}
