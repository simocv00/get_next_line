/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: melayyad <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/02 09:28:21 by melayyad          #+#    #+#             */
/*   Updated: 2024/12/02 09:28:27 by melayyad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"
#include <limits.h>

static char	*ft_new_line_detector(char *str)
{
	char	*newline;

	if (!str)
		return (NULL);
	newline = ft_strchr(str, '\n');
	if (newline)
		return (ft_strdup(newline + 1));
	return (NULL);
}

static char	*get_line(char *buffers[1024], int fd)
{
	char	*here;
	char	*temp;

	if (!buffers[fd] || buffers[fd][0] == '\0')
	{
		free(buffers[fd]);
		buffers[fd] = NULL;
		return (NULL);
	}
	here = ft_strcpy(buffers[fd], '\n');
	temp = ft_new_line_detector(buffers[fd]);
	free(buffers[fd]);
	buffers[fd] = temp;
	return (here);
}

char	*get_next_line(int fd)
{
	static char	*buffers[1024];
	char		*temp_buffer;
	int			bytes_read;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	temp_buffer = malloc((BUFFER_SIZE + 1) * sizeof(char));
	if (!temp_buffer)
		return (NULL);
	if (!buffers[fd])
		buffers[fd] = ft_strdup("");
	while (!ft_strchr(buffers[fd], '\n'))
	{
		bytes_read = read(fd, temp_buffer, BUFFER_SIZE);
		if (bytes_read < 0)
			return (free(temp_buffer), NULL);
		if (bytes_read == 0)
			break ;
		temp_buffer[bytes_read] = '\0';
		buffers[fd] = ft_strjoin(buffers[fd], temp_buffer);
	}
	free(temp_buffer);
	return (get_line(buffers, fd));
}
