#include "libft.h"

void ft_putendl_fd(char *s, int fd)
{
	size_t i;

	i = 0;
	while (s[i] != '\0')
		write(fd, &s[i++], 1);
	write(fd, "\n", 1);
}

/*
int main(void)
{
	ft_putendl_fd("42Tokyo", 1);
	return (0);
}
*/