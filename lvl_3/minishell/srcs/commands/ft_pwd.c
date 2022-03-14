/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_pwd.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jibanez- <jibanez-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/15 15:58:05 by dareias-          #+#    #+#             */
/*   Updated: 2022/02/15 18:24:42 by jibanez-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	ft_pwd(t_comm *ft_comm)
{
	char	*cwd;

	cwd = NULL;
	(void)ft_comm;
	cwd = getcwd(cwd, 100);
	if (!cwd)
	{
		perror("Minishell: pwd: ");
		return (1);
	}
	printf("%s\n", cwd);
	free(cwd);
	return (0);
}
