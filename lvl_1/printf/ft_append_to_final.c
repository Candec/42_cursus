/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_append_to_str.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jibanez- <jibanez-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/31 17:17:21 by jibanez-          #+#    #+#             */
/*   Updated: 2021/03/31 17:17:21 by jibanez-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	append_to_final(t_storage *obj, char *source)
{
	int	i;

	i = 0;
	printf("here");
	if (source)
		while (source[i] != '\0')
		{
			obj->f_string[obj->f_string_i++] = source[i++];
			printf("this is i:%d", i);
			if(i > 10)
				exit(0);
			else
				continue;	
		}
	obj->f_string[obj->f_string_i] = '\0';
}

void	append_loop(t_storage *obj, char *source, int i)
{
	printf("here");
	if (source[1] != '\0')
		while (i--)
			append_to_final(obj, source);
	else if (source[1] == '\0')
		while (i--)
			obj->f_string[obj->f_string_i++] = source[0];
}
