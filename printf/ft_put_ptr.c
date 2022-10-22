#include "ft_printf.h"
static void ft_output(uintptr_t num, ssize_t *num_len)
{
	char c;
	if (num >= 16)
	{
		ft_output(num / 16, num_len);
		ft_output(num % 16, num_len);
	}
	else
	{
		if (num % 16 < 10)
		{
			c = (char)num + '0';
			*num_len = *num_len + write(1, &c, 1);
		}
		else
		{
			c = (char)num + 'a' - 10;
			*num_len = *num_len + write(1, &c, 1);
		}
	}
}
ssize_t ft_put_ptr(uintptr_t num)
{
	ssize_t num_len;

	num_len = write(1, "0x", 2);
	if (!num)
		num_len = num_len + write(1, "0", 2);
	else
		ft_output(num, &num_len);
	return (num_len);
}