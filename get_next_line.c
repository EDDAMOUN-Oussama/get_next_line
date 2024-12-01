/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oeddamou <oeddamou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/26 12:28:46 by oeddamou          #+#    #+#             */
/*   Updated: 2024/12/01 21:39:21 by oeddamou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include <stdio.h>

int	ft_strcpy(char *d, char *s)
{
	int	i;

	i = 0;
	if (s)
	{
		i = 0;
		while (s[i])
		{
			d[i] = s[i];
			if (s[i] == '\n')
			{
				i++;
				break ;
			}
			i++;
		}
	}
	d[i] = '\0';
	return (i);
}

int	ft_substr(char **r)
{
	char	*p;
	int		i;
	int 	s;

	i = ((s = 0), 0);
	while ((*r)[i])
	{
		if ((*r)[i] == '\n')
		{
			i++;
			break ;
		}
		i++;
	}
	while ((*r)[i + s])
		s++;
		if (s == 0)
			return (-1);
	p = malloc(s + 1);
	if (!p)
		return (-1);
	s = i;
	ft_strcpy(p, (*r) + i);
	(*r) = ((free((*r))), p);
	return (s);
}

int	ft_strjoin(char **buf, char *r)
{
	char	*p;
	int		i;
	int		n;

	i = ((n = 0), 0);
	while (r[i])
		if (r[i] != '\n')
			i++;
	else
	{
		i++;
		break ;
	}
	if ((*buf))
		while ((*buf)[n] != '\0')
			n++;
	p = malloc(i + n + 1);
	if (!p)
		return (-1);
	ft_strcpy(p, *buf);
	ft_strcpy(p + n, r);
	*buf = ((free(*buf)), p);
	if (p[n + i - 1] == '\n')
		return (1);
	return (0);
}
char	*ft_read_line(int fd, char **buf)
{
	char	*r;
	int		s;

	r = malloc(BUFFER_SIZE + 1);
	if (!r)
		return (NULL);
	r[BUFFER_SIZE] = '\0';
	s = 0;
	while (!s)
	{
		s = read(fd, r, BUFFER_SIZE);
		if (s == -1 || s == 0)
			break ;
		r[s] = '\0';
		s = ft_strjoin(buf, r);
	}
	if (s == -1)
	{
		free(*buf);
		free(r);
		*buf = NULL;
		r = NULL;
	}
	if (s == 0)
	{
		free(r);
		r = NULL;
		// ft_strjoin(&r, *buf);
		 
	}
	return (r);
}
char	*get_next_line(int fd)
{
	char	*buf;
	static char		*r;
	int			c;

	if (r)
	{
		c = ft_substr(&r);
		if (c == -1)
		{
			free(r);
			r = NULL;
			return (NULL);
		}

	}
	buf = r;
	r = ft_read_line(fd, &buf);
	
	return (buf);
}
