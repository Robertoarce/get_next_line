/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: roberto <rarce@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/08 18:08:45 by roberto           #+#    #+#             */
/*   Updated: 2020/06/19 17:14:07 by roberto          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

int		get_next_line(int fd, char **line)
{
	static char	*fd_backup[32];
	char		buf[BUFFER_SIZE + 1];
	int			read_size;
	int			cut;
	int	bklen=0;
	char		*tmp;

	if (!line || fd < 0 || BUFFER_SIZE < 1 || read(fd, buf, 0) < 0)
		return (-1);

	cut = 0;
	*line = ft_strnew(0);

	while ((read_size = read(fd, buf, BUFFER_SIZE)) > 0)
	{

		buf[read_size] = '\0';
		
		if (!fd_backup[fd])
			fd_backup[fd] = ft_strnew(0); 
		

		cut = ft_strlen(buf);
		bklen= ft_strlen(fd_backup[fd]);
		tmp = ft_strnew( bklen + cut);
		ft_strncpy (tmp,fd_backup[fd], bklen);
		ft_strncpy (tmp,buf ,cut);
		free(fd_backup[fd]);
		fd_backup[fd] = tmp;

//		if(!(fd_backup[fd] = ft_strjoin(&fd_backup[fd],buf, cut))) /*add all buf*/
//			return(-1);
		
		if (ft_findchar(fd_backup[fd], '\n') > -1) /* there is a new line in backup */
		{

			cut = ft_findchar(fd_backup[fd], '\n'); 
	//		if(*line)
	//			free(*line);
			if(!(*line = ft_strnew(cut)))
					return (-1);
			ft_strncpy(&**line,fd_backup[fd], cut);
			
			bklen = ft_strlen(&fd_backup[fd][cut + 1]);
		if(!(tmp = ft_strnew(bklen))) /*tmp up becomes the rest*/
				return (-1);
			ft_strncpy(tmp,&fd_backup[fd][cut + 1],bklen);

			free(fd_backup[fd]); /*free backup*/
			fd_backup[fd] = tmp; /*assign backup*/
		
		return (1);
		}
	}
	while ( ft_findchar(fd_backup[fd],'\n') )
	{

			cut = ft_findchar(fd_backup[fd], '\n'); 
	//		if(*line)
	//			free(*line);
			if(!(*line = ft_strnew(cut)))
					return (-1);
			ft_strncpy(&**line,fd_backup[fd], cut);
			
			bklen = ft_strlen(&fd_backup[fd][cut + 1]);
		if(!(tmp = ft_strnew(bklen))) /*tmp up becomes the rest*/
				return (-1);
			ft_strncpy(tmp,&fd_backup[fd][cut + 1],bklen);

			free(fd_backup[fd]); /*free backup*/
			fd_backup[fd] = tmp; /*assign backup*/
		
		return (1);
	}

	/*   It arrived to the EoF no new line '\n'  */			

			if(!(*line = ft_strnew(cut)))
					return (-1);
			ft_strncpy(&**line,fd_backup[fd], cut);
			
			bklen = ft_strlen(&fd_backup[fd][cut + 1]);
			free(fd_backup[fd]); /*free backup*/
		
		return (0);
}

