/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpazouki <mpazouki@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/26 01:23:18 by mpazouki          #+#    #+#             */
/*   Updated: 2025/03/03 22:52:06 by mpazouki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>
#include <stdio.h>

#ifndef BUFFER_SIZE
# define BUFFER_SIZE 5
#endif

char	*ft_strdup(char *src)
{
	int		i;
	char	*dest;

	i = 0;
	while (src[i])
		i++;
	dest = (char *)malloc(sizeof(char) * (i + 1));
	if (!dest)
		return (NULL);
	i = 0;
	while (src[i])
	{
		dest[i] = src[i];
		i++;
	}
	dest[i] = '\0';
	return (dest);
}

char	*get_next_line(int fd)
{
	static char	buffer[BUFFER_SIZE];
	static int	buffer_read = 0;
	static int	buffer_index = 0;
	char		*line;
	int			line_index = 0;
	
	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	
	line = (char *)malloc(70000);
	if (!line)
		return (NULL);
	
	while (1)
	{
		if (buffer_index >= buffer_read)
		{
			buffer_read = read(fd, buffer, BUFFER_SIZE);
			buffer_index = 0;
			if (buffer_read <= 0)
				break ;
		}
		line[line_index++] = buffer[buffer_index++];
		if (line_index > 0 && line[line_index - 1] == '\n')
			break ;
	}
	line[line_index] = '\0';
	if (line_index == 0)
	{
		free(line);
		return (NULL);
	}
	char *temp = ft_strdup(line);
	if (!temp) // Ensure strdup didn't fail
	{
    	free(line);
    	return NULL;
	}
	free(line);
	return temp;
}

int	main()
{
	int		fd;
	char	*line;

	fd = open("test.txt", O_RDONLY);
	while ((line = get_next_line(fd)) != NULL)
	{
		printf("%s", line);
		free(line);
	}
	close(fd);
	return (0);
}

// gcc get_next_line.c -o gnl
//valgrind --leak-check=full ./gnl
