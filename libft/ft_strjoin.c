#include "libft.h"

char *ft_strjoin(char const *s1, char const *s2)
{
	char *ptr;
	char *save;

	if (!s1 || !s2)
		return (NULL);
	ptr = (char *)malloc(ft_strlen(s1) + ft_strlen(s2) + 1);
	if (!ptr)
		return (NULL);
	save = ptr;
	while (*s1)
		*ptr++ = *s1++;
	while (*s2)
		*ptr++ = *s2++;
	*ptr = 0;
	return (save);
}

/*
int main(void)
{
	printf("%s\t%s\n", ft_strjoin("hello", "world"));
	printf("%s\t%s\n", ft_strjoin("", "world"), "world");
	printf("%s\t%s\n", ft_strjoin("hello", ""), "hello");
	printf("%s\t%s\n", ft_strjoin("", ""), "");
	return (0);
}
*/