/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ikalach <ikalach@student.codam.nl>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/08 14:31:46 by ikalach           #+#    #+#             */
/*   Updated: 2025/11/12 15:12:45 by ikalach          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*get_next_line(int fd)
{
	char	temp[1024];
	char	*result;
	int		i;

	i = 0;
	if (!(read(fd, temp, sizeof(temp))))
		return (NULL);
	read(fd, temp, sizeof(temp));
	while (1)
	{
		if (temp[i] == '\n' || temp[i] == '\0')
		{
			result = ft_strdup(temp, i);
			break ;
		}
		i++;
	}
	return (result);
}
