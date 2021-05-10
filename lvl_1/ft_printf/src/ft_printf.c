#include "ft_printf.h"

int	write_char(char *t_str, char *str, int last)
{
	int			len;
	static int	total_len;
	int			backup;

	len = str - t_str;
	if (len)
		write(1, t_str, len);
	total_len += len;
	if (last)
	{
		backup = total_len;
		total_len = 0;
		return (backup);
	}
	return (total_len);
}

static void	read_string(va_list *args, char *str)
{
	char	*t_str;
	int		valid;

	t_str = str;
	valid = 0;
	while (*str)
	{
		if (*str == '%')
		{
			write_char(t_str, str++, 0);
			conversion(args, &str);
			str++;
			valid = 0;
			if (*str)
				t_str = str;
		}
		else
		{
			str++;
			valid = 1;
		}
	}
	if (valid)
		write_char(t_str, str, 0);
}

int	ft_printf(const char *str, ...)
{
	va_list	args;

	va_start(args, str);
	read_string(&args, (char *)str);
	va_end(args);
	return (write_char((char *)str, (char *)str, 1));
}
