/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_echo.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jibanez- <jibanez-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/09 16:25:59 by Jibanez-          #+#    #+#             */
/*   Updated: 2022/02/16 12:43:06 by dareias-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static int	echo_n_flag(char *flag);

int	ft_echo(t_comm *ft_comm)
{
	int	n;
	int	i;

	n = 0;
	i = 1;
	if (ft_comm->args[1] && echo_n_flag(ft_comm->args[1]))
	{
		n = 1;
		i = 2;
	}
	while (ft_comm->args[i])
	{
		printf("%s", ft_comm->args[i++]);
		if (ft_comm->args[i])
			printf(" ");
	}
	if (n == 0)
		printf("%c", '\n');
	return (0);
}

static int	echo_n_flag(char *flag)
{
	int	i;

	i = 0;
	if (flag[i++] != '-')
		return (0);
	if (flag[i] == '\0')
		return (0);
	while (flag[i] != '\0')
	{
		if (flag[i] != 'n')
			return (0);
		i++;
	}
	return (1);
}
