/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isalpha.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jibanez- <jibanez-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/28 19:40:30 by jibanez-          #+#    #+#             */
/*   Updated: 2021/01/13 12:43:23 by jibanez-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_isalpha(int c)
{
	// unsigned char ch;

	// ch = c;
	// if ((ch >= 'A' && ch <= 'Z') || (ch >= 'a' && ch <= 'z'))
	// 	return (1);
	// return (0);
	return ((c >= 'A' && c <= 'Z') || (c >= 'a' && c <= 'z'));
}
