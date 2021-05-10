#include "ft_printf.h"

void	print_loop(t_printf *p, char s, int i)
{
	while (i--)
		p->ret += write(1, &s, 1);
}
