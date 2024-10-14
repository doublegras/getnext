/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.h                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maambuhl <marcambuehl4@gmail.com>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/14 11:10:09 by maambuhl          #+#    #+#             */
/*   Updated: 2024/10/14 11:10:14 by maambuhl         ###   LAUSANNE.ch       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_BONUS_H
# define GET_NEXT_LINE_BONUS_H
# include <unistd.h>
# include <stdlib.h>
# include <fcntl.h>
# include <sys/types.h>
# include <sys/uio.h>

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 42
# endif

char	*get_next_line(int fd);
char	*ft_conca(char *dst, char *src);
char	*ft_calloc_char(size_t size);
size_t	ft_strlen(char *s);
char	*ft_getline(char *s);
char	*ft_getrest(char *s);
int		ft_slineret(char *s);
char	*ft_freer(void *ptr1, void *ptr2);

#endif
