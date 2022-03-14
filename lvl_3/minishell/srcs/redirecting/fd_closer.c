/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fd_closer.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dareias- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/17 17:02:26 by dareias-          #+#    #+#             */
/*   Updated: 2021/11/17 17:30:23 by dareias-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static int	close_fds(t_comm *comm)
{
	if (comm->shell->io.current_in != STDIN_FILENO)
		close(comm->shell->io.current_in);
	if (comm->shell->io.current_out != STDOUT_FILENO)
		close(comm->shell->io.current_out);
	return (0);
}

int	fd_closer(t_comm *comm)
{
	if (close_fds(comm))
		return (1);
	return (0);
}
