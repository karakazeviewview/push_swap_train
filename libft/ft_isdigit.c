#include "libft.h"

int ft_isdigit(int c)
{
	return ('0' <= c && c <= '9');
}

/*
int main(void)
{
	for (int i = 0; i < 522; i++)
	{
		printf("%d\n", ft_isdigit(1));
	}
	return (0);
}
*/