/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_pipes.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jibanez- <jibanez-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/17 16:36:13 by dareias-          #+#    #+#             */
/*   Updated: 2022/03/09 18:55:25 by jibanez-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

/*
 *
 * We read from comm->shell->io.my_pipe[0] and 
 * write to comm->shell->io.my_pipe[1]
 * if comm->is_ft then the fds we have are not duplicated
 * 
*/

static int	getting_piped(t_comm *comm);
static int	piping(t_comm *comm);
static int	getting_piped_and_piping(t_comm *comm);

int	set_pipes(t_comm *comm)
{
	if (comm->piping == 1)
		return (getting_piped(comm));
	else if (comm->piping == 2)
		return (piping(comm));
	else if (comm->piping == 3)
		return (getting_piped_and_piping(comm));
	return (0);
}

static int	getting_piped(t_comm *comm)
{
	if (comm->shell->io.current_in != STDIN_FILENO)
		close(comm->shell->io.current_in);
	if (dup2(comm->shell->io.my_pipe[0], STDIN_FILENO) < 0)
		return (print_error(IN_N_OUT_FAIL));
	comm->shell->io.current_in = comm->shell->io.my_pipe[0];
	return (0);
}

static int	piping(t_comm *comm)
{
	if (comm->shell->io.current_out != STDOUT_FILENO)
		close(comm->shell->io.current_out);
	if (pipe(comm->shell->io.my_pipe) < 0)
		return (print_error(IN_N_OUT_FAIL));
	if (dup2(comm->shell->io.my_pipe[1], STDOUT_FILENO) < 0)
		return (print_error(IN_N_OUT_FAIL));
	comm->shell->io.current_out = comm->shell->io.my_pipe[1];
	return (0);
}

static int	getting_piped_and_piping(t_comm *comm)
{
	if (comm->shell->io.current_in != STDIN_FILENO)
		close(comm->shell->io.current_in);
	if (comm->shell->io.current_out != STDOUT_FILENO)
		close(comm->shell->io.current_out);
	if (dup2(comm->shell->io.my_pipe[0], STDIN_FILENO) < 0)
		return (print_error(IN_N_OUT_FAIL));
	comm->shell->io.current_in = comm->shell->io.my_pipe[0];
	if (pipe(comm->shell->io.my_pipe) < 0)
		return (print_error(IN_N_OUT_FAIL));
	if (dup2(comm->shell->io.my_pipe[1], STDOUT_FILENO) < 0)
		return (print_error(IN_N_OUT_FAIL));
	comm->shell->io.current_out = comm->shell->io.my_pipe[1];
	return (0);
}
