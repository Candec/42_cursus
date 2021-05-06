#include "ft_printf.h"

// static	void	d_sign(t_printf *p, int numb)
// {
// 	if (p->flags.plus == true && numb >= 0)
// 		p->ret += write(1, "+", 1);
// 	if (numb < 0)
// 		p->ret += write(1, "-", 1);
// }

// static	int	s_size(t_printf *p, char *str)
// {
// 	ssize_t	len;

// 	len = p->var.precision;
// 	if ((ssize_t)ft_strlen(str) > len)
// 		return (ft_strlen(str));
// 	return (len);
// }

// static	void	d_precision(t_printf *p, char *str, int numb)
// {
// 	int		i;
// 	int		size;

// 	i = 0;
// 	size = ft_strlen(str);
// 	if (p->flags.zero == false)
// 		d_sign(p, numb);
// 	if (p->var.precision > size)
// 	{
// 		while (i++ < p->var.precision - size)
// 			p->ret += write(1, "0", 1);
// 		p->ret += write(1, str, size);
// 	}
// 	else
// 		p->ret += write(1, str, size);
// }

// static	void	d_pad(t_printf *p, int i, char *str, int numb)
// {
// 	if (p->flags.minus == false)
// 	{
// 		if (p->flags.zero == true)
// 		{
// 			d_sign(p, numb);
// 			print_loop(p, '0', i);
// 		}
// 		else if (p->flags.zero == false)
// 			print_loop(p, ' ', i);
// 		d_precision(p, str, numb);
// 	}
// 	else if (p->flags.minus == true)
// 	{
// 		d_precision(p, str, numb);
// 		print_loop(p, ' ', i);
// 	}
// }

// void	collect_d(t_printf *p)
// {
// 	int		i;
// 	int		pre;
// 	int		numb;
// 	char	*str;

// 	i = 0;
// 	numb = va_arg(p->args, int);
// 	str = ft_mod_itoa(numb);
// 	pre = s_size(p, str);
// 	if (p->var.width > pre && p->var.width > 0)
// 		i = p->var.width - pre;
// 	if (p->flags.plus == true)
// 		i -= 1;
// 	d_pad(p, i, str, numb);
// }


void			collect_d(t_printf *p)
{
	int_fast64_t	n;
	char			*s;
	char			*t_s;

	s[0] = 0;
	t_s[0] = 0;
	ft_bzero(&p->var, sizeof(p->var));
	n = 0;
	n = length_field_d(p);
	if (n < 0)
	{
		ft_strcpy(s, "-");
		if (n == INT_MIN)
			ft_strcpy(t_s, "2147483648");
		else
		{
			n = ft_abs(n);
			t_s = ft_itoa_base(n, FT_DECIMAL, t_s);
		}
	}
	else
	{
		if (p->flags.plus == true)
			ft_strcpy(s, "+");
		else if (p->flags.space == true)
			ft_strcpy(s, " ");
		ft_itoa_base(n, FT_DECIMAL, t_s);
	}
	(p->var.precision != -1) && (p->flags.zero = false);
	(p->var.precision == 0 && n == 0) && (ft_strcpy(t_s, NULL));
	d_append_buffer(p, s, t_s);
}