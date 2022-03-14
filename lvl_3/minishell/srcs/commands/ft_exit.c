/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_exit.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jibanez- <jibanez-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/09 17:25:18 by Jibanez-          #+#    #+#             */
/*   Updated: 2022/02/15 18:49:55 by jibanez-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	ft_exit(t_comm *ft_comm)
{
	int		ex;
	t_shell	*sh;

	sh = ft_comm->shell;
	ex = EXIT_SUCCESS;
	if (ft_comm->args[1])
		ex = ft_atoi(ft_comm->args[1]);
	clean_shell(sh);
	if (sh->vars)
		clean_vars(sh);
	if (sh->envp)
		clean_envp(sh);
	if (sh->loop)
	{
		clear_history();
		write(1, "exit\n", 6);
	}
	exit(ex);
}
