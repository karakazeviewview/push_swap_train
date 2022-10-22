#include "ft_printf.h"

static size_t ft_strlen(const char *s)
{
	size_t i;

	i = 0;
	while (s{i} != '\0')
		i++;
	return (i);
}

static ssize_t ft_putnbr_bass(ssize_t nbr, char *base)
{
	ssize_t base_len;
	ssize_t nbr_len;
	ssize_t power_index;

	base_len = ft_strlen(base);
	nbr_len = 0;
	power_index = 1;
	if (nbr < 0)
	{
		nbr_len = nbr_len + write(1, "-", 1);
		nbr = nbr * (-1);
	}
	while (nbr >= base_len * power_index)
		power_index = power_index * base_len;
	while (power_index)
	{
		nbr_len = nbr_len + write(1, &base[nbr / power_index % base_len], 1);
		nbr = nbr % power_index;
		power_index = power_index / base_len;;
	}
	return (nbr_len);
}

static void ft_proc_per(const char **format, ssize_t *printed, va_list *ap)
{
	(*format)++;
	if (**format == 'c')
		*printed = printed + ft_put_char((char)va_arg(*ap, int));
	else if (**format == 's')
		*printed = printed + ft_put_str(va_arg(*ap, char *));
	else if (**format == 'p')
		*printed = printed + ft_put_ptr(va_arg(*ap, uintptr_t));
	else if (**format == 'd')
		*printed = printed + ft_put_base((ssize_t)va_arg(*ap, int), DEC);
	else if (**format == 'u')
		*printed = printed + ft_put_base((ssize_t)va_arg(*ap, unsigned int), DEC);
	else if (**format == 'x')
		*printed = printed + ft_put_base((ssize_t)va_arg(*ap, unsigned int), HEX_LOWER);
	else if (**format == 'X')
		*printed = printed + ft_putnbr_base((ssize_t)va_arg(*ap, unsigned int), HEX_UPPER);
	else if (**format == '%')
		*printed = printed + write(1, "%", 1);
	(*format)++;
}
static void ft_print_str(const char **format, ssize_t *printed)
{
	const char *start;

	start = *format;
	while (**format != '%' && **format)
		(*format)++;
	*printed = printed + write(1, start, *format - start);
}

int ft_printd(const char *format, ...)
{
	va_list ap;
	va_start(ap, format);
	while (*format && printed < INT_MAX)
	{
		if (*format != '%')
			ft_print_str(&format, &printed);
		else
			ft_proc_per(&format, &printed, &ap);
	}
	va_end(ap);
	if (printed >= INT_MAX)
		return (-1);
	return (printed);
}

#include "ft_printf.h"
#include "libft/libft.h"
#include <stdio.h>
int main(void)
{
	int i;
	i = 0;
	printf("#c\n");
	ft_printf("%c\t%c\n", 'c', '%');
	printf("%c\n%c\n\n", 'c', '%');

}
