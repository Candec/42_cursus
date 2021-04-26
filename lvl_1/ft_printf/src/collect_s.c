#include "ft_printf.h"

static	int	s_size(t_printf *p, char *str)
{
	if (ft_strlen(str) < p->var.precision)
		return (ft_strlen(str));
	return (p->var.precision);
}

static	void	s_precision(t_printf *p, char *str, int pre)
{
	int		i;
	char	c;

	i = 0;
	if (p->var.precision >= 6 && str == "(null)")
		p->ret += write(1, "(null)", 6);
	else if (p->var.precision == -1 && str == "(null)")
		p->ret += write(1, "(null)", 6);
	else if (p->var.precision < 6 && str == "(null)")
		return ;
	else if (p->var.precision >= 0)
	{
		while (i < pre)
		{
			c = str[i];
			p->ret += write(1, &c, 1);
			i++;
		}
	}
	else
		p->ret += write(1, str, ft_strlen(str));
}

void	collect_s(t_printf *p)
{
	char	*str;
	int		i;
	int		pre;

	str = va_arg(p->args, char *);
	if (!str)
		str = "(null)";
	pre = s_size(p, str);
	i = 0;
	if (p->var.width > pre)
		i = p->var.width - pre;
	if (p->flags.minus == false)
	{
		if (p->flags.zero == true)
			print_loop(p, '0', i);
		else if (p->flags.zero == false)
			print_loop(p, ' ', i);
		s_precision(p, str, pre);
	}
	else if (p->flags.minus == true)
	{
		s_precision(p, str, pre);
		print_loop(p, ' ', i);
	}
}
