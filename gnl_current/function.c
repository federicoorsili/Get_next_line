#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>
#include <fcntl.h>

//#define BUFFER_SIZE 0

char  *ft_strcpy(char *dest, char *src)
{
  int i;

  i = 0;
  while (src[i] != '\0')
  {
    dest[i] = src[i];
    i++;
  }
  dest[i] = '\0';
  return (dest);
}

size_t  ft_strlen(const char *str)
{
  size_t i;

  i = 0;
  while (str[i])
    i++;
  return (i);
}

int check_zero(char buf[4064][BUFFER_SIZE], int fd)
{
  int i;
  int count;

  i = 0;
  count = 0;
  while (i < BUFFER_SIZE)
  {
    if (buf[fd][i] == 0)
      count++;
    i++;
  }
  if (count == BUFFER_SIZE)
    return (1);
  return (0);
}

char *alloc(char *str)
{
  int i;
  char *tmp;

  i = 0;
  if(!(tmp = malloc((ft_strlen(str) + BUFFER_SIZE + 1 ) * sizeof(char))))
    return (0);
  i = 0;
  tmp = ft_strcpy(tmp, str);
  free(str);
  return (tmp);
}

int     check_buf(char buf[4064][BUFFER_SIZE], char **line, int fd)
{
    int k;
    int j;
    int res_read;

    k = 0;
    j = ft_strlen(*line);
    if (!(check_zero(buf, fd)))
    {
     while (buf[fd][k] != '\n' && k < BUFFER_SIZE)
        {
            if (buf[fd][k] != 0)
            {
                (*line)[j] = buf[fd][k];
                buf[fd][k] = 0;
                j++;
                //printf("%s\n", *line);
            }
            k++;
        }
        (*line)[j] = 0;
      }
      if (buf[fd][k] == '\n')
          return (1);
      *line = alloc(*line);
      res_read = (read(fd, buf[fd], BUFFER_SIZE));
      //printf("%d", res_read);
      if (res_read <= 0)
          return (res_read);
      if (res_read > 0)
        (check_buf(buf, line, fd));
      if ((read(fd, buf[fd], BUFFER_SIZE)) == 0)
        return (0);
      return (1);
}

int get_next_line(int fd, char **line)
{ 
    static  char       buf[4064][BUFFER_SIZE];
  int                 exit;

  if (fd < 0 || !line || BUFFER_SIZE <= 0)
    return (-1);
  if (!(*line = (char *)malloc(BUFFER_SIZE * sizeof(char))))
          return (-1);
  exit = check_buf(buf, line, fd);
//  printf("exit : %d", exit);
  if (exit != 1)
    return (exit);
  return (1);
}

int main()
{
  char *line;
  int fd = open("prova", O_RDONLY);

  get_next_line(fd, &line);
  printf("%s\n\n", line);
  get_next_line(fd, &line);
  printf("%s\n\n", line);
  get_next_line(fd, &line);
  printf("%s\n\n", line);
}