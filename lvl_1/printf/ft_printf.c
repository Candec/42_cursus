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

void	ft_collect_data(t_storage *obj)
{
	g_ft_dispatch_table[obj->type_field](obj);
}


void	ft_collect_width(t_storage *obj)
{
	if (ft_isdigit(obj->str[obj->i]) == 1)
		obj->width_field = ft_atoi(&obj->str[obj->i]);
	else if (obj->str[obj->i] == '*' && ft_isdigit(obj->str[obj->i + 1]) != 1)
	{
		obj->width_field = va_arg(obj->arguments, int);
		obj->i++;
		if (obj->width_field < 0)
		{
			obj->flags.zero = false;
			obj->flags.minus = true;
			obj->width_field = -1 * obj->width_field;
		}
	}
	else if (obj->str[obj->i] == '*' && ft_isdigit(obj->str[obj->i + 1]) == 1)
	{
		obj->width_field = va_arg(obj->arguments, int);
		obj->width_field = ft_atoi(&obj->str[obj->i + 1]);
		obj->i = obj->i + 2;
	}
}

void	ft_collect_precision(t_storage *obj)
{
	if (obj->str[obj->i] == '.' && ft_isdigit(obj->str[obj->i + 1]) == 1)
	{
		obj->i++;
		obj->precision_field = ft_atoi(&obj->str[obj->i]);
		while (ft_isdigit(obj->str[obj->i]) == 1)
			obj->i++;
	}
	else if (obj->str[obj->i] == '.' && obj->str[obj->i + 1] == '*')
	{
		obj->precision_field = va_arg(obj->arguments, int);
		obj->i = obj->i + 2;
		if (obj->precision_field < 0)
			obj->precision_field = -1;
	}
	else if (obj->str[obj->i] == '*' && ft_isdigit(obj->str[obj->i + 1]) != 1)
	{
		obj->i++;
		obj->precision_field = 0;
	}
}

void	ft_collect_length(t_storage *obj)
{
	char	current;
	char	next;

	current = obj->str[obj->i];
	next = obj->str[obj->i + 1];
	if ((current == 'h' && next == 'h') || current == 'l' && next == 'l')
	{
		if (current == 'h' && next == 'h')
			obj->len.hh = true;
		else if (current == 'l' && next == 'l')
			obj->len.ll = true;
		obj->i = obj->i + 2;
	}
	else if (current == 'h' || current == 'l' || current == 'L')
	{
		if (current == 'h')
			obj->len.h = true;
		else if (current == 'l')
			obj->len.l = true;
		else if (current == 'L')
			obj->len.uppercase_l = true;
		obj->i++;
	}
}

void	ft_collect_type_of_field(t_storage *obj)
{
	char c;
	char *valid;
	int j;

	c = obj->str[obj->i];
	valid = "cspdiouxXfb%";
	while (valid[j])
	{
		if (valid[j] == c)
		{
			obj->type_field = j;
			return ;
		}
		j++;
	}
}

void	ft_cancel_flags(t_storage *obj)
{
	if (obj->flags.plus == true)
		obj->flags.space = false;
	if (obj->flags.minus == true)
		obj->flags.zero = false;
}

int	ft_collect_flags(t_storage *obj)
{
	if (obj->str[obj->i] == '#')
		return (obj->flags.hash = true);
	else if (obj->str[obj->i] == '0')
		return (obj->flags.zero = true);
	else if (obj->str[obj->i] == ' ')
		return (obj->flags.plus = true);
	else if (obj->str[obj->i] == '-')
		return (obj->flags.minus = true);
	else if (obj->str[obj->i] == '+')
		return (obj->flags.plus = true);
	return (-1);
}

void	ft_start_collect_flags(t_storage *obj)
{
	while (ft_collect_flags(obj) != -1)
		obj->i++;
	ft_cancel_flags(obj);
	ft_collect_width(obj);
	ft_collect_precision(obj);
	ft_collect_length(obj);
	ft_collect_type_of_field(obj);
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
	ft_initialized_flags_and_tags(obj);
	if (obj->str[obj->i] == '\0')
		return ;
	ft_start_collect_flags(obj);
	ft_collect_data(obj);
}

void	ft_initialized_vars(t_storage *obj)
{
	obj->i = 0;
	obj->i_prev = 0;
}

void	ft_start_printf(va_list args, const char *fmt)
{
	t_storage	obj;

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

int	ft_printf(const char *fmt, ...)
{
	va_list	args;

	va_start(args, fmt);
	ft_start_printf(args, fmt);
	va_end(args);
	return (1);
}
