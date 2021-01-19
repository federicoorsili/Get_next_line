/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: forsili <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/18 14:00:57 by forsili           #+#    #+#             */
/*   Updated: 2021/01/18 14:00:59 by forsili          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

//#include "get_next_line.h"
#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>
#include <fcntl.h>
 

size_t	ft_strlen(const char *str);
char		*ft_substr(char const *s, unsigned int start, size_t len);
char				*ft_strdup(const char *s1);
void	ft_bzero(void *s, unsigned long long n);
int	engine_smal(int fd, char **buf, char *line);

char	**malloc_buf(char **buf)
{
	int i;

	i = 0;
	if (BUFFER_SIZE == 0)
		return (0);
	if (!(buf = (char **)malloc(4064 * sizeof(char *))))
		return (0);
	while(i < 4064)
	{
		if (!(buf[i] = (char *)malloc((BUFFER_SIZE) * sizeof(char))))
			return (0);
		ft_bzero(buf[i], BUFFER_SIZE + 1);
        i++;
	}
	return (buf);
}

int	engine(int fd, char **buf, char *line)
{
    int k;
    int i;

    k = ft_strlen(line);
    i = 0;
    while (buf[fd][i] != '\n' && buf[fd][i])
    {
        line[k] = buf[fd][i];
        i++;
        k++;
    }
    line[k] = 0;
    printf("|%s| \n", line);
    if (i == ft_strlen(buf[fd]) && buf[fd][i] ==  '\n')
    {
        free(buf[fd]);
        return (1);
    }
    if (i < ft_strlen(buf[fd]) && buf[fd][i] ==  '\n')
        if ((buf[fd] = ft_substr(buf[fd], i + 1, (ft_strlen(buf[fd]) - (i + 1)))) != 0)
            return (1);
    if (i == ft_strlen(buf[fd]) && buf[fd][i] ==  0)
        return(engine_smal(fd, buf, line));
    return (1);
}

int	check_buf(int fd, char **buf, char *line)
{
    int k;
    int read_res;

    k = 0;
    if (buf[fd][k] != 0)
    {
        while (buf[fd][k] != '\n' && buf[fd][k] != 0)
        {
            line[k] = buf[fd][k];
            k++;
        }
        if (buf[fd][k] == '\n')
        {
            line[k] = 0;
            buf[fd] = ft_substr(buf[fd], k + 1, (ft_strlen(buf[fd]) - (k + 1)));
            return (1);
        }
        else if (buf[fd][k] == 0)
            ft_bzero(buf[fd], BUFFER_SIZE + 1);
    }
    if ((read_res = read(fd, buf[fd], BUFFER_SIZE)) < 1)
        return (read_res);
    read_res = engine(fd, buf, line);
        return (read_res);
}

int get_next_line(int fd, char **line)
{ 
	static char         **buf;
	int                 exit;

	if (!buf)
		if ((buf = malloc_buf(buf)) == 0)
            return (-1);
	if (!fd || !line)
		return (-1);
	exit = check_buf(fd, buf, (*line));
	if (exit != 1)
		return (exit);
	return (1);
}

int main()
{
  int fd;
  int i = 0;
  char  **line;
  int res = 1;

  if (!(line = (char **)malloc(1000 * sizeof(char *))))
      return (-1);
    if (!(line[0] = (char *)malloc(1000 * sizeof(char ))))
      return (-1);
  fd = open("prova", O_RDONLY);
  i = 0;
  while(res == 1)
  {
      res = get_next_line(fd, line);
      //printf("%d\n", res);
      //printf("|%s| \n", *line);
      if (!(line[0] = (char *)malloc(1000 * sizeof(char ))))
      return (-1);
      //printf("3\n");
  	i++;
  }
}