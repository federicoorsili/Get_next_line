#include "get_next_line.h"

char	*ft_strcpy(char *dest, char *src)
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

int		ft_strlen(const char *str)
{
	int i;

	i = 0;
	while (str[i])
		i++;
	return (i);
}

int		check_zero(char buf[4064][BUFFER_SIZE], int fd)
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