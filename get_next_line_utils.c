/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maambuhl <marcambuehl4@gmail.com>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/09 15:35:48 by maambuhl          #+#    #+#             */
/*   Updated: 2024/10/12 01:22:41 by maambuhl         ###   LAUSANNE.ch       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*ft_getrest(char *s)
{
	size_t	i;
	size_t	j;
	char	*rest;

	i = 0;
	while (s[i] && s[i] != '\n')
		i++;
	// if (s[i] != '\n')
	// {
	// 	rest = ft_dup(s);
	// 	if (!rest)
	// 		return (0);
	// 	return (rest);
	// }
	if (!s[i])
		return (0);
	if (!s[i + 1])
		return (0);
	rest = malloc(sizeof(char) * (ft_strlen(s) - i));
	if (!rest)
		return (0);
	j = 0;
	++i;
	while (s[i])
		rest[j++] = s[i++];
	rest[j] = 0;
	return (rest);
}

size_t	ft_strlen(char *s)
{
	size_t	i;

	i = 0;
	while (s[i])
		i++;
	return (i);
}

char	*ft_calloc_char(size_t size)
{
	char	*ptr;
	size_t	i;

	ptr = malloc(size);
	if (!ptr)
		return (0);
	i = 0;
	while (i < size)
		ptr[i++] = 0;
	return (ptr);
}

// char	*ft_getline(char *s, ssize_t r)
// {
// 	int		i;
// 	char	*line;
//
// 	i = 0;
// 	if (r == 0 && !ft_slineret(s))
// 	{
// 		line = ft_dup(s);
// 		if (!line)
// 			return (0);
// 		return (line);
// 	}
// 	while (s[i] != '\n' && s[i])
// 		i++;
// 	if (s[i] != '\n')
// 		return (0);
// 	line = malloc(sizeof(char) * (i + 2));
// 	if (!line)
// 		return (0);
// 	i = 0;
// 	while (s[i] != '\n')
// 	{
// 		line[i] = s[i];
// 		i++;
// 	}
// 	line[i++] = '\n';
// 	line[i] = 0;
// 	return (line);
// }

char	*ft_conca(char *dst, char *src)
{
	size_t	j;
	size_t	i;
	char	*conca;

	conca = malloc(sizeof(char) * (ft_strlen(src) + ft_strlen(dst) + 1));
	if (!conca)
		return (0);
	i = 0;
	while (dst[i])
	{
		conca[i] = dst[i];
		i++;
	}
	j = 0;
	while (src[j])
		conca[i++] = src[j++];
	conca[i] = 0;
	free(dst);
	return (conca);
}

char	*ft_getline(char *s)
{
	size_t	i;
	size_t	j;
	char	*line;

	i = 0;
	while (s[i] && s[i] != '\n')
		i++;
	if (s[i] == '\n')
		i++;
	line = malloc(sizeof(char) * (i + 1));
	if (!line)
		return (0);
	j = 0;
	while (j < i)
	{
		line[j] = s[j];
		j++;
	}
	line[j] = 0;
	return (line);
}


