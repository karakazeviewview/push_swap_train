#include "libft.h"

void ft_bzero(void *s, size_t n)
{
	ft_memset(s, 0, n);
}

/*
int main(void)
{
	char str[] = "012345678901234567890123456789";
	ft_bzero(str, 5);
	int i = 0;
	while (i < 10)
	{
		printf("%c\n", str[i]);
		i++;
	}
	return (0);
}
*/