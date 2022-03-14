/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   clean_shell.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dareias- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/18 19:42:07 by dareias-          #+#    #+#             */
/*   Updated: 2022/03/05 19:44:25 by dareias-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

/*
*	What mallocs do we have?
*	1 For the command table
*	1 for each command
*	1 for each substr "comm.cmd"
*	1 for shell line
*/

// static int	clean_args(t_comm *comm);

static void	free_cmd(t_comm *comm);

int	clean_shell(t_shell *shell)
{
	int	i;

	i = 0;
	if (shell->ast)
		clean_ast(shell->ast);
	if (shell->par)
		clean_parser(shell->par);
	while (shell->commands && shell->commands[i] != NULL)
	{
		free_cmd(shell->commands[i]);
		free(shell->commands[i]);
		i++;
	}
	if (shell->commands)
		free(shell->commands);
	return (i);
}

int	clean_vars(t_shell *shell)
{
	int	i;

	i = 0;
	while (shell->vars && (shell->vars[i] != NULL || i % 2 != 0))
	{
		if (shell->vars[i])
			free(shell->vars[i]);
		i++;
	}
	if (shell->vars)
		free(shell->vars);
	return (i);
}

int	clean_envp(t_shell *shell)
{
	int	i;

	i = 0;
	while (shell->envp && shell->envp[i])
		free(shell->envp[i++]);
	if (shell->envp)
		free(shell->envp);
	return (i);
}

static void	free_cmd(t_comm *comm)
{
	if (comm->cmd)
		free(comm->cmd);
	if (comm->infile)
		free(comm->infile);
	if (comm->outfile)
		free(comm->outfile);
	if (comm->heredoc_filename)
		free(comm->heredoc_filename);
	if (comm->heredoc_word)
		free (comm->heredoc_word);
	if (comm->args)
		free (comm->args);
}
