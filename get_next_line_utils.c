
#include "get_next_line.h"
#include <stdio.h>

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
	int 	s;

	i = ((s = 0), 0);
	if (!r) return (NULL);
	while ((*r) && (*r)[i])
	{
		if ((*r)[i] == '\n')
		{
			i++;
			break ;
		}
		i++;
	}
	while ((*r) && (*r)[i + s])
		s++;
		if (!(*r) || s == 0)
			{
				if (*r)
				(free(*r));
				return ( NULL);
			}
	p = malloc(s + 1);
	if (!p)
		return (NULL);
	ft_strcpy(p, (*r) + i, 0);
	if (*r)
	free((*r));
	return (p);
}

int	ft_strjoin(char **buf, char *r)
{
	char	*p;
	int		i;
	int		n;

	i = ((n = 0), 0);
	if (!r)
		return (-1);
	while (r[i])
		if (r[i] != '\n')
			i++;
	else
	{
		i++;
		break ;
	}
	if (buf && (*buf))
		while ((*buf)[n] != '\0')
			n++;
	p = malloc(i + n + 1);
	if (!p)
		return (-1);
	ft_strcpy(p, *buf, 0);
	ft_strcpy(p + n, r, 1);
	if (*buf)
	(free(*buf));
	*buf = ( p);
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
		{
			// if (*buf)
			free(*buf);
			*buf = NULL;
			return ( NULL);
		}
	// r[BUFFER_SIZE] = '\0';
	s = 0;
	while (!s)
	{
		s = read(fd, r, BUFFER_SIZE);
		if (s == -1 || s == 0 )
			break ;
		r[s] = '\0';
		s = ft_strjoin(buf, r);
		
	}
	if (s == 0)
	{
		// if (r)
		free(r);
		r = *buf;
		*buf = NULL;
		s = ft_strjoin(buf, r);
		// printf("$$buf$$\n%s\n>>>>\n%s\n$$res$$",*buf,r);
	}
	if (s == -1)
	{
		if (*buf)
		free(*buf);
		if (r)
		free(r);
		*buf = NULL;
		r = NULL;
	}
	return (ft_substr(&r));
}

char	*get_next_line(int fd)
{
	char	*buf;
	// char	*t;
	static char		*r;
	// printf("!!!!!!%s!!!!", r);
	buf = NULL;
	if (r)
	{	
	// printf("!!!!!!1====>%s!!!!\n", r);
		buf = r;

	}
	r  = ft_read_line(fd, &buf);
	// printf("\n!!!!!!=====>2%s!!!!\n", r);
	
	return (buf);
}
