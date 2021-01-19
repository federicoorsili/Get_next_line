/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: forsili <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/18 14:39:47 by forsili           #+#    #+#             */
/*   Updated: 2021/01/18 14:39:49 by forsili          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>
#include <fcntl.h>

int main()
{
  int fd;
  int i = 0;
  char  *line;
  if (!(line = (char *)malloc(100000 * sizeof(char ))))
      return (-1);
  fd = open("prova", O_RDONLY);
  printf("%zd\n", read(fd, line, 30));
  //printf("%s\n", line);
  printf("%zd\n", read(fd, line, 1));
}