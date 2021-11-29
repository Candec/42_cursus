/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ternary.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jibanez- <jibanez-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/29 15:12:21 by jibanez-          #+#    #+#             */
/*   Updated: 2021/11/29 17:55:34 by jibanez-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int8_t	ft_ternary8(int flag, int8_t a, int8_t b)
{
	if (flag)
		return (a);
	return (b);
}

int16_t	ft_ternary16(int flag, int16_t a, int16_t b)
{
	if (flag)
		return (a);
	return (b);
}

int32_t	ft_ternary32(int flag, int32_t a, int32_t b)
{
	if (flag)
		return (a);
	return (b);
}

int64_t	ft_ternary64(int flag, int64_t a, int64_t b)
{
	if (flag)
		return (a);
	return (b);
}
