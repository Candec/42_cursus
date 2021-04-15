#include "ft_printf.h"

int	ft_init_printf(va_list args, const char *s)
{
	t_printf	p;

	p.str = s;
	p.i = 0;
	p.ret = 0;
	va_copy(p.args, args);
	while (p.str[p.i] != '\0')
	{
		if (p.str[p.i] == '%')
		{
			ft_collect_flags(&p);
			ft_collect_width(&p);
			ft_collect_precision(&p);
			ft_collect_type(&p);
			ft_collect_data(&p);
		}
		p.ret += write(1, &p.str[p.i], 1);
		p.i++;
	}
	return (p.ret);
}

int	ft_printf(const char *s, ...)
{
	va_list	args;
	int		ret;

	va_start(args, s);
	ret = ft_init_printf(args, s);
	va_end(args);
	return (ret);
}
