/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   collect_c.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jibanez- <jibanez-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/27 19:12:35 by jibanez-          #+#    #+#             */
/*   Updated: 2021/03/27 19:12:35 by jibanez-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	collect_c(t_storage *obj)
{
	int	c;
	int	i;

	c = va_arg(obj->arguments, int);
	i = 0;
	if (obj->width_field > 0)
		i = obj->width_field - 1;
	if (obj->flags.minus == false)
	{
		if (obj->flags.zero == true)
			append_loop(obj, "0", i);
		else if (obj->flags.zero == false)
			append_loop(obj, " ", i);
		obj->f_string[obj->f_string_i++] = c;
	}
	else if (obj->flags.minus == true)
	{
		obj->f_string[obj->f_string_i++] = c;
		append_loop(obj, " ", i);
	}
}