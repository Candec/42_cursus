/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   collect_d.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jibanez- <jibanez-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/06 18:33:51 by jibanez-          #+#    #+#             */
/*   Updated: 2021/04/06 19:32:07 by jibanez-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
int_fast64_t	length_field_d(t_storage *obj)
{
	int_fast64_t	num;

	num = 0;
	if (obj->len.hh == true)
		num = (char)va_arg(obj->arguments, int);
	else if (obj->len.h == true)
		num = (short)va_arg(obj->arguments, int);
	else if (obj->len.l == true)
		num = va_arg(obj->arguments, long);
	else if (obj->len.ll == true)
		num = va_arg(obj->arguments, long long);
	else
		num = va_arg(obj->arguments, int);
	return (num);
}

void	collect_d(t_storage *obj)
{
	int_fast64_t	n;
	char			*str;
	char			*tmp;

	str = ft_calloc(0, (ft_abs(obj->precision_field) + obj->width_field + 32));
	tmp = ft_calloc(0, (ft_abs(obj->precision_field) + obj->width_field + 32));
	ft_bzero(&obj->vars, sizeof(obj->vars));
	n = 0;
	n = length_field_d(obj);
	if (n < 0)
	{
		ft_strcpy(str, "-");
		// ft_itoa_min(obj, n, tmp);
	}
	else
	{
		if (obj->flags.plus == true)
			ft_strcpy(str, "+");
		else if (obj->flags.space == true)
			ft_strcpy(str, " ");
		// ft_itoa_base(n, FT_DECIMAL, tmp);
	}
	(obj->precision_field != -1) && (obj->flags.zero = false);
	(obj->precision_field == 0 && n == 0) && (ft_strcpy(tmp, NULL));
	// d_append_buffer(obj, str, tmp);
}
