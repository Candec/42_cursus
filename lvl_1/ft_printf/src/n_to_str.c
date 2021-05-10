#include "ft_printf.h"

static	void	negative_cases(t_printf *p, unsigned long long *n)
{
	if (!ft_strchr("uxX", p->type))
	{
		p->negative = 1;
		*n *= -1;
	}
	else
		*n += UINT_MAX + 1;
}

void	n_to_str(t_printf *p, unsigned long long n,
			char *base, char *buffer)
{
	long long	len_of_base;
	char		digit;
	char		*t_str;

	t_str = buffer;
	len_of_base = (long long) ft_strlen(base);
	if (n == 0)
		*buffer = '0';
	if (n < 0)
		negative_cases(p, &n);
	while (n != 0)
	{
		digit = base[n % len_of_base];
		*(buffer++) = digit;
		n = n / len_of_base;
	}
	if (p->type == 'p')
		ft_strlcat(buffer, "x0", BUFF_LEN);
	ft_strrev(t_str);
	p->content = t_str;
	p->len = ft_strlen(t_str);
}
