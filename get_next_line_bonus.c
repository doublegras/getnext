/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maambuhl <marcambuehl4@gmail.com>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/08 15:54:37 by maambuhl          #+#    #+#             */
/*   Updated: 2024/10/22 10:55:37 by maambuhl         ###   LAUSANNE.ch       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"
#include <stdio.h>

int	ft_slineret(char *s)
{
	size_t	i;

	i = 0;
	while (s[i])
	{
		if (s[i] == '\n')
			return (1);
		i++;
	}
	return (0);
}

char	*ft_freer(void *ptr1, void *ptr2)
{
	free(ptr1);
	free(ptr2);
	return (0);
}

char	*read_file(int fd, char *conca)
{
	char	*buff;
	ssize_t	r;

	buff = ft_calloc_char(BUFFER_SIZE + 1);
	if (!buff)
		return (ft_freer(conca, 0));
	if (!conca)
		conca = ft_calloc_char(1);
	if (read(fd, buff, 0) < 0)
		return (ft_freer(conca, buff));
	r = 1;
	while (r)
	{
		r = read(fd, buff, BUFFER_SIZE);
		if (r == -1)
			return (ft_freer(conca, buff));
		buff[r] = 0;
		conca = ft_conca(conca, buff);
		if (ft_slineret(conca))
			r = 0;
	}
	free(buff);
	return (conca);
}

char	*get_next_line(int fd)
{
	static char	*conca[FD_NB];
	char		*line;
	char		*rest;

	if (fd < 0)
		return (0);
	conca[fd] = read_file(fd, conca[fd]);
	if (!conca[fd])
		return (0);
	line = ft_getline(conca[fd]);
	if (!line)
		return (ft_freer(conca[fd], 0));
	rest = ft_getrest(conca[fd]);
	free(conca[fd]);
	conca[fd] = rest;
	if (!*line)
		return (ft_freer(rest, line));
	return (line);
}

// int	main(void)
// {
// 	int		fd;
// 	char	*str;
//
// 	fd = open("", O_RDONLY);
// 	// fd = -3;
//
// 	// str = get_next_line(fd);
// 	// printf("%s", str);
// 	// free(str);
// 	//
// 	// str = get_next_line(fd);
// 	// printf("%s", str);
// 	// free(str);
// 	//
// 	// str = get_next_line(fd);
// 	// printf("%s", str);
// 	// free(str);
// 	//
// 	// str = get_next_line(fd);
// 	// printf("%s", str);
// 	// free(str);
// 	//
// 	// str = get_next_line(fd);
// 	// printf("%s", str);
// 	// free(str);
// 	//
// 	// str = get_next_line(fd);
// 	// printf("%s", str);
// 	// free(str);
// 	printf("%s", get_next_line(fd));
// 	printf("%s", get_next_line(fd));
// 	printf("%s", get_next_line(fd));
// 	printf("%s", get_next_line(fd));
// 	printf("%s", get_next_line(fd));
// 	printf("%s", get_next_line(fd));
// 	printf("%s", get_next_line(fd));
// 	printf("%s", get_next_line(fd));
// 	printf("%s", get_next_line(fd));
// 	printf("%s", get_next_line(fd));
// 	printf("%s", get_next_line(fd));
// 	return (0);
// }
