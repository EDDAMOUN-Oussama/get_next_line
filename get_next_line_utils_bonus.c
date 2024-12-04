/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils_bonus.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oeddamou <oeddamou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/04 11:23:39 by oeddamou          #+#    #+#             */
/*   Updated: 2024/12/04 18:12:52 by oeddamou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

int	ft_strchr(char *p)
{
	int	i;

	i = 0;
	if (p)
	{
		while (p[i])
		{
			if (p[i] == '\n')
				return (i + 1);
			i++;
		}
		return (i);
	}
	return (-1);
}

int	ft_strcpy(char *d, char *s, int c)
{
	int	i;

	i = 0;
	if (s)
	{
		i = 0;
		while (s[i])
		{
			d[i] = s[i];
			if (c == 1 && s[i] == '\n')
			{
				i++;
				break ;
			}
			i++;
		}
		d[i] = '\0';
	}
	return (i);
}

char	*ft_substr(char **r)
{
	char	*p;
	int		i;
	int		s;

	if (!r || !(*r))
		return (NULL);
	i = ((s = 0), ft_strchr(*r));
	while ((*r)[i + s])
		s++;
	if (s == 0)
		return ((free(*r)), *r = NULL, NULL);
	p = malloc(s + 1);
	if (!p)
		return (free(*r), (*r) = NULL, NULL);
	ft_strcpy(p, (*r) + i, 0);
	return (free(*r), *r = NULL, p);
}

int	ft_strjoin(char **buf, char *r)
{
	char	*p;
	int		i;
	int		n;

	if (!r)
		return (-1);
	i = ((n = 0), ft_strchr(r));
	if (buf && (*buf))
		while ((*buf)[n] != '\0')
			n++;
	p = malloc(i + n + 1);
	if (!p)
		return (-1);
	ft_strcpy(p, *buf, 0);
	ft_strcpy(p + n, r, 1);
	*buf = ((free(*buf)), p);
	if (p[n + i - 1] == '\n')
		return (1);
	return (0);
}

char	*ft_read_line(int fd, char **line)
{
	char	*r;
	int		s;

	r = ((s = 0), malloc(BUFFER_SIZE + 1));
	if (!r)
		return ((free(*line)), (*line = NULL), NULL);
	while (!s)
	{
		s = read(fd, r, BUFFER_SIZE);
		if (s == -1 || s == 0)
			break ;
		r[s] = '\0';
		s = ft_strjoin(line, r);
	}
	if (s == 0 && line && *line)
	{
		r = ((free(r)), *line);
		s = ((*line = NULL), ft_strjoin(line, r));
	}
	if (s == -1 || (s == 0 && !*line))
	{
		*line = ((free(*line)), NULL);
		r = ((free(r)), NULL);
	}
	return (ft_substr(&r));
}
