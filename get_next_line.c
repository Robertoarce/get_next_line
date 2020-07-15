/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: roberto <rarce@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/08 18:08:45 by roberto           #+#    #+#             */
/*   Updated: 2020/07/15 11:27:09 by titorium         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

int	ft_fillstock(char *buf, char **stock)
{
	char *tmp;

	if (!*stock)
	{
		if (!(*stock = ft_strnew(0)))
			return (1);
	}
	if (!(tmp = ft_strnew(ft_strlen(buf) + ft_strlen(*stock))))
		return (-1);
	tmp = ft_strncpy(tmp, *stock, -1);
	tmp = ft_strncpy(tmp, buf, -1);
	free(*stock);
	*stock = tmp;
	return (1);
}

int	ft_nl(char **line, char **stock, int cut, int end)
{
	char	*tmp;

	if (!(*line = ft_strnew(cut)))
		return (-1);
	*line = ft_strncpy(*line, *stock, cut);
	if (!(tmp = ft_strnew(ft_strlen(&(*stock)[cut + 1]))))
		return (-1);
	tmp = ft_strncpy(tmp, &(*stock)[cut + 1], -1);
	free(*stock);
	*stock = tmp;
	return (end);
}

int	ft_nl2(char **line, char **stock, int cut, int end)
{
	if (!(*line = ft_strnew(cut)))
		return (-1);
	*line = ft_strncpy(*line, *stock, cut);
	free(*stock);
	*stock = NULL;
	return (end);
}

int	get_next_line(int fd, char **line)
{
	static char	*fd_stock[64];
	char		buf[BUFFER_SIZE + 1];
	int			read_size;

	if (!(*line = NULL) && (BUFFER_SIZE < 1 || read(fd, buf, 0)))
		return (-1);
	while (1)
	{
		if (ft_findnl(fd_stock[fd]) > -1)
			return (ft_nl(&*line, &fd_stock[fd], ft_findnl(fd_stock[fd]), 1));
		if ((read_size = read(fd, buf, BUFFER_SIZE)) <= 0)
			break ;
		buf[read_size] = '\0';
		if (ft_fillstock(buf, &fd_stock[fd]) == FAILURE)
			return (FAILURE);
	}
	if (read_size == -1)
		return (-1);
	if (ft_findnl(fd_stock[fd]) >= 0)
		return (ft_nl(&*line, &fd_stock[fd], ft_findnl(fd_stock[fd]), 1));
	if (fd_stock[fd])
		return (ft_nl2(&*line, &fd_stock[fd], ft_strlen(fd_stock[fd]), 0));
	return (ft_nl2(&*line, &fd_stock[fd], 0, 0));
}
