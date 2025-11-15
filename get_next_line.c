/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ikalach <ikalach@student.codam.nl>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/08 14:31:46 by ikalach           #+#    #+#             */
/*   Updated: 2025/11/15 15:44:28 by ikalach          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include <stdio.h>

static char	*fill_buffer(int fd, char *buffer)
{
	char	temp[BUFFER_SIZE + 1];
	char	*tmp;
	int		bytes_read;

	bytes_read = 1;
	if (!buffer)
		buffer = ft_strdup("");
	while (!ft_strchr(buffer, '\n') && bytes_read != 0)
	{
		bytes_read = read(fd, temp, BUFFER_SIZE);
		if (bytes_read == -1)
		{
			free(buffer);
			return (NULL);
		}
		temp[bytes_read] = '\0';
		tmp = buffer;
		buffer = ft_strjoin(buffer, temp);
		free(tmp);
	}
	return (buffer);
}

static char	*get_line(char *buffer)
{
	int		i;
	char	*line;
	int		is_newline;

	i = 0;
	if (!buffer || !*buffer)
		return (NULL);
	while (buffer[i] && buffer[i] != '\n')
		i++;
	if (buffer[i] == '\n')
		is_newline = 1;
	else
		is_newline = 0;
	line = ft_substr(buffer, 0, i + is_newline);
	return (line);
}

static char	*create_new_buffer(char *buffer)
{
	char	*new_buffer;
	int		i;

	i = 0;
	while (buffer[i] && buffer[i] != '\n')
		i++;
	if (!buffer[i])
	{
		free(buffer);
		return (NULL);
	}
	new_buffer = ft_strdup(buffer + i + 1);
	free(buffer);
	return (new_buffer);
}

char	*get_next_line(int fd)
{
	static char	*buffer;
	char		*result;

	if (BUFFER_SIZE > 8380000)
		return (NULL);
	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	buffer = fill_buffer(fd, buffer);
	if (!buffer)
		return (NULL);
	result = get_line(buffer);
	buffer = create_new_buffer(buffer);
	return (result);
}

// int	main(void)
// {
// 	int	fd;

// 	fd = open("test.txt", O_RDONLY);
// 	printf("%s", get_next_line(fd));
// 	printf("%s", get_next_line(fd));
// 	printf("%s", get_next_line(fd));
// 	printf("%s", get_next_line(fd));
// }
