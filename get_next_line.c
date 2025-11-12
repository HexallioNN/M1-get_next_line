/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ikalach <ikalach@student.codam.nl>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/08 14:31:46 by ikalach           #+#    #+#             */
/*   Updated: 2025/11/12 16:51:24 by ikalach          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include <stdio.h>

char	*get_next_line(int fd)
{
	static char	temp[1024];
	static char	*result;
	static int	i = 0;
	static int	counter = 0;
	int			j;

	if (counter == 0)
		if (!(read(fd, temp, BUFFER_SIZE + 1)))
			return (NULL);
	if (counter > 0)
	{
		i++;
	}
	j = i;
	while (1)
	{
		if (temp[i] == '\n' || temp[i] == '\0')
		{
			result = ft_substr(temp, j, i - j + 1);
			counter++;
			return (result);
		}
		i++;
	}
}
