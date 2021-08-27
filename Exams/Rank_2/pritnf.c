#include <unistd.h>
#include <stdarg.h>
#include <stdio.h>

size_t	ft_strlen(const char *s)
{
	size_t	i = 0;

	while (s[i] != '\0')
		i++;
	return (i);
}

int	ft_numlen(long long int num, int basel)
{
	int i;

	i = 1;
	while (num >= basel || num <= -basel)
	{
		num /= basel;
		i++;
	}
	return (i);
}

void	ft_print_num(long long int num, int basel, char *base)
{
	if (num >= basel)
		ft_print_num(num / basel, basel, base);
	write(1, &base[num % basel], 1);
}

int	ft_printf(char *fmt, ...)
{
	char *s, *base, *str;
	va_list list;

	str = (char *)fmt;

	va_start(list, fmt);
	int w = 0, p = 0, spc = 0, dot = 0, neg = 0, zero = 0, basel = 0, num = 0, str_len = 0, len = 0;
	while (*str != '\0')
	{
		if (*str == '%')
		{
			w = 0, p = 0, spc = 0, dot = 0, neg = 0, zero = 0, basel = 0, num = 0, len = 0;
			str++;

			//width
			while (*str >= '0' && *str <= '9')
			{
				w = w * 10 + (*str - 48);
				str++;
			}
			//precision
			if (*str == '.')
			{
				while (*str >= '0' && *str <= '9')
				{
					p = p * 10 + (*str - 48);
					str++;
				}
				dot = 1;
			}
			//conversion
			if (*str == 's')
			{
				s = va_arg(list, char *);
				if (!s)
					s = "(null)";
				len = ft_strlen(s);
			}
			else if (*str == 'd')
			{
				num = va_arg(list, int);
				if (num < 0)
				{
					num *= -1;
					neg = 1;
				}
				base = "0123456789";
				basel = 10;
				len = ft_numlen(num, basel);
			}
			else if (*str == 'x')
			{
				num = va_arg(list, unsigned);
				base = "0123456789abcdef";
				basel = 16;
				len = ft_numlen(num, basel);
			}
			//formating calculation
			if (dot == 1 && p > len && *str != 's')
				zero = p - len;
			if (dot == 1 && p < len && *str == 's')
				len = p;
			if (dot == 1 && p == 0 && (*str == 's' || num > 0))
				p = 0;
			spc = w - len - p;

			//printing formating
			while (spc-- > 0)
				str_len += write(1, " ", 1);
			if (neg == 1)
				str_len += write(1, "-", 1);
			while (zero-- > 0)
				str_len += write(1, "0", 1);
			if (*str == 's')
				str_len += write(1, s, len);
			else if (num >= 0)
			{
				str_len += len;
				ft_print_num(num, basel, base);
			}
		}
		else
			str_len += write(1, str, 1);
		str++;
	}
	va_end(list);
	return (str_len);
}

int main(int argc, char *argv)
{
	printf("referencia:   ");
	printf("test str: %s | dig: %d\n", "guay", 42);
	ft_printf("Mi printf :   ");
	ft_printf("test str: %s | dig: %d\n", "guay", 42);
	return (0);
}
