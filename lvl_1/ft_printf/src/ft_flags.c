#include "ft_printf.h"

void	ft_cancel_flags(t_printf *p)
{
	if (p->flags.plus == true)
		p->flags.space = false;
	if (p->flags.minus == true)
		p->flags.zero = false;
}

int	ft_look_flags(t_printf *p)
{
	if (p->str[p->i] == '#')
		return (p->flags.hash = true);
	else if (p->str[p->i] == '-')
		return (p->flags.minus = true);
	else if (p->str[p->i] == '+')
		return (p->flags.plus = true);
	else if (p->str[p->i] == ' ')
		return (p->flags.space = true);
	else if (p->str[p->i] == '0')
		return (p->flags.zero = true);
	return (-1);
}

void	ft_init_flags(t_printf *p)
{
	p->type_field = 0;
	p->var.width = 0;
	p->var.precision = -1;
	ft_bzero(&p->flags, sizeof(p->flags));
}

void	ft_collect_flags(t_printf *p)
{
	if (p->str[p->i] == '\0')
		return ;
	ft_init_flags(p);
	while (ft_look_flags(p) != -1)
		p->i++;
	ft_cancel_flags(p);
}
