/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isascii.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jibanez- <jibanez-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/02 15:51:54 by jibanez-          #+#    #+#             */
/*   Updated: 2020/12/02 15:51:54 by jibanez-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_isascii(int c)
{
	unsigned char ch;

	ch = c;
	if (ch >= 0 && ch <= 127)
		return (1);
	return(0);
}