/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jibanez- <jibanez-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/12 11:27:24 by jibanez-          #+#    #+#             */
/*   Updated: 2021/03/12 11:27:24 by jibanez-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_collect_flags(t_storage *obj)
{
	if (obj->str[obj->i] == '#')
		return (obj->flags.hash= true);
	else if (obj->str[obj->i] == '0')
		return (obj->flags.zero = true);
	else if (obj->str[obj->i] == ' ')
		return (obj->flags.plus = true);
	else if (obj->str[obj->i] == '-')
		return (obj->flags.minus = true);
	else if (obj->str[obj->i] == '+')
		return (obj->flags.plus = true);
	return(-1);
}

void	ft_initialized_flags_and_tags(t_storage *obj)
{
	obj->type_field = 0;
	obj->length_field = 0;
	obj->width_field = 0;
	obj->precision_field = -1;
	ft_bzero(&obj->flags, sizeof(obj->flags));
	ft_bzero(&obj->len, sizeof(obj->len));
}

void	ft_parse(t_storage *obj)
{
	obj->i++;
	ft_initialized_flags_and_tags(&obj);
	ft_collect_flags(obj);
}

void	ft_initialized_vars(t_storage *obj)
{
	obj->i = 0;
	obj->i_prev = 0;
}


void	ft_start_printf(va_list args, const char *fmt)
{
	t_storage obj;

	obj.str = fmt;
	ft_initialized_vars(&obj);
	while (obj.str[obj.i] != '\0')
	{
		if (obj.str[obj.i] == '%')
		{
			ft_parse(&obj);
		}
		write(1, &obj.str[obj.i], 1);
		obj.i++;
	}
}

int		ft_printf(const char *fmt, ...)
{
	va_list args;
	va_start(args, fmt);
	ft_start_printf(args, fmt);
	va_end(args);
	return (1);
}
