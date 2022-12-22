/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ktunchar <ktunchar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/10 23:01:16 by ktunchar          #+#    #+#             */
/*   Updated: 2022/12/07 15:01:21 by ktunchar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef	GET_NEXT_LINE_H
#define GET_NEXT_LINE_H

#include <stdio.h>
#include <fcntl.h>
#include <string.h>
#include <unistd.h>
#include <stddef.h>
#include <stdlib.h>

#ifndef BUFFER_SIZE
#define BUFFER_SIZE 1
#endif

char	*ft_strchr(const char *s, int c);
char    *get_next_line(int fd);
char	*ft_strjoin_free(char *s1, char *s2);
size_t	ft_strlen(const char *s);
size_t	ft_strlen_nl(const char *s);
void	ft_bzero(void *s, size_t n);
void	*ft_memset(void *b, int c, size_t len);
void	ft_buffercpy(char *dst, const char *src);
char	*ft_strdup_nl(const char *s1);
char	*ft_strdup(const char *s1);




#endif