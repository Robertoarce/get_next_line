/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: roberto <rarce@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/08 18:08:45 by roberto           #+#    #+#             */
/*   Updated: 2020/06/09 19:13:10 by roberto          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

int		get_next_line(int fd, char **line)
{
	static char	buf[BUFFER_SIZE + 1];
	static int	start;
	static int	counter;

	if (!line || fd < 0 || BUFFER_SIZE < 1 || read(fd, buf, 0) == -1)
		return (-1);
	while ((start = read(fd, buf, BUFFER_SIZE)) > 1)
	{
		init(&buf[start], line, &counter, &start);
		while (buf[counter] != '\0')
		{
			if (buf[counter] == '\n' && buf[counter + 1])
			{
				if ((start = (bla(&(*line), counter, start, buf))) == -1)
					return (-1);
			}
			counter++;
			return (1);
		}
		if ((start = (bla(&(*line), counter, start, buf))) == -1)
			return (-1);
	}
	return (0);
}
