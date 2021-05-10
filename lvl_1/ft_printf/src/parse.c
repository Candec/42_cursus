#include "ft_printf.h"

static	void	collect_flags(t_printf *p, char **str)
{
	while (ft_strchr("0-", **str))
	{
		if (**str == '-')
		{
			p->minus = 1;
			*(str) += 1;
		}
		else if (**str == '0')
		{
			p->zero = 1;
			*(str) += 1;
		}
	}
}

static	void	collect_width(t_printf *p, char **str, va_list *args)
{
	while (str && (ft_isdigit(**str) || **str == '*'))
	{
		if (**str == '*' && !(p->width || p->w_aster))
		{
			p->width = va_arg(*args, int);
			p->w_aster = 1;
			p->w_inp = 1;
			*(str) += 1;
		}
		else if (!p->w_aster)
		{
			while (ft_isdigit(**str))
			{
				p->width = p->width * 10 + (int)**str - '0';
				*(str) += 1;
			}
			p->w_inp = 1;
		}
	}
}

static	void	collect_preci(t_printf *p, char **str, va_list *args)
{
	if (str && (**str == '.'))
	{
		if (*(*(str) + 1) == '*' && !p->prec)
		{
			p->prec = va_arg(*args, int);
			p->p_aster = 1;
			p->p_inp = 1;
			*(str) += 2;
		}
		else
		{
			*(str) += 1;
			while (*str && ft_isdigit(**str))
			{
				p->prec = p->prec * 10 + (int)**str - '0';
				*(str) += 1;
			}
			p->p_inp = 1;
		}
		if (!p->p_inp)
			*(str) += 1;
	}
}

static	void	collect_types(t_printf *p, char **str)
{
	int	i;

	i = -1;
	while (TYPES[++i] && str)
	{
		if (**str == TYPES[i] || **str == '%')
		{
			p->type = **str;
			return ;
		}
	}
	p->invalid = 1;
}

void	conversion(va_list *args, char **str)
{
	t_printf	p;
	char		*t_str;
	char		buffer[BUFF_LEN];

	t_str = *str;
	memories_init(&p);
	collect_flags(&p, str);
	collect_width(&p, str, args);
	collect_preci(&p, str, args);
	collect_types(&p, str);
	if (p.invalid)
		write_char(t_str - 1, *str, 0);
	else
	{
		if (!p.type)
			p.content = 0;
		else if (ft_strchr("cs%", p.type))
			char_type_mem(&p, args);
		else
			int_type_mem(&p, args, buffer);
		clean(&p);
		write_buffer(&p);
	}
}
