/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isalnum.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jibanez- <jibanez-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/02 15:17:42 by jibanez-          #+#    #+#             */
/*   Updated: 2020/12/02 15:17:42 by jibanez-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
int	ft_isalnum(int c)
{
	unsigned char ch;

	ch = c;
	if (ft_isalpha(ch) || ft_isdigit(ch))
		return (1);
	return (0);
}
