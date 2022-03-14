/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   comm_printer.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dareias- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/06 16:43:39 by dareias-          #+#    #+#             */
/*   Updated: 2022/01/10 18:10:14 by dareias-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	comm_printer(t_comm *comm)
{
	int	i;

	i = 0;
	fprintf(stderr, "%s", ft_color(YEL));
	fprintf(stderr, "\nCOMMAND: %s\n", comm->cmd);
	while (comm->args && comm->args[i] != NULL)
	{
		fprintf(stderr, "ARG[%i]: %s\n", i, comm->args[i]);
		i++;
	}
	fprintf(stderr, "PIPING: %i\n", comm->piping);
	fprintf(stderr, "IN: %s(%i)\nOUT: %s(%i)\n", comm->infile,
		comm->shell->io.current_in, comm->outfile, comm->shell->io.current_out);
	fprintf(stderr, "PIPE[0]: (%i)\nPIPE[1]: (%i)\n", comm->shell->io.my_pipe[0],
		comm->shell->io.my_pipe[1]);
	fprintf(stderr, "IS_FT: (%i)\n", comm->is_ft);
	fprintf(stderr, "%s\n", ft_color(WHT));
}
