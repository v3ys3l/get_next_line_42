/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vbicer <vbicer@student.42kocaeli.com.tr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/03 00:33:06 by vbicer            #+#    #+#             */
/*   Updated: 2024/12/03 10:41:50 by vbicer           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

int	ft_strlen(char *str)
{
	int	i;

	i = 0;
	while (str[i] != '\0')
		i++;
	return (i);
}

int ft_strchr(char *str)
{
	int i;
	i = 0;
	if(!str)
		return(0);
	while (str[i++] == '\n')
		return(1);
	return(0);
}

char *ft_strjoin(char *str1, char *str2)
{
	char *newstr;
	int i;
	int j;
	i = 0;
	j = 0;
	if(!str1)
	{
		str1 = malloc(1);
		str1[0] = '\0';
	}
	if(!str1 || !str2)
		return(0);
	newstr = malloc(sizeof(char) * (ft_strlen(str1) + ft_strlen(str2) + 1));
	if(!newstr)
		return(NULL);
	while (str1[i])
	{
		newstr[i] = str1[i];
		i++;
	}
	while (str2[j])
	{
		newstr[i] = str2[j];
		i++;
		j++;
	}
	newstr[i] = '\0';
	free(str1);
	return(newstr);
}
