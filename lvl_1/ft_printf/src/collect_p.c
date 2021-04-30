#include "ft_printf.h"

static void	p_write(t_printf *p, char *str)
{
	p->ret += write(1, "0x", 2);
	p->ret += write(1, str, ft_strlen(str));
}

static void	p_pad(t_printf *p, int i, char *str)
{
	if (p->flags.minus == false)
	{
		if (p->flags.zero == true)
			print_loop(p, '0', i);
		else if (p->flags.zero == false)
			print_loop(p, ' ', i);
		p_write(p, str);
	}
	else if (p->flags.minus == true)
	{
		p_write(p, str);
		print_loop(p, ' ', i);
	}
}

void	collect_p(t_printf *p)
{
	int				i;
	int				len;
	uint_fast64_t	pointer;
	char			*str;

	pointer = 0;
	str = 0;
	pointer = (uint_fast64_t)va_arg(p->args, void *);
	str = ft_itoa_base(pointer, FT_HEX, str);
	i = 0;
	len = ft_strlen(str);
	if (p->var.width > len)
		i = p->var.width - len - 2;
	p_pad(p, i, str);
}
