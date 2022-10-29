#include "libft.h"
//#include <libc.h>

size_t ft_strlen(const char *s)
{
	size_t i;

	i = 0;
	while (s[i] != '\0')
		i++;
	return (i);
}

/*
int main(void)
{
	char str1[] = "";
	char str2[] = "world";
	printf("%lu\n", ft_strlen(str1));
	printf("%lu\n", ft_strlen(str2));
	return (0);
}
*/