/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   run_ft_command.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jibanez- <jibanez-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/07 22:39:48 by dareias-          #+#    #+#             */
/*   Updated: 2022/03/09 16:36:11 by jibanez-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	exec_ft_comm(t_comm *ft_comm)
{
	if (ft_comm->is_ft == 1)
		return (ft_cd(ft_comm));
	if (ft_comm->is_ft == 2)
		return (ft_pwd(ft_comm));
	if (ft_comm->is_ft == 3)
		return (ft_echo(ft_comm));
	if (ft_comm->is_ft == 4)
		return (ft_env(ft_comm));
	if (ft_comm->is_ft == 5)
		return (ft_export(ft_comm));
	if (ft_comm->is_ft == 6)
		return (ft_unset(ft_comm));
	if (ft_comm->is_ft == 7)
		ft_exit(ft_comm);
	return (-1);
}
