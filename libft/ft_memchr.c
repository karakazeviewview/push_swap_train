#include "libft.h"

void *ft_memchr(const void *s, int c, size_t n)
{
	size_t i;
	unsigned char *chr_ptr;
	unsigned char chr_c;

	chr_ptr = (unsigned char *)s;
	chr_c = (unsigned char)c;
	i = 0;
	while (i < n)
	{
		if (chr_ptr[i] == chr_c)
			return (chr_ptr + i);
		i++;
	}
	return (NULL);
}

/*
int main(void)
{
	char str_1[100] = "0123456789"
	printf("%s\t%s\n", ft_memchr(str_1, '0', 5), memchr(str_1, '0', 5));
	printf("%s\t%s\n", ft_memchr(str_1, '6', 5), memchr(str_1, '6', 5));
	printf("%s\t%s\n", ft_memchr(str_1, '0', 100), memchr(str_1, '0', 100));
	printf("%s\t%s\n", ft_memchr(str_1, 'g', 5), memchr(str_1, 'g', 5));
	return (0);
}
*/