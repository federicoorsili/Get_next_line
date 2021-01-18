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
int read_file(char **line, char **buf, int fd, int flag);

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
		if (!(buf[i] = (char *)malloc((BUFFER_SIZE + 1) * sizeof(char))))
			return (0);
		i++;
	}
	return (buf);
}

int	check_buf(int fd, char **buf, char **line, int control)
{
	int i;
	int k;
	int sw;
	char *tmp;

	i = 0;
	k = ft_strlen(*line);
	while (buf[fd][i] != '\n' && buf[fd][i])
	{
		printf("giustalol\n");
		(*line)[k] = buf[fd][i];
		printf("%c\n%c\n", *line[k], buf[fd][i]);
		k++;
		i++;
	}
	sw = (buf[fd][i] == '\n' ? 1 : 0);
	if (sw == 1 && (*line)[k - 1] == buf[fd][ft_strlen(buf[fd]) - 2])
	{
		line[k] = 0;
		printf("giusta %s\n", (*line));
		return (1);
	}
	else if (sw == 1 && (*line)[k - 1] != buf[fd][ft_strlen(buf[fd]) - 1])
	{
		if(!(tmp = (char *)malloc((ft_strlen(buf[fd]) + 1) * sizeof (char))))
			return (-1);
		tmp = ft_strdup(buf[fd]);
		buf[fd] = ft_substr(tmp, ft_strlen(*line), (ft_strlen(buf[fd]) - ft_strlen(*line)));
		printf("lunga %s\n", (*line));
		return (1);
	}
	else if (sw == 0 && k > i)
	{
		printf("corta %s\n", (*line));
		/*salva l'ccedenza*/
		if (control == 0)
			return (0);
		else
		{
			ft_bzero(buf, BUFFER_SIZE);
			read_file(line, buf, fd, 1);
		}
	}
	if (sw == 0 && control < BUFFER_SIZE)
		return (0);
	return (1);
}

int get_next_line(int fd, char **line)
{ 
	static char         **buf;
	int                 exit;

	if (!buf)
		{
			buf =malloc_buf(buf);
			if(!buf)
				return (-1);
		}
	if (!fd)
		return (-1);
	printf("check 1v\n");
	exit = read_file(line, buf, fd, 0);
	if (exit != 1)
		return (exit);
	//exit = check_buf(fd, buf, line , 1);
	//if (exit != 1)
	//	return (exit);
	return (1);
}

int main()
{
  int fd;
  int i = 0;
  char  **line;
  

  if (!(line = (char **)malloc(100000 * sizeof(char *))))
      return (-1);
  while (i < 300)
  {
  	if (!(line[i] = (char *)malloc(100 * sizeof(char ))))
      return (-1);
  	i++;
  }
  fd = open("prova", O_RDONLY);
  i = 0;
  while(get_next_line(fd, line) == 1)
  	i++;
}

