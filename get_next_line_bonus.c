/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oeddamou <oeddamou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/26 12:28:46 by oeddamou          #+#    #+#             */
/*   Updated: 2024/12/04 11:30:42 by oeddamou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

char	*get_next_line(int fd)
{
	char		*line;
	char		*t;
	static char	*rest[OPEN_MAX];

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (free(rest[fd]), rest[fd] = NULL, NULL);
	line = rest[fd];
	if (line && line[ft_strchr(line) - 1] == '\n')
	{
		t = NULL;
		if (ft_strjoin(&t, line) == -1)
			return (free(line), rest[fd] = NULL, NULL);
		rest[fd] = ft_substr(&line);
		free(line);
		line = t;
		t = NULL;
		if (ft_strchr(line))
			return (line);
	}
	rest[fd] = ft_read_line(fd, &line);
	if (!rest[fd] && !line)
		return (NULL);
	return (line);
}
