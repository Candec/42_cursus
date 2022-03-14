/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_in_and_out_two.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jibanez- <jibanez-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/09 18:44:42 by jibanez-          #+#    #+#             */
/*   Updated: 2022/03/10 11:24:31 by jibanez-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	comm_read(t_comm *comm, int *reset_in)
{
	if (comm->shell->io.current_in != STDIN_FILENO)
		close(comm->shell->io.current_in);
	comm->shell->io.current_in = change_in(STDIN_FILENO,
			comm->infile, comm->redir.reads);
	*reset_in = 0;
	if (comm->shell->io.current_in < 0)
		return (1);
	comm->redir.reads = 0;
	return (0);
}

int	comm_write(t_comm *comm, int *reset_out)
{
	close(comm->shell->io.current_out);
	comm->shell->io.current_out = change_out(STDOUT_FILENO,
			comm->outfile, comm->redir.writes);
	*reset_out = 0;
	if (comm->shell->io.current_out < 0)
		return (1);
	comm->redir.writes = 0;
	return (0);
}

int	comm_appends(t_comm *comm, int *reset_out)
{
	close(comm->shell->io.current_out);
	comm->shell->io.current_out = change_out(STDOUT_FILENO,
			comm->outfile, comm->redir.appends);
	*reset_out = 0;
	if (comm->shell->io.current_out < 0)
		return (1);
	comm->redir.appends = 0;
	return (0);
}

int	comm_heredoc(t_comm *comm, int *reset_in)
{
	if (comm->shell->io.current_in != STDIN_FILENO)
		close(comm->shell->io.current_in);
	comm->shell->io.current_in = change_in(STDIN_FILENO,
			comm->heredoc_filename, comm->redir.heredoc);
	*reset_in = 0;
	if (comm->shell->io.current_in < 0)
		return (1);
	return (0);
}

int	while_set_in_and_out(t_comm *comm, int *reset_in, int *reset_out)
{
	while (comm->redir.ammount > 0)
	{
		if (comm->redir.reads && comm_read(comm, reset_in) != 0)
			return (1);
		else if (comm->redir.writes && comm_write(comm, reset_out) != 0)
			return (2);
		else if (comm->redir.appends && comm_appends(comm, reset_out) != 0)
			return (3);
		else if (comm->redir.heredoc && comm_heredoc(comm, reset_in) != 0)
			return (4);
		comm->redir.ammount--;
	}
	return (0);
}
