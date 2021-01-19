/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: forsili <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/18 14:03:21 by forsili           #+#    #+#             */
/*   Updated: 2021/01/18 14:03:23 by forsili          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_GETNEXTLINE
# define FT_GETNEXTLINE

# include <unistd.h>
# include <stdlib.h>

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 4000
# endif

int		get_next_line(int fd, char **line);
char	*ft_strcpy(char *dest, char *src);
void	ft_bzero(void *s, unsigned long long n);
int		ft_strlen(const char *str);
int		check_zero(char buf[4064][BUFFER_SIZE], int fd);

#endif
