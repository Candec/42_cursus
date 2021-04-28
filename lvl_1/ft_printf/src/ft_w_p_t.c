#include "ft_printf.h"

void	ft_collect_width(t_printf *p)
{
	if (ft_isdigit(p->str[p->i]))
	{
		p->var.width = ft_atoi(&p->str[p->i]);
		while (ft_isdigit(p->str[p->i]))
			p->i++;
	}
	else if (p->str[p->i] == '*')
	{
		p->var.width = va_arg(p->args, int);
		p->i++;
	}
}

void	ft_collect_precision(t_printf *p)
{
	if (p->str[p->i] == '.' && ft_isdigit(p->str[p->i + 1]))
	{
		p->var.precision = ft_atoi(&p->str[p->i + 1]);
		p->i++;
		while (ft_isdigit(p->str[p->i]))
			p->i++;
	}
	else if (p->str[p->i] == '.' && p->str[p->i + 1] == '*')
	{
		p->var.precision = va_arg(p->args, int);
		p->i += 2;
	}
	else if (p->str[p->i] == '.')
	{
		p->var.precision = 0;
		p->i++;
	}
}

void	ft_collect_type(t_printf *p)
{
	int		i;
	char	c;
	char	*str;

	i = 0;
	c = p->str[p->i];
	str = VALID;
	while (str[i] != '\0')
	{
		if (c == str[i])
		{
			p->type_field = i;
			return ;
		}
		i++;
	}
}

void	ft_collect_data(t_printf *p)
{
	static t_collect	*g_ft_table[] = {
	collect_c,
	collect_s,
	collect_p,
	// collect_d,
	// collect_d,
	// **  collect_o,
	// collect_u,
	// collect_x,
	// collect_x,
	// **  collect_f,
	// **  collect_b,
	// collect_percent
	};

	g_ft_table[p->type_field](p);
}
