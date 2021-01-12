/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_toupper.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jibanez- <jibanez-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/02 16:20:41 by jibanez-          #+#    #+#             */
/*   Updated: 2021/01/12 11:02:48 by jibanez-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_toupper(int c)
{
	unsigned char ch;

	ch = c;
	if (ch >= 'a' && ch <= 'z')
		return (ch - 32);
	return (c);
}
