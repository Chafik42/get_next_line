/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmarouf <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/13 02:52:53 by cmarouf           #+#    #+#             */
/*   Updated: 2021/10/14 23:57:04 by cmarouf          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "get_next_line.h"

size_t	get_next_len(char *str)
{
	size_t	i;

	i = 0;
	while (str[i] != '\n' && str[i] != '\0')
		i++;
	return (i);
}

char	*update_memory(char	*lines)
{
	char	*tmp;
	int		i;
	int		j;

	if (lines)
	{
		i = get_next_len(lines);
		if (!lines[i])
		{
			free(lines);
			return (NULL);
		}
		tmp = (char *)malloc(sizeof(char) * (ft_strlen(lines) - i) + 1);
		if (!tmp)
			return (NULL);
		j = i + 1;
		while (lines[++i])
			tmp[i - j] = lines[i];
		tmp[i - j] = '\0';
		free(lines);
		return (tmp);
	}
	return (NULL);
}

static char	*read_file(int fd, char *lines)
{
	int		buffend;
	char	*buffer;

	buffer = (char *)malloc(sizeof(char) * (BUFFER_SIZE + 1));
	if (!buffer)
		return (NULL);
	buffer[0] = '\0';
	buffend = 1;
	if (!ft_strchr(lines, '\n'))
	{
		while (!ft_strchr(buffer, '\n') && buffend > 0)
		{
			buffend = read(fd, buffer, BUFFER_SIZE);
			if (buffend == -1)
			{
				free(lines);
				free(buffer);
				return (NULL);
			}
			buffer[buffend] = '\0';
			lines = ft_strjoin(lines, buffer);
		}
	}
	free(buffer);
	return (lines);
}

char	*get_next_line(int fd)
{
	char			*line;
	static char		*memory = NULL;

	if (fd < 0 || BUFFER_SIZE < 1)
		return (NULL);
	memory = read_file(fd, memory);
	if (!memory)
		return (NULL);
	line = ft_substr(memory);
	memory = update_memory(memory);
	return (line);
}
