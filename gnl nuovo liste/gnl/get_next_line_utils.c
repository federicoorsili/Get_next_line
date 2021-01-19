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

typedef struct		s_list
{
	int             fd;
    char			*buf;
	struct s_list	*next;
}					t_list;

int	check_buf(int fd, char *buf, char *line);
int	engine(int fd, char *buf, char *line);

size_t	ft_strlen(const char *str)
{
	size_t i;

	i = 0;
	while (str[i])
		i++;
	return (i);
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

int	engine_smal(int fd, char *buf, char *line)
{
    int res;
    
    if (buf[0] != 0)
        ft_bzero(buf, BUFFER_SIZE);
    if ((res = read(fd, buf, BUFFER_SIZE)) == 0)
        return (1);
    return(engine(fd, buf, line));
}

t_list *src_lst(int fd, t_list *app)
{
    int i;
    t_list *newnode;

    if (!app)
    {
        if (!(app = (t_list *)malloc(sizeof(t_list))))
		return (0);
	    app->fd = fd;
        app->buf = (char *)malloc(BUFFER_SIZE * sizeof(char));
	    app->next = 0;
	    app->next = 0;
    }
    while(app->fd != fd || app->next != 0)
        app = app->next;
    if (app->next == 0)
    {
        newnode = (t_list *)malloc(sizeof(t_list));
	    newnode->fd = fd;
        newnode->buf = (char *)malloc(BUFFER_SIZE * sizeof(char));
	    newnode->next = 0;
        app->next = &(*newnode);
	    return (app);
    }
    if (app->fd == fd)
        return (app);
}

