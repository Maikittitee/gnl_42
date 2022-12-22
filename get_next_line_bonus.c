/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ktunchar <ktunchar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/07 13:08:41 by ktunchar          #+#    #+#             */
/*   Updated: 2022/12/18 00:02:53 by ktunchar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

//TODO >> check protect

#include "get_next_line_bonus.h"

char	*cut_line(char	*str)
{
	int	len_nl;
	int	len;
	char	*temp;

	len_nl = ft_strlen_nl(str);
	len = ft_strlen(str);
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

	if (ft_strchr(str,'\n'))
	{
		//printf("what are u doing here bro\n");
		line = ft_strdup_nl(str);
	}
	else 
		line = ft_strdup(str);

	return (line);
}

char *read_line(int	fd, char *str)
{
	int	can_read;
	char	*buffer;

	can_read = 8000;
	buffer = malloc(sizeof(char) * (BUFFER_SIZE + 1));
	while (can_read)
	{
		ft_bzero(buffer, BUFFER_SIZE + 1);
		can_read = read(fd, buffer, BUFFER_SIZE);
		if (can_read <= 0)
			break;
		//printf("===%d===",can_read);
		str = ft_strjoin_free(str, buffer);
		//printf("===%s===\n",str);
	

		if (ft_strchr(buffer, '\n'))
			break;
		
	}
	//printf("===%s===\n",str);
	free(buffer);
	return (str);
}

char *get_next_line(int fd)
{
    static char *str[OPEN_MAX];
	char *line;
	//int	len;
	//int	len_nl;

	line = NULL;
	str[fd] = read_line(fd, str[fd]);
	if (str[fd])
	{
		line = get_only_line(str[fd]);
		str[fd] = cut_line(str[fd]);
	}
	return (line);

}

// int	main()
// {
// 	int	fd;

// //	char *a = "012345\nab";

// 	fd = open("gnlTester/files/41_no_nl",O_RDONLY);

// 	//printf("strlen_nl = %zu\n",ft_strlen_nl(a));
// 	//printf("strlen = %zu\n",ft_strlen(a));
// 	printf("line 1:%s|",get_next_line(fd));
// 	// printf("line 2:%s|",get_next_line(fd));
// 	// printf("line 3 : %s",get_next_line(fd));
// 	// printf("line 4 : %s",get_next_line(fd));
// }
