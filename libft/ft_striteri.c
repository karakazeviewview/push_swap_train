//#include "libft.h"
#include <libc.h>

void ft_striteri(char *s, void (*f)(unsigned int, char *))
{
	unsigned int i;

	if (s == NULL || f == NULL)
		return ;
	i = 0;
	while (s[i] != '\0')
	{
		(*f)(i, &s[i]);
		i++;
	}
}

void ft_plusone(unsigned int i, char *str)
{
	*str = *str + 1;
}
void ft_plusi(unsigned int i, char *str)
{
	*str = *str + i;
}
/*
int main(void)
{
	char s[] = "abcdefg";

	ft_striteri(s, ft_plusone);
	printf("%s\n", s);
	strcpy(s, "abcdefg");
	ft_striteri(s, ft_plusi);
	printf("%s\n", s);
	return (0);
}
*/