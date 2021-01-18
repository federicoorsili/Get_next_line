/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: forsili <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/18 17:17:31 by forsili           #+#    #+#             */
/*   Updated: 2021/01/18 17:17:34 by forsili          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

//#include "get_next_line.h"
#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>
#include <fcntl.h>
 

int	check_buf(int fd, char **buf, char *line, int control);

size_t	ft_strlen(const char *str)
{
	size_t i;

	i = 0;
	while (str[i])
		i++;
	return (i);
}

int read_file(char *line, char **buf, int fd, int flag)
{
	int k;
	int control;

	k = 0;
	control = 0;
	// bisogna controllare se il buffer é vuoto, se non lo é, copiare prima il buffer e poi cominciare a leggere 
	if (flag == 1)
	{
		while (buf[fd][k])
		{
			line[k] = buf[fd][k];
			k++;
		}
	}
	control = read(fd, buf[fd], BUFFER_SIZE);
	if (control < 0)
		return (-1);
	check_buf(fd, buf, line, control);
	return (1);
}

void	ft_bzero(void *s, unsigned long long n)
{
	unsigned long long int i;

	i = 0;
	while (i < n)
	{
		((unsigned char *)s)[i] = (unsigned char)0;
		i++;
	}
}

char				*ft_strdup(const char *s1)
{
	char					*out;
	size_t					i;

	i = 0;
	if (!(out = malloc((ft_strlen(s1) + 1) * sizeof(char))))
		return (0);
	while (i < ft_strlen(s1))
	{
		out[i] = s1[i];
		i++;
	}
	out[i] = 0;
	return (out);
}

size_t	ft_strlcpy(char *dst, const char *src, size_t dstsize)
{
	size_t i;

	i = 0;
	if (!dst || !src)
		return (0);
	if (!dstsize)
		return (ft_strlen(src));
	while (src[i] && i < dstsize - 1)
	{
		dst[i] = src[i];
		i++;
	}
	dst[i] = 0;
	return (ft_strlen(src));
}


char		*ft_substr(char const *s, unsigned int start, size_t len)
{
	char	*substr;
	size_t	new_len;

	if (s == NULL)
		return (NULL);
	if ((unsigned int)ft_strlen(s) < start)
		return (ft_strdup(""));
	new_len = ft_strlen(s + start);
	if (new_len < len)
		len = new_len;
	if (!(substr = (char *)malloc(sizeof(char) * (len + 1))))
		return (NULL);
	ft_strlcpy(substr, s + start, len + 1);
	return (substr);
}

