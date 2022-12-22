/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ktunchar <ktunchar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/07 13:08:41 by ktunchar          #+#    #+#             */
/*   Updated: 2022/12/22 22:33:41 by ktunchar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

//TODO >> Check protect

#include "get_next_line_bonus.h"

void	*ft_memset(void *b, int c, size_t len)
{
	size_t			i;
	unsigned char	*str;

	i = 0;
	str = b;
	while (i < len)
	{
		str[i] = c;
		i++;
	}
	return (str);
}

char	*cut_line(char	*str)
{
	int		len_nl;
	int		len;
	char	*temp;

	len_nl = ft_strlen(str, 1);
	len = ft_strlen(str, 0);
	if (len_nl < len - 1)
	{
		temp = str;
		str = ft_strjoin_free(NULL, str + len_nl + 1);
		free(temp);
	}
	else
	{
		free(str);
		return (NULL);
	}
	return (str);
}

char	*get_only_line(char *str)
{
	char	*line;

	if (ft_strchr(str, '\n'))
		line = ft_strdup_nl(str);
	else
		line = ft_strdup(str);
	return (line);
}

char	*read_line(int fd, char *str)
{
	int		can_read;
	char	*buffer;

	can_read = 8000;
	buffer = malloc(sizeof(char) * (BUFFER_SIZE + 1));
	while (can_read)
	{
		ft_memset(buffer, 0, BUFFER_SIZE + 1);
		can_read = read(fd, buffer, BUFFER_SIZE);
		if (can_read <= 0)
			break ;
		str = ft_strjoin_free(str, buffer);
		if (ft_strchr(buffer, '\n'))
			break ;
	}
	free(buffer);
	return (str);
}

char	*get_next_line(int fd)
{
	static char	*str[OPEN_MAX + 3];
	char		*line;

	line = NULL;
	str[fd] = read_line(fd, str[fd]);
	if (str[fd])
	{
		line = get_only_line(str[fd]);
		str[fd] = cut_line(str[fd]);
	}
	return (line);
}
