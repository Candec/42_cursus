#include "ft_printf.h"

static	void	handles_negative_width_prec(t_printf *p)
{
	if (p->width < 0)
	{
		p->minus = 1;
		p->width *= -1;
	}
	if (p->prec < 0)
	{
		p->p_inp = 0;
		p->prec = 0;
	}
}

static	void	general_attributions(t_printf *p)
{
	if (p->type == 's' && p->p_inp && p->prec < p->len)
		p->len = p->prec;
	else if (p->p_inp && p->prec <= p->len)
		p->zero = 0;
	else if (!ft_strchr("sc%", p->type) && p->prec > p->len)
		p->nbr_zeros = ft_max(2, p->prec - p->len, 0);
	if (p->len + p->nbr_zeros >= p->width)
		p->width = 0;
	else if (p->nbr_zeros > 0)
		p->width = p->width - p->len - p->nbr_zeros;
	else
		p->width = p->width - p->len;
	if (p->negative && p->width > 0)
		p->width -= 1;
	if (p->zero == 1 && !p->nbr_zeros && !p->minus)
	{
		p->nbr_zeros = p->width;
		p->width = 0;
	}
	if (p->minus)
	{
		p->minus = p->width;
		p->width = 0;
	}
}

void	clean(t_printf *p)
{
	if (!p->invalid)
	{
		handles_negative_width_prec(p);
		general_attributions(p);
	}
}
