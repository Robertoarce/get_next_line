/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: roberto <rarce@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/08 18:08:45 by roberto           #+#    #+#             */
/*   Updated: 2020/06/22 18:44:58 by rarce            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

int		get_next_line(int fd, char **line)
{
	static char	*fd_backup[32];
	char		buf[BUFFER_SIZE + 1];
	int			read_size;
	int			cut;
	char		*tmp;

	if (!line || fd < 0 || BUFFER_SIZE < 1 || read(fd, buf, 0) < 0)
		return (-1);

	/*------block 1 START--------*/
	if (!fd_backup[fd])
		fd_backup[fd] = ft_strnew(0); 
	/*------block 1 END--------*/


	while ((read_size = read(fd, buf, BUFFER_SIZE)) > 0)
	{


		buf[read_size] = '\0';
	/*------block 2 = STOCK ALL BUF in BACKUP= START--------*/
		cut = ft_strlen(buf);
		tmp = ft_strnew(cut);
		
		if (cut > 0) //buf not empty
		{
			ft_strncpy(&tmp,fd_backup[fd],ft_strlen(fd_backup[fd]));
			ft_strncpy(&tmp,buf,cut);
		}
		free(fd_backup[fd]);
		fd_backup[fd] = tmp;

	/*------block 2 END --------*/
 
			cut = ft_findnl(fd_backup[fd]); 
		
		if (  cut > -1 ) /* there is a \n new line. */
		{ 
			if (!(*line = ft_strnew(cut)))
					return (-1);
			ft_strncpy(&*line,fd_backup[fd], cut); /*copy backup[:cut] to line*/
			

			cut  = ft_strlen(&fd_backup[fd][cut + 1]);
		if(!(tmp = ft_strnew(cut)))
				return (-1);
			ft_strncpy(&tmp, &fd_backup[fd][cut + 1], cut); /*copy backup[cut:] to tmp*/
			free(fd_backup[fd]); /*free backup*/
			fd_backup[fd] = tmp; /*assign backup*/
			
		return (1);
		}
	}
	
	/* Nothing else to read
	 * all is in fd_backup[fd]*/

	cut = ft_findnl(fd_backup[fd]); 
	if ( cut  > -1 ) /* There is a line but we dont know if is the end*/
	{
		if (!(*line = ft_strnew(cut)))
				return (-1);
		ft_strncpy(&*line,fd_backup[fd], cut); /*copy backup[:cut] to line*/
		
		cut  = ft_strlen(&fd_backup[fd][cut + 1]);
		if(!(tmp = ft_strnew(cut)))
			return (-1);
		ft_strncpy(&tmp, &fd_backup[fd][cut + 1],cut); /*copy backup[cut:] to tmp*/
		free(fd_backup[fd]); /*free backup*/
		fd_backup[fd] = tmp; /*assign backup*/
			
		return (1);
	}

	/* There is no more to read and no line ===> SEND ALL*/
		
		if (!(*line = ft_strnew(cut)))
				return (-1);
		ft_strncpy(&*line,fd_backup[fd], cut); /*copy backup[:cut] to line*/
		
		free(fd_backup[fd]); /*free backup*/
	return (0);
}

