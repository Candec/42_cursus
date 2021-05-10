#include "ft_printf.h"

void	memories_init(t_printf *p)
{
	p->zero = 0;
	p->nbr_zeros = 0;
	p->minus = 0;
	p->width = 0;
	p->w_aster = 0;
	p->p_aster = 0;
	p->w_inp = 0;
	p->p_inp = 0;
	p->prec = 0;
	p->type = 0;
	p->chr = 0;
	p->content = 0;
	p->len = 0;
	p->negative = 0;
	p->invalid = 0;
}

void	char_type_mem(t_printf *p, va_list *args)
{
	if (ft_strchr("c%", p->type))
	{
		if (p->type == 'c')
			p->chr = va_arg(*args, int);
		else
			p->chr = '%';
		p->len = 1;
	}
	else if (p->type == 's')
	{
		(p->content) = va_arg(*args, char *);
		if (!(p->content))
			p->len = ft_strlen("(null)");
		else
			p->len = ft_strlen(p->content);
	}
}

static	void	if_number(t_printf *p, long long prov_number, char *buffer)
{
	if (prov_number < 0)
	{
		if (!ft_strchr("uxX", p->type))
		{
			p->negative = 1;
			prov_number *= -1;
		}
		else
			prov_number = UINT_MAX + prov_number + 1;
	}
	if (!prov_number && p->p_inp && !p->prec)
		return ;
	if (ft_strchr("diu", p->type))
		n_to_str(p, prov_number, DEC_BASE, buffer);
	else
	{
		n_to_str(p, prov_number, HEX_BASE, buffer);
		if (p->type == 'X')
			ft_strtoupper(p->content);
	}
}

void	int_type_mem(t_printf *p, va_list *args, char *buffer)
{
	long long	prov_number;

	ft_bzero(buffer, BUFF_LEN);
	if (ft_strchr("diuxX", p->type))
	{
		prov_number = va_arg(*args, int);
		if_number(p, prov_number, buffer);
	}
	else
	{
		prov_number = va_arg(*args, unsigned long long int);
		n_to_str(p, prov_number, HEX_BASE, buffer);
	}
}
