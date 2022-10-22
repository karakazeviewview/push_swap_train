#include "libft.h"

int ft_isalnum(int c)
{
	return (ft_isalnum(c) || ft_isalpha(c));
}

/*
int main(void)
{
	for (int i = 0; i < 512; i++)
	{
		printf("%d\n", ft_isalnum(i));
	}
	return (0);
}
*/