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

typedef struct		s_list
{
	int             fd;
    char			*buf;
	struct s_list	*next;
}					t_list;

size_t	ft_strlen(const char *str);
char		*ft_substr(char const *s, unsigned int start, size_t len);
char				*ft_strdup(const char *s1);
void	ft_bzero(void *s, unsigned long long n);
int	engine_smal(int fd, char *buf, char *line);
t_list *src_lst(int fd, t_list *lista);

int	engine(int fd, char *buf, char *line)
{
    int k;
    int i;

    k = ft_strlen(line);
    i = 0;
    while (buf[i] != '\n' && buf[i])
    {
        line[k] = buf[i];
        i++;
        k++;
    }
    line[k] = 0;
    //printf("|%s| \n", buf);
    if (i == ft_strlen(buf) && buf[i] ==  '\n')
    {
        free(buf);
        return (1);
    }
    if (i < ft_strlen(buf) && buf[i] ==  '\n')
        if ((buf = ft_substr(buf, i, (ft_strlen(buf) - (i)))) != 0)
            return (1);
    //printf("  entrato   %s\n", ft_substr(buf, i, (ft_strlen(buf) - (i))));
    if (i == ft_strlen(buf) && buf[i] ==  0)
        return(engine_smal(fd, buf, line));
    return (1);
}

int	check_buf(int fd, char *buf, char *line)
{
    int k;
    int read_res;

    k = 0;
    if (buf[k] != 0)
    {
        while (buf[k] != '\n' && buf[k] != 0)
        {
            line[k] = buf[k];
            k++;
        }
        if (buf[k] == '\n')
        {
            line[k] = 0;
            buf = ft_substr(buf, k + 1, (ft_strlen(buf) - (k + 1)));
            return (1);
        }
        else if (buf[k] == 0)
            ft_bzero(buf, BUFFER_SIZE + 1);
    }
    if ((read_res = read(fd, buf, BUFFER_SIZE)) < 1)
        return (read_res);
    read_res = engine(fd, buf, line);
        return (read_res);
}

int get_next_line(int fd, char **line)
{ 
	static t_list         *lst;
    t_list              *lista;
	int                 exit;

    lista = src_lst(fd, lst);
	if (!fd || !line)
		return (-1);
	exit = check_buf(fd, lista->buf, (*line));
	if (exit != 1)
		return (exit);
	return (1);
}

int main()
{
  int fd;
  int fd2;
  int i = 0;
  char  **line;
  char  **line2;
  int res = 1;
  int res2 = 1;

  if (!(line = (char **)malloc(1000 * sizeof(char *))))
      return (-1);
    if (!(line[0] = (char *)malloc(1000 * sizeof(char ))))
      return (-1);
    if (!(line2 = (char **)malloc(1000 * sizeof(char *))))
      return (-1);
    if (!(line2[0] = (char *)malloc(1000 * sizeof(char ))))
      return (-1);
  fd = open("prova", O_RDONLY);
  fd2 = open("ciao", O_RDONLY);
  i = 0;
  while(res == 1 || res2 == 1)
  {
      res = get_next_line(fd, line);
      res2 = get_next_line(fd2, line2);
      //printf("%d\n", res);
      printf("prima |%s| \n", *line);
      printf("\n");
      //printf("seconda |%s| \n", *line2);
      if (!(line[0] = (char *)malloc(1000 * sizeof(char ))))
      return (-1);
      if (!(line2[0] = (char *)malloc(1000 * sizeof(char ))))
      return (-1);
      //printf("3\n");
  	i++;
  }
}