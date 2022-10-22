#include "libft.h"

char *ft_strdup(const char *s1)
{
	char *ptr;
	char *save;

	if (!s1)
		return (NULL);
	ptr = (char *)malloc(ft_strlen(s1) + 1);
	if (!ptr)
		return (NULL);
	while (*s1)
		*ptr++ = *s1++;
	*ptr = 0;
	return (save);
}

/*
int main(void)
{
	char *string = "this is a copy";
	char *newlist;
	if ((newlist = ft_strdup(string)) != NULL)
	{
		printf("The new string is: %s\n", newstr);
		printf("%p\n%p\n", string, newstr);
	}
	printf("%s\n", strdup((char*)""));
	printf("%s\n", ft_strdup((char *)""););
	printf("%p\n", strdup((char *)""););
	printf("%p\n", ft_strdup((char *)""));
	return (0);
}
*/