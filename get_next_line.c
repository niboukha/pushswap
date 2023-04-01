/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: niboukha <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/07 15:08:05 by niboukha          #+#    #+#             */
/*   Updated: 2022/11/14 09:39:56 by niboukha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

static char	*ft_read_line(int fd, char *str)
{
	char	*buffer;
	int		r_b;

	buffer = malloc(BUFFER_SIZE + 1);
	if (!buffer)
		return (NULL);
	r_b = 1;
	while (!ft_strchr(str, '\n'))
	{
		r_b = read (fd, buffer, BUFFER_SIZE);
		if (r_b == -1)
			return (free(buffer), free(str), NULL);
		if (r_b == 0)
		{
			free(buffer);
			if (str && !*str)
				return (free(str), NULL);
			return (str);
		}
		buffer[r_b] = '\0';
		str = ft_strjoin(str, buffer);
	}
	free(buffer);
	return (str);
}

static char	*ft_get_line(char *str)
{
	char	*buffer;
	int		len;

	len = 0;
	while (str[len] && str[len] != '\n')
		len++;
	buffer = malloc (len + 2);
	if (!buffer)
		return (NULL);
	len = 0;
	while (str[len] && str[len] != '\n')
	{
		buffer[len] = str[len];
		len++;
	}
	if (str[len] == '\n')
	{
		buffer[len] = str[len];
		len++;
	}
	buffer[len] = '\0';
	return (buffer);
}

static char	*ft_next_line(char *str)
{
	char	*buffer;
	int		i;
	int		j;

	i = 0;
	if (!str)
	{
		free(str);
		return (NULL);
	}
	while (str[i] && str[i] != '\n')
		i++;
	buffer = malloc(ft_strlen(str) - i);
	if (!buffer)
		return (NULL);
	j = 0;
	if (str[i])
		i++;
	while (str[i])
		buffer[j++] = str[i++];
	buffer[j] = '\0';
	free(str);
	return (buffer);
}

char	*get_next_line(int fd)
{
	char		*line;
	static char	*str;

	if (fd < 0 || fd > 10240 || BUFFER_SIZE <= 0)
		return (0);
	str = ft_read_line(fd, str);
	if (!str)
		return (NULL);
	line = ft_get_line(str);
	str = ft_next_line(str);
	return (line);
}
