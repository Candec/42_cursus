/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_in_and_out.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jibanez- <jibanez-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/17 15:57:45 by dareias-          #+#    #+#             */
/*   Updated: 2022/03/10 11:23:38 by jibanez-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	set_in_and_out(t_comm *comm)
{
	int		reset_in;
	int		reset_out;
	int		while_ret;

	reset_in = 1;
	reset_out = 1;
	comm_piping(comm, &reset_in, &reset_out);
	if (comm->piping)
		if (set_pipes(comm))
			return (1);
	if (comm->redir.reads || comm->redir.heredoc)
		save_std_io(comm->shell, 1, 0);
	if (comm->redir.appends || comm->redir.writes)
		save_std_io(comm->shell, 0, 1);
	while_ret = while_set_in_and_out(comm, &reset_in, &reset_out);
	if (while_ret != 0)
		return (while_ret);
	reset_std_io(comm->shell, reset_in, reset_out);
	return (0);
}

int	reset_std_io(t_shell *shell, int reset_in, int reset_out)
{
	if (reset_in)
	{
		if (shell->io.saved_in)
		{
			dup2(shell->io.save_in, STDIN_FILENO);
			if (shell->io.current_in != STDIN_FILENO)
				close(shell->io.current_in);
			shell->io.current_in = shell->io.save_in;
			shell->io.saved_in = 0;
		}
	}
	if (reset_out)
	{
		if (shell->io.saved_out)
		{
			dup2(shell->io.save_out, STDOUT_FILENO);
			if (shell->io.current_out != STDOUT_FILENO)
				close(shell->io.current_out);
			shell->io.current_out = shell->io.save_out;
			shell->io.saved_out = 0;
		}
	}
	return (0);
}

void	save_std_io(t_shell *shell, int in, int out)
{
	if (!shell->io.saved_in && in)
	{
		shell->io.save_in = dup(STDIN_FILENO);
		shell->io.saved_in = 1;
	}
	if (!shell->io.saved_out && out)
	{
		shell->io.save_out = dup(STDOUT_FILENO);
		shell->io.saved_out = 1;
	}
}

void	close_std_io_dups(t_shell *shell)
{
	if (shell->io.saved_in)
	{
		close(shell->io.save_in);
		shell->io.saved_in = 0;
	}
	if (shell->io.saved_out)
	{
		close(shell->io.save_out);
		shell->io.saved_out = 0;
	}
}

void	comm_piping(t_comm *comm, int *reset_in, int *reset_out)
{
	if (comm->piping == 1 || comm->piping == 3)
	{
		save_std_io(comm->shell, 1, 0);
		*reset_in = 0;
	}
	if (comm->piping == 2 || comm->piping == 3)
	{
		save_std_io(comm->shell, 0, 1);
		*reset_out = 0;
	}
}
