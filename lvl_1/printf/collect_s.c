/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   collect_s.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jibanez- <jibanez-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/06 16:17:12 by jibanez-          #+#    #+#             */
/*   Updated: 2021/04/06 17:57:13 by jibanez-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	str_append_fstr(t_storage *obj, char *str, int i)
{
	if (obj->flags.minus == false)
	{
		if (obj->flags.zero == true)
			append_loop(obj, "0", i);
		else if (obj->flags.zero == false)
			append_loop(obj, " ", i);
		append_to_final(obj, str);
	}
	else if (obj->flags.minus == true)
	{
		append_to_final(obj, str);
		append_loop(obj, " ", i);
	}
}

void	collect_s(t_storage *obj)
{
	char	*tmp;
	char	str[obj->width_field + ft_abs(obj->precision_field + FT_MEMORY)];
	int	i;
	int width;
	int	precision;

	str[0] = 0;
	width = obj->width_field;
	precision = obj->precision_field;
	i = 0;
	tmp = va_arg(obj->arguments, char *);
	if (tmp == NULL)
		tmp = "(null)";
	if (obj->precision_field > 0)
		ft_strncpy(str, tmp, obj->precision_field);
	else if (obj->precision_field == -1)
		ft_strcpy(str, tmp);
	else if (obj->precision_field == 0)
		ft_strcpy(str, NULL);
	i = ft_pad(obj->width_field, ft_strlen(str));
	str_append_fstr(obj, str, i);
}