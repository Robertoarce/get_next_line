/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: roberto <rarce@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/08 18:08:45 by roberto           #+#    #+#             */
/*   Updated: 2020/06/25 14:40:40 by roberto          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include <stdio.h>
#include "get_next_line.h"

int		get_next_line(int fd, char **line)
{
	static char	*fd_backup[32];
	char		buf[BUFFER_SIZE + 1];
	int			read_size;
	int			cut;
	char		*tmp;
//	char k[]="=*+=+=*==+=+=*=+=*=+=*=+==";

	if (!line || fd < 0 || BUFFER_SIZE < 1 || read(fd, buf, 0) < 0)
		return (-1);

	/*------block 1 =make sure fd  exists = START--------*/
	if (!fd_backup[fd])
	{	
		if(!(fd_backup[fd] = ft_strnew(0)))
			return (-1);
	}
	/*------block 1 END--------*/


	while ((read_size = read(fd, buf, BUFFER_SIZE)) > 0) /*read while possible*/
	{
		buf[read_size] = '\0';
	/*------block 2 = STOCK ALL BUF in BACKUP= START--------*/
		if(!(tmp = ft_strnew(ft_strlen(buf) + ft_strlen(fd_backup[fd]))))
				return (-1);
		
		tmp = ft_strncpy(tmp, fd_backup[fd], -1);
		tmp = ft_strncpy(tmp, buf, -1);
		
		free(fd_backup[fd]);
		fd_backup[fd] = tmp;

	/*------ block 2 END --------*/
 
		cut = ft_findnl(fd_backup[fd]); 
		
	/*------ block 3 = if there is a NEW LINE  --------*/

		if (  cut > -1 ) /* there is a \n new line. */
		{ 
			if (!(*line = ft_strnew(cut)))
					return (-1);
			*line = ft_strncpy(*line,fd_backup[fd], cut); /*copy backup[:cut] to line*/

			if(!(tmp = ft_strnew(ft_strlen(&fd_backup[fd][cut + 1]))))
				return (-1);
			tmp = ft_strncpy(tmp, &fd_backup[fd][cut + 1], -1); /*copy backup[cut:] to tmp*/
			
			free(fd_backup[fd]); /*free backup*/
			fd_backup[fd] = tmp; /*assign backup*/
			
		return (1);
		}
	/*------ block 3  END --------*/
	
	}
	
	/* Nothing else to read
	 * all is in fd_backup[fd]*/
	
	
	/*------ block 4 = read from backup , no buffer, no more read lines  --------*/
	
		cut = ft_findnl(fd_backup[fd]); 

		if (  cut > -1 ) /* there is a \n new line. */
		{ 
			if (!(*line = ft_strnew(cut)))
					return (-1);
			*line = ft_strncpy(*line,fd_backup[fd], cut); /*copy backup[:cut] to line*/

			if(!(tmp = ft_strnew(ft_strlen(&fd_backup[fd][cut + 1]))))
				return (-1);
			tmp = ft_strncpy(tmp, &fd_backup[fd][cut + 1], -1); /*copy backup[cut:] to tmp*/
			
			free(fd_backup[fd]); /*free backup*/
			fd_backup[fd] = tmp; /*assign tmp to backup*/

		return (1);
		}

	// There is no more to read and no New line until EoF  ===> SEND ALL
		
		if (!(*line = ft_strnew(ft_strlen(fd_backup[fd]) + 1)))
				return (-1);
		*line = ft_strncpy(*line,fd_backup[fd],-1); //copy backup[:cut] to line
		
	//	free(fd_backup[fd][0]); //free backup
	return (0);
}

