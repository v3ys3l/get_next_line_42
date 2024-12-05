/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils_bonus.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vbicer <vbicer@student.42kocaeli.com.tr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/05 05:04:45 by vbicer            #+#    #+#             */
/*   Updated: 2024/12/05 19:11:30 by vbicer           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

int	ft_strlen(char *str)
{
	int	i;

	i = 0;
	while (str[i] != '\0')
		i++;
	return (i);
}

int	ft_strchr(char *str)
{
	int	i;

	i = -1;
	if (!str)
		return (0);
	while (str[i++] == '\n')
		return (1);
	return (0);
}

char	*ft_strjoin(char *str1, char *str2)
{
	char	*newstr;
	int		i;
	int		j;

	i = -1;
	j = -1;
	if (!str1)
	{
		str1 = malloc(1);
		str1[0] = '\0';
	}
	if (!str1 || !str2)
		return (0);
	newstr = malloc(sizeof(char) * (ft_strlen(str1) + ft_strlen(str2) + 1));
	if (!newstr)
		return (NULL);
	while (str1[++i])
		newstr[i] = str1[i];
	while (str2[++j])
	{
		newstr[i] = str2[j];
		i++;
	}
	newstr[i] = '\0';
	return (free(str1), newstr);
}
