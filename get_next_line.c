/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chrihorc <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/09 18:32:34 by chrihorc          #+#    #+#             */
/*   Updated: 2017/03/09 19:11:44 by chrihorc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft/libft.h"

int		get_line(const int fd, char **str)
{
	char	*buff;
	int		nx;

	buff = (char *)malloc(2);
	while ((nx = read(fd, buff, 1)) > 0)
	{
		if (buff[0] == '\n')
			break ;
		buff[1] = '\0';
		if (buff && !*str)
			*str = ft_strdup(buff);
		else
			*str = ft_strjoin(*str, buff);
	}
	free(buff);
	if (nx == 0 && *str[0])
		nx = 1;
	return (nx);
}

int		get_next_line(const int fd, char **line)
{
	static int		x;

	if (fd < 0 || !line)
		return (-1);
	*line = (char*)malloc(1);
	*line[0] = '\0';
	if ((x = get_line(fd, line)) < 1)
		return (x);
	return (1);
}
