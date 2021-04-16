#include "ft_printf.h"

static	void	s_precision(t_printf *p, char *str, int len)
{
	int i;
	char c;

	i = 0;

	if (p->var.precision < len && p->var.precision > 0)
	{
		while (i < p->var.precision)
		{
			c = str[i];
			p->ret += write(1, &c, 1);
			i++;
		}
	}
	else if (p->var.precision == 0)
		p->ret += write(1, NULL, 1);
	else
		p->ret += write(1, str, len);
}

void	collect_s(t_printf *p)
{
	char	*str;
	int		i;
	int		len;

	str = va_arg(p->args, char *);
	len = ft_strlen(str);
	i = 0;
	if (p->var.precision > 0)
	 	i = p->var.precision;
	if (p->var.width > len)
		i = p->var.width - len;
	if (p->flags.minus == false)
	{
		if (p->flags.zero == true)
			print_loop(p, '0', i);
		else if (p->flags.zero == false)
			print_loop(p, ' ', i);
		s_precision(p, str, len);
	}
	else if (p->flags.minus == true)
	{
		s_precision(p, str, len);
		// p->ret += write(1, str, len);
		print_loop(p, ' ', i);
	}
}