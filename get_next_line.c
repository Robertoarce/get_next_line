/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: roberto <rarce@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/08 18:08:45 by roberto           #+#    #+#             */
/*   Updated: 2020/06/26 18:36:29 by roberto          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

int	ft_fillstock(char *buf, char **stock)
{
	char *tmp;

	if (!*stock)
	{
		if (!(*stock = ft_strnew(0)))
			return (-1);
	}
	if (!(tmp = ft_strnew(ft_strlen(buf) + ft_strlen(*stock))))
		return (-1);
	tmp = ft_strncpy(tmp, *stock, -1);
	tmp = ft_strncpy(tmp, buf, -1);
	free(*stock);
	*stock = tmp;
	return (1);
}

int	ft_isnewline(char **line, char **stock, int cut)
{
	char *tmp;

	if (!(*line = ft_strnew(cut)))
		return (-1);
	*line = ft_strncpy(*line, *stock, cut);
	if (!(tmp = ft_strnew(ft_strlen(&(*stock)[cut + 1]))))
		return (-1);
	tmp = ft_strncpy(tmp, &(*stock)[cut + 1], -1);
	free(*stock);
	*stock = tmp;
	return (1);
}

int	get_next_line(int fd, char **line)
{
	static char	*fd_stock[32];
	char		buf[BUFFER_SIZE + 1];
	int			read_size;
	int			cut;

	if (!line || fd < 0 || BUFFER_SIZE < 1 || read(fd, buf, 0) < 0)
		return (-1);
	while ((read_size = read(fd, buf, BUFFER_SIZE)) > 0)
	{
		buf[read_size] = '\0';
		if (ft_fillstock(buf, &fd_stock[fd]) == -1)
			return (-1);
		if (ft_findnl(fd_stock[fd]) > -1)
			break ;
	}
	cut = ft_findnl(fd_stock[fd]);
	if (cut > -1)
		return (ft_isnewline(&*line, &fd_stock[fd], cut));
	if (!(*line = ft_strnew(ft_strlen(fd_stock[fd]) + 1)))
		return (-1);
	*line = ft_strncpy(*line, fd_stock[fd], -1);
	return (0);
}
