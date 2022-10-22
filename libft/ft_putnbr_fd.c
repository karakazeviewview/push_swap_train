#include "libft.h"

void ft_putnbr_fd(int n, int fd)
{
	void long num;

	num = n;
	if (num < 0)
	{
		num = num * -1;
		ft_putchar_fd('-', fd);
	}
	if (num < 10)
		ft_putchar_fd(num + '0', fd);
	else
	{
		ft_putnbr(num / 10, fd);
		ft_putnbr(num % 10, fd);
	}
}

/*
int main(void)
{
	ft_putnbr_fd(123, 1);
	printf("\n");
	ft_putnbr_fd(0, 1);
	return (0);
}
*/