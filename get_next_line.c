/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oeddamou <oeddamou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/26 12:28:46 by oeddamou          #+#    #+#             */
/*   Updated: 2024/11/26 17:46:24 by oeddamou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

int ft_substr(char *buf, int s, char **p)
{
    int i;
    int c;

    i = 0;
    c = 0;
    while (i < s)
    {
        if (buf[i] == '\n')
            {
                c = 1;
                break;
            }
        i++;
    }
    (*p) = malloc (i + 1);
    if (!(*p))
        return (-1);
    (*p)[i + 1] = '\0';
    while (i >= 0)
    {
        (*p)[i] = buf[i];
        i--;
    }
    return (c);
}
int ft_strjoin(char **r, char *buf, int s)
{
    char    *p;
    int j;
    int k;

    j = 0;
    while ((*r)[j++]);
    if (!p)
    return ((free(*r), -1));
    while (k < j)
        {
            p[k] = (*r)[k];
            k++;
        }
        k = 0;
    p[k] = '\0';
    free (*r);
    *r = p;
    if (p[k - 1] = '\n')
        return (1);
    return (0);
}
char    *get_next_line(int fd)
{
    char buf[BUFFER_SIZE];
    char    *r;
    int i;

    r = NULL;
    i = read(fd, buf, BUFFER_SIZE);
    if (i <= 0)
        return (NULL);
    while (i > 0)
    {
        ft_substr(buf, i, &r);
    }
    
}
