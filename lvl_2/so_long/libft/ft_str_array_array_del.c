/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_str_array_array_del.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jibanez- <jibanez-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/17 18:41:15 by jibanez-          #+#    #+#             */
/*   Updated: 2021/10/17 18:41:15 by jibanez-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_str_array_array_del(char ***str_arr)
{
	int	i;

	i = -1;
	while ((*str_arr)[++i])
		ft_strdel(&(*str_arr)[i]);
	free(*str_arr);
	*str_arr = NULL;
}
