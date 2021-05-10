#include "ft_printf.h"

static void	handles_content(t_printf *p, char **t_str, char **res, int size)
{
	char	*empty;

	empty = "";
	if (p->type == 'c' && !p->chr)
	{
		write_char(*t_str, *res, 0);
		write_char(empty, empty + 1, 0);
		ft_bzero(*t_str, size);
		*res = *t_str;
		p->len = 0;
	}
	else if (p->type == 'c' || p->type == '%')
		ft_memset(*res, p->chr, 1);
	else if (!p->content && p->type == 's')
		ft_strlcat(*res, "(null)", p->len + 1);
	else
		ft_strlcat(*res, (char *)p->content, p->len + 1);
}

void	write_buffer(t_printf *p)
{
	char	*t_str;
	char	*res;
	int		size;

	size = p->width + p->negative + p->nbr_zeros
		+ p->len + p->minus + 1;
	res = ft_calloc(size, sizeof(char));
	if (!res)
		return ;
	t_str = res;
	while (!p->minus && p->width-- > 0)
		*(res++) = ' ';
	if (p->negative)
		ft_memset(res++, '-', 1);
	if (p->nbr_zeros)
		ft_memset(res, '0', p->nbr_zeros);
	res += p->nbr_zeros;
	handles_content(p, &t_str, &res, size);
	res += p->len;
	while (p->minus--)
		*(res++) = ' ';
	write_char(t_str, res, 0);
	free(t_str);
	t_str = NULL;
}
