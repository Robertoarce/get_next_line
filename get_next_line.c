/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rarce <rarce@42.student.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/19 17:04:10 by rarce             #+#    #+#             */
/*   Updated: 2020/06/05 15:28:24 by rarce            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include <stdio.h>
#include "get_next_line.h"


int	get_next_line(int fd, char **line)
{
	static char	buf[BUFFER_SIZE + 1];
	static int	ret;
	static int	counter;
	static int	start;
	static char *tmp;

	int a= 1;
	if (!line || fd < 1 || BUFFER_SIZE < 1 || read(fd, buf, 0) == -1)
		return (-1);
	while ((ret = read(fd, buf, BUFFER_SIZE)) > 1 )
	{
		ft_putstr("ret=");
		ft_putnbr(ret);
		buf[ret] = '\0'; /*add a end of string at the end*/
		*line = ft_newstr("",0);
		
		
		counter = 0;
		start = 0;

							ft_putstr("\nALL buf = ");  /////////////
							ft_putstrn(buf,ret);//////////////

		while (buf[counter] != '\0')
		{
/*******************************************************************/
			ft_putstr("\n---------------------------------------------------------------\n");
			ft_putstr("counter = ");
			ft_putnbr(counter);
			
				ft_putstr("\tbuf[");
				ft_putnbr(counter);
				ft_putstr("]=");
			write(1,&buf[counter], 1);
			ft_putstr("\n---------------------------------------------------------------\n");
/************************************************************************/

			if (buf[counter] == '\n' && buf[counter + 1])
			{
				ft_putstr("yes got in\n");
				
				if (!(tmp = ft_newstr( *line, ft_strlen(*line) + counter - start + 1)))// create a tmp for line + buff new line
				   return (-1);
																										ft_putstr(" -- a1 - create space by newstr for tmp-----\n");
				ft_strcpy(tmp, *line, ft_strlen(tmp));  //first copy lines
																										ft_putstr(" -- a2 - copy line to tmp-----\n");
				free(*line); //then free lines
																										ft_putstr(" -- a3 - free line ----\n");

				line = &tmp; // make line the new sized tmp 
																								ft_putstr(" -- a4 - copy tmp to line (now line has more space)----\n");
																											ft_putstr("line [before] =");
																											ft_putnbr(ft_strlen(*line) + counter - start + 1);
																											ft_putstrn(*line,ft_strlen(*line) + counter - start + 1);
																											ft_putstr("\n");

				ft_strcpy(*line, &buf[start], counter);  //now add buff lines
																											ft_putstr(" -- a5 - copy buf to line ----\n");	
																											ft_putstr("&buf[start]=");
																											ft_putstr(&buf[start]);
																											ft_putstr("\n");
																											ft_putstr("line [after] =");
																											ft_putstrn(*line,ft_strlen(*line) + counter - start + 1);
																											ft_putstr("\n");



				if (buf[start + counter + 1] && buf[start + counter + 1] != '\0')
					start = counter + 1;
			}
			counter++;

			if (buf[counter] == '\0')
			{

				ft_putstr("yes got in\n");
				
				if (!(tmp = ft_newstr( *line, ft_strlen(*line) + counter - start + 1)))// create a tmp for line + buff new line
				   return (-1);
																										ft_putstr(" -- b1 - create space by newstr for tmp-----\n");
				ft_strcpy(tmp, *line, ft_strlen(tmp));  //first copy lines
																										ft_putstr(" -- b2 - copy line to tmp-----\n");
				free(*line); //then free lines
																										ft_putstr(" -- b3 - free line ----\n");

				line = &tmp; // make line the new sized tmp 
																								ft_putstr(" -- b4 - copy tmp to line (now line has more space)----\n");
																											ft_putstr("line [before] =");
																											ft_putnbr(ft_strlen(*line) + counter - start + 1);
																											ft_putstrn(*line,ft_strlen(*line) + counter - start + 1);
																											ft_putstr("\n");

				ft_strcpy(*line, &buf[start], counter);  //now add buff lines
																											ft_putstr(" -- b5 - copy buf to line ----\n");	
																											ft_putstr("&buf[start]=");
																											ft_putstr(&buf[start]);
																											ft_putstr("\n");
																											ft_putstr("line [after] =");
																											ft_putstrn(*line,ft_strlen(*line) + counter - start + 1);
																											ft_putstr("\n");
				printf("return (0) - end of doc");		 
				a = 0;
			}
		}
	}
	return (0);
}
