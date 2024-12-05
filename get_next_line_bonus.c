/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vbicer <vbicer@student.42kocaeli.com.tr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/05 05:06:34 by vbicer            #+#    #+#             */
/*   Updated: 2024/12/05 21:16:36 by vbicer           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

static char	*ft_read_file(int fd, char *str)
{
	char	*tmp;
	int		size;

	size = 1;
	tmp = malloc(sizeof(char) * (BUFFER_SIZE + 1));
	if (!tmp)
		return (NULL);
	while (!ft_strchr(str) && size != 0)
	{
		size = read(fd, tmp, BUFFER_SIZE);
		if (size == -1)
		{
			free(tmp);
			return (NULL);
		}
		tmp[size] = '\0';
		str = ft_strjoin(str, tmp);
	}
	free(tmp);
	return (str);
}

static char	*ft_get_line(char *str)
{
	char	*newline;
	int		i;

	i = 0;
	if (!str || str[0] == '\0')
		return (NULL);
	while (str[i] && str[i] != '\n')
		i++;
	newline = malloc(sizeof(char) * (i + 2));
	if (!newline)
		return (NULL);
	i = 0;
	while (str[i] && str[i] != '\n')
	{
		newline[i] = str[i];
		i++;
	}
	if (str[i] == '\n')
	{
		newline[i] = '\n';
		i++;
	}
	newline[i] = '\0';
	return (newline);
}

static char	*ft_next_line(char *str)
{
	char	*nextline;
	int		i;
	int		j;

	j = 0;
	i = 0;
	while (str[i] && str[i] != '\n')
		i++;
	if (!str[i])
	{
		free(str);
		return (NULL);
	}
	nextline = malloc(sizeof(char) * (ft_strlen(str) - i + 1));
	if (!nextline)
		return (NULL);
	i++;
	while (str[i])
	{
		nextline[j] = str[i];
		i++;
		j++;
	}
	nextline[j] = '\0';
	return (free(str), nextline);
}

char	*get_next_line(int fd)
{
	char		*line;
	static char	*str[4096];

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	str[fd] = ft_read_file(fd, str[fd]);
	if (!str[fd])
		return (NULL);
	line = ft_get_line(str[fd]);
	str[fd] = ft_next_line(str[fd]);
	return (line);
}
