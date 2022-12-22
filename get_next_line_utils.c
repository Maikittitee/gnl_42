/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ktunchar <ktunchar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/03 14:49:14 by ktunchar          #+#    #+#             */
/*   Updated: 2022/12/22 21:41:51 by ktunchar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*ft_strchr(const char *s, int c)
{
	int		i;
	char	*str;

	i = 0;
	str = (char *)s;
	while (str[i] != (char)c && str[i])
		i++;
	if (str[i] == (char)c)
		return (str + i);
	if (c == '\0')
		return (str);
	else
		return (NULL);
}

char	*ft_strjoin_free(char *s1, char *s2)
{
	char		*buffer;
	int			i;
	int			j;
	static int	count;

	count++;
	if (!s2)
		return (NULL);
	buffer = malloc((ft_strlen(s1) + ft_strlen(s2) + 1) * sizeof (char));
	if (!buffer)
		return (NULL);
	i = 0;
	j = 0;
	if (s1)
		while (s1[j])
			buffer[i++] = s1[j++];
	j = 0;
	while (s2[j])
	{
		buffer[i++] = s2[j++];
	}
	buffer[i] = '\0';
	if (s1)
		free (s1);
	return (buffer);
}

size_t	ft_strlen(const char *s)
{
	size_t	i;

	i = 0;
	if (!s)
		return (0);
	while (s[i])
		i++;
	return (i);
}

size_t	ft_strlen_nl(const char *s)
{
	size_t	i;

	i = 0;
	if (!s)
		return (0);
	while (s[i] != '\0')
	{
		if (s[i] == '\n')
			return (i);
		i++;
	}
	return (i);
}

char	*ft_strdup_nl(const char *s1)
{
	char	*buffer;
	int		i;

	i = 0;
	buffer = malloc(sizeof(char) * ft_strlen_nl(s1) + 2);
	if (!buffer)
		return (NULL);
	while (s1[i])
	{
		buffer[i] = s1[i];
		if (s1[i] == '\n')
			break ;
		i++;
	}
	i++;
	buffer[i] = '\0';
	return (buffer);
}

char	*ft_strdup(const char *s1)
{
	char	*buffer;
	int		i;

	i = 0;
	buffer = malloc(sizeof(char) * ft_strlen(s1) + 2);
	if (!buffer)
		return (NULL);
	while (s1[i] != '\0')
	{
		buffer[i] = s1[i];
		i++;
	}
	buffer[i] = '\0';
	return (buffer);
}
