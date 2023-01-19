/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kinaz <42istanbul.com.tr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/05 17:26:26 by kinaz             #+#    #+#             */
/*   Updated: 2022/12/05 17:57:46 by kinaz            ###   ########.tr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*ft_read_buff(int fd, char *str)
{
	int		rd;
	char	*buff;

	buff = malloc(sizeof(char) * BUFFER_SIZE + 1);
	if (!buff)
		return (NULL);
	rd = 1;
	while (!ft_strchr(str, '\n') && rd != 0)
	{
		rd = read(fd, buff, BUFFER_SIZE);
		if (rd == -1)
		{
			free(str);
			free(buff);
			return (NULL);
		}
		buff[rd] = '\0';
		str = ft_strjoin1(str, buff);
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
	str = ft_read_buff(fd, str);
	if (!str)
		return (NULL);
	line = ft_line(str);
	str = ft_str(str);
	return (line);
}
