#include "libft.h"

int ft_isprint(int c)
{
	return (040 <= c && c <= 0176);
}

/*
int mian(void)
{
	for (int i = 0; i < 512; i++)
	{
		printf("%d", ft_isprint(i));
	}
	return (0);
}
*/