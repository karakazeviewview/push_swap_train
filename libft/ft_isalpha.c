#include "libft.h"

int ft_isalpha(int c)
{
	return (('A' <= c && c <= 'Z') || ('a' <= c && c <= 'z'));
}

/*
int main(void)
{
	for (int i = 0; i < 512; i++)
	{
		printf("%d\n", ft_isalpha(i));
	}
	return (0);
}
*/