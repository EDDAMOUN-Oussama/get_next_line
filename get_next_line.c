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

#include "get_next_line.h"
#include <stdio.h>

int    ft_strcpy(char *d, char *s, int c)
{
    int    i;

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

char    *ft_substr(char **r)
{
    char    *p;
    int        i;
    int        s;

    i = ((s = 0), 0);
    if (!r)
        return (NULL);
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
        return ((free(*r)), NULL);
    p = malloc(s + 1);
    if (!p)
        return (NULL);
    ft_strcpy(p, (*r) + i, 0);
    return ((free(*r)), p);
}

int    ft_strjoin(char **buf, char *r)
{
    char    *p;
    int        i;
    int        n;

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
    *buf = ((free(*buf)), p);
    if (p[n + i - 1] == '\n')
        return (1);
    return (0);
}

char    *ft_read_line(int fd, char **line)
{
    char    *r;
    int        s;
    int i = 0;
    char *t;

    r = malloc(BUFFER_SIZE + 1);
    if (!r)
    {
        free(*line);
        *line = NULL;
        return (NULL);
    }
    s = 0;
    while (line && *line && (*line)[i])
    {
        if ((*line)[i] == '\n')
        {
            
            t = malloc (BUFFER_SIZE + 1);
            t = NULL;
            ft_strjoin(&t, *line);
            r = ft_substr(line);
            free(*line);
            *line = t;
            return (r);
        }
        i++;
    }

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
        free(r);
        r = *line;
        *line = NULL;
        s = ft_strjoin(line, r);
    }
    if (s == -1 || (s == 0 && !*line))
    {
        free(*line);
        free(r);
        *line = NULL;
        r = NULL;
    }
    return (ft_substr(&r));
}

char    *get_next_line(int fd)
{
    char        *line;
    static char    *rest;

    if (fd < 0 || BUFFER_SIZE <= 0)
        return (free(rest), rest = NULL, NULL);
    line = rest;
    rest = ft_read_line(fd, &line);
    if (!rest && !line)
        return (NULL);
    return (line);
}
