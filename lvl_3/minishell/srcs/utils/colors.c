/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   colors.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dareias- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/07 16:18:22 by dareias-          #+#    #+#             */
/*   Updated: 2022/01/10 14:29:29 by dareias-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

char	*ft_color(unsigned int color)
{
	if (color == WHT)
		return ("\033[0;37m");
	if (color == BLK)
		return ("\033[0;30m");
	if (color == RED)
		return ("\033[0;31m");
	if (color == YEL)
		return ("\033[0;33m");
	if (color == BLU)
		return ("\033[0;34m");
	if (color == GRN)
		return ("\033[0;32m");
	if (color == CYA)
		return ("\033[0;36m");
	if (color == PUR)
		return ("\033[0;35m");
	return ("");
}

void	change_color(unsigned int color)
{
	char	*s;

	s = ft_color(color);
	printf("%s", s);
}
