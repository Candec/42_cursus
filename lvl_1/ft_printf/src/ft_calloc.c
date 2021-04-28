/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jibanez- <jibanez-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/02 16:40:58 by jibanez-          #+#    #+#             */
/*   Updated: 2021/04/27 13:55:29 by jibanez-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	*ft_calloc(size_t nmemb, size_t size)
{
	void	*m;

	m = malloc(size * nmemb);
	if (m == 0)
		return (0);
	ft_bzero(m, size * nmemb);
	return (m);
}
