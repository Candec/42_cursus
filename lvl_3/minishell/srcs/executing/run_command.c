/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   run_command.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jibanez- <jibanez-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/17 15:44:39 by dareias-          #+#    #+#             */
/*   Updated: 2022/03/10 10:48:49 by jibanez-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static int	null_command(t_comm *comm);
static int	child_process(t_comm *comm);

static void	comm_sig(int sig)
{
	if (sig == SIGINT)
	{
		printf("\n");
	}
}

int	run_command(t_comm *comm)
{
	pid_t	pid;
	int		sta;

	if (set_in_and_out(comm))
		return (1);
	signal(SIGINT, comm_sig);
	if (comm->is_ft)
		return (run_ft_command(comm));
	if (!comm->cmd)
		return (null_command(comm));
	pid = fork();
	if (pid == -1)
		return (print_error(FORK_FAIL));
	if (pid == 0)
		child_process(comm);
	else
	{
		waitpid(pid, &sta, 0);
		sta = WEXITSTATUS(sta);
		if (sta)
			return (sta);
		return (0);
	}
	return (0);
}

static int	child_process(t_comm *comm)
{
	int	error;

	error = 0;
	if (!comm->is_ft)
	{
		error = execve(comm->cmd, comm->args, comm->shell->envp);
		if (error < 0)
			return (print_error(-1));
	}
	return (error);
}

static int	null_command(t_comm *comm)
{
	comm->cmd = ft_strcat("minishell: command not found: ", comm->args[0]);
	ft_putstr_fd(comm->cmd, STDERR_FILENO);
	ft_putstr_fd("\n", STDERR_FILENO);
	return (127);
}

int	run_ft_command(t_comm *ft_comm)
{
	int	sta;

	sta = 0;
	sta = exec_ft_comm(ft_comm);
	return (sta);
}
