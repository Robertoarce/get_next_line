/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bla.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: roberto <rarce@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/08 18:08:45 by roberto           #+#    #+#             */
/*   Updated: 2020/06/18 21:36:45 by roberto          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include "get_next_line_utils.c"
#include <unistd.h>
#include <stdio.h>
#include <limits.h>
#include <fcntl.h>


int		get_next_line(int fd, char **line)
{
	static char	*fd_backup[32];
	char		buf[BUFFER_SIZE + 1];
	int			read_size;
	int			cut;
	char		*tmp;
	int laps= 0;

	if (!line || fd < 0 || BUFFER_SIZE < 1 || read(fd, buf, 0) < 0)
		return (-1);

	cut = 0;
	*line  = ft_strnew("",0); //if  first time
	
	while ((read_size = read(fd, buf, BUFFER_SIZE)) > 0)
	{

		buf[read_size] = '\0';
		
		if (!fd_backup[fd])
			fd_backup[fd] = ft_strnew("",0); //if  first time



		if(!(fd_backup[fd] = ft_strjoin(&fd_backup[fd],buf, ft_strlen(&buf[0])))) /*add all buf*/
			return(-1);
		
		if (ft_findchar(fd_backup[fd], '\n') > -1) /* there is a new line in backup */
		{


			cut = ft_findchar(fd_backup[fd], '\n'); 
			if(!( ft_substr(&*line,fd_backup[fd], cut))) /*creates a line with all backup*/
				return (-1);
			if(!(tmp = ft_strnew(&fd_backup[fd][cut + 1],0))) /*tmp up becomes the rest*/
				return (-1);
			free(fd_backup[fd]); /*free backup*/
			fd_backup[fd] = tmp; /*assign backup*/

		
		return (1);
		}
laps++;
	}
				
	
		cut = ft_strlen(fd_backup[fd]); /*EOF position in backup*/
	
		if(!(ft_substr(&*line,fd_backup[fd], cut))) /*creates a line with all backup*/
		return (-1);

	
		if(fd_backup[fd]) /*tmp up becomes the rest*/
			free(fd_backup[fd]); /*free backup*/
		return (0);
}

int main(void)
{
	char *line = 0;
	int ret;
	int fd;

	
	fd = open("42", O_RDONLY);
	while ((ret = get_next_line(fd, &line)) > 0)
	{
	
	printf("%s\n", line);
		free(line);
	}
	printf("%s\n", line);
	free(line);
	return (0);
}


