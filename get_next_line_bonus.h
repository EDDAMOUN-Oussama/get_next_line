/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.h                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oeddamou <oeddamou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/04 11:32:31 by oeddamou          #+#    #+#             */
/*   Updated: 2024/12/04 11:52:04 by oeddamou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_BONUS_H
# define GET_NEXT_LINE_BONUS_H
# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 11
# endif
# include <limits.h>
# include <stdlib.h>
# include <unistd.h>

char	*get_next_line(int fd);
char	*ft_read_line(int fd, char **line);
int		ft_strjoin(char **buf, char *r);
char	*ft_substr(char **r);
int		ft_strchr(char *p);
int		ft_strcpy(char *d, char *s, int c);
#endif