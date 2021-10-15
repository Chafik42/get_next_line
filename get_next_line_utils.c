/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmarouf <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/10 23:41:04 by cmarouf           #+#    #+#             */
/*   Updated: 2021/10/15 20:24:59 by cmarouf          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "get_next_line.h"

size_t	ft_strlen(const char *str)
{
	size_t	i;

	i = 0;
	if (!str)
		return (0);
	while (str[i])
		i++;
	return (i);
}

char	*ft_strchr(const char *s, int c)
{
	int	i;

	i = 0;
	if (s == NULL)
		return (NULL);
	while (s[i] && s[i] != c)
	{
		if (s[i] == (char)c)
			return ((char *)&s[i]);
		i++;
	}
	if (s[i] == c)
		return ((char *)&s[i]);
	return (NULL);
}

char	*ft_strdup(const char *s)
{
	int			i;
	char		*str;
	char		*dest;

	i = 0;
	str = (char *)s;
	dest = (char *) malloc(sizeof(char) * (ft_strlen(str) + 1));
	while (str[i] != '\0')
	{
		dest[i] = str[i];
		i++;
	}
	dest[i] = '\0';
	return (dest);
}

char	*ft_strjoin(char *s1, char *s2, int size)
{
	char	*dest;
	size_t	i;
	size_t	j;

	i = -1;
	j = -1;
	if (!s1)
	{
		s1 = (char *)malloc(sizeof(char));
		s1[0] = '\0';
	}
	if (!s1 || !s2)
		return (NULL);
	dest = malloc(sizeof(char) * (size) + 1);
	if (!dest)
		return (NULL);
	while (s1[++i])
		dest[i] = s1[i];
	while (s2[++j])
		dest[i + j] = s2[j];
	dest[i + j] = '\0';
	free(s1);
	return (dest);
}

char	*ft_substr(char *s)
{
	char	*dest;
	size_t	i;

	i = -1;
	if (!s[0])
		return (NULL);
	dest = malloc(sizeof(char) * (get_next_len(s)) + 2);
	if (!dest)
		return (NULL);
	while (s[++i] && s[i] != '\n')
		dest[i] = s[i];
	if (s[i] == '\n')
	{
		dest[i] = s[i];
		i++;
	}
	dest[i] = '\0';
	return (dest);
}
