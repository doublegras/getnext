/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maambuhl <marcambuehl4@gmail.com>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/08 15:54:37 by maambuhl          #+#    #+#             */
/*   Updated: 2024/10/11 15:05:10 by maambuhl         ###   LAUSANNE.ch       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include <stdio.h>
#include <strings.h>

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

char	*ft_dup(char *s)
{
	char	*new;
	size_t	i;

	new = malloc(sizeof(char) * (ft_strlen(s) + 1));
	if (!new)
		return (0);
	i = 0;
	while (s[i])
	{
		new[i] = s[i];
		i++;
	}
	new[i] = 0;
	return (new);
}

char	*read_file(int fd, char *conca)
{
	char	*buff;
	ssize_t	r;

	buff = ft_calloc_char(BUFFER_SIZE + 1);
	if (!buff)
		return (0);
	if (!conca)
		conca = ft_calloc_char(1);
	r = 1;
	while (r)
	{
		r = read(fd, buff, BUFFER_SIZE);
		if (r == -1)
		{
			free(buff);
			return (0);
		}
		conca = ft_conca(conca, buff);
		if (ft_slineret(conca))
			r = 0;
	}
	free(buff);
	return (conca);
}

char	*get_next_line(int fd)
{
	static char	*conca;

	conca = read_file(fd, conca);
	
}

int	main(void)
{
	int		fd;
	/*char	*str;*/

	fd = open("/Users/maambuhl//francinette/tests/get_next_line/fsoares/1char.txt", O_RDONLY);

	/*str = get_next_line(fd);*/
	/*printf("%s", str);*/
	/*free(str);*/
	printf("%s", get_next_line(fd));
	printf("%s", get_next_line(fd));
	// printf("%s", get_next_line(fd));
	// printf("%s", get_next_line(fd));
	// printf("%s", get_next_line(fd));
	// printf("%s", get_next_line(fd));
	// printf("%s", get_next_line(fd));
	// printf("%s", get_next_line(fd));
	// printf("%s", get_next_line(fd));
	// printf("%s", get_next_line(fd));
	return (0);
}
