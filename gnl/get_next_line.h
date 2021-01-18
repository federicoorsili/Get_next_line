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

# define BUFFER_SIZE 0

int			get_next_line(int fd, char **line);
size_t	ft_strlen(const char *str);
char		*ft_substr(char const *s, unsigned int start, size_t len);
char				*ft_strdup(const char *s1);
void	ft_bzero(void *s, unsigned long long n);



#endif
