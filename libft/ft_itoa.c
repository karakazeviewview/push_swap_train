#include "libft.h"

static size_t get_size(int n)
{
	size_t len;

	len = 0;
	if (!n)
		return (1);
	if (n < 0)
		len++;
	while (n)
	{
		n = n / 10;
		len++;
	}
	return (len);
}

char *ft_itoa(int n)
{
	char *s;
	size_t len;
	int num;

	len = get_size(n);
	s = malloc(sizeof(int) * (len + 1));
	if (!s)
		return (NULL);
	num = n;
	while (len--)
	{
		if (num < 0)
			s[len] = -(num % 10) + '0';
		else
			s[len] = num % 10 + '0';
		num = num / 10;
	}
	if (n < 0)
		*s = '-';
	return (s);
}