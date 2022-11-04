/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vrsargsy <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/15 16:21:29 by vrsargsy          #+#    #+#             */
/*   Updated: 2022/04/28 18:16:28 by vrsargsy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*ft_read_tls(int fd, char *str)
{
	char	*buff;
	int		read_cnt;

	buff = malloc((BUFFER_SIZE + 1) * sizeof(char));
	if (!buff)
		return (NULL);
	read_cnt = 1;
	while (!ft_strchr(str, '\n') && read_cnt != 0)
	{
		read_cnt = read(fd, buff, BUFFER_SIZE);
		if (read_cnt == -1)
		{
			free(buff);
			return (NULL);
		}
		buff[read_cnt] = '\0';
		str = ft_strjoin(str, buff);
	}
	free(buff);
	return (str);
}

char	*get_next_line(int fd)
{
	char		*line;
	static char	*str;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (0);
	str = ft_read_tls(fd, str);
	if (!str)
		return (NULL);
	line = ft_get_line(str);
	str = ft_new_ls(str);
	return (line);
}
