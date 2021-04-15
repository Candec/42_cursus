#include "ft_printf.h"

void	into_loop(t_printf *p, char *s)
{
	int	i;

	i = 0;
	while (s[i] != '\0')
	{
		p->f_str[p->f_i] = s[i];
		p->f_i++;
		i++;
	}
}

void	ft_init_printf(va_list args, const char *s)
{
	t_printf p;

	p.str = s;
	p.i = 0;
	p.f_i = 0;
	va_copy(p.args, args);
	while (p.str[p.i] != '\0')
	{
		if (p.str[p.i] == '%')
		{
			collect_flags(&p);
		}
		write(1, &p.str[p.i], 1);
		p.i++;
	}
}

int	ft_printf(const char *s, ...)
{
	va_list args;

	va_start(args, s);
	ft_init_printf(args, s);
	va_end(args);
	return(0);
}

int main()
{
	ft_printf("test de % asdasd");
}
