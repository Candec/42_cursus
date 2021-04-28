#include "ft_printf.h"

void	collect_c(t_printf *p)
{
	int	c;
	int	i;

	c = va_arg(p->args, int);
	i = 0;
	if (p->var.width > 1)
		i = p->var.width - 1;
	if (p->flags.minus == false)
	{
		if (p->flags.zero == true)
			print_loop(p, '0', i);
		else if (p->flags.zero == false)
			print_loop(p, ' ', i);
		p->ret += write(1, &c, 1);
	}
	else if (p->flags.minus == true)
	{
		p->ret += write(1, &c, 1);
		print_loop(p, ' ', i);
	}
}
