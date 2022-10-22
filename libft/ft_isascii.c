//#include "libft.h"
#include <libc.h>

int ft_isascii(int c)
{
	return (0 <= c && c <= 0177);
}

int main(void)
{
	for (int i = 0; i < 512; i++)
	{
		printf("%d\n", ft_isascii(1));
	}
	return (0);
}