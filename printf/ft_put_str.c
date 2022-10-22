#include "ft_printf.h"
static size_t ft_strlen(const char *s)
{
	size_t i;

	i = 0;
	while (s[i] != '\0')
		i++;
	return (i);
}
ssize_t ft_put_str(char *str)
{
	if (!str)
		return (write(1, "(null)", 6));
	return (write(1, str, ft_strlen(str)));
}
ssize_t ft_put_char(char c)
{
	return (write(1, &c, 1));
}