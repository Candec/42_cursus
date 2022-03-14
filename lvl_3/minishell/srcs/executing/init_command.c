/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_command.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dareias- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/24 15:40:52 by dareias-          #+#    #+#             */
/*   Updated: 2022/03/10 20:13:39 by dareias-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static void	init_comm_helper(t_comm *comm);
static int	setup_comm_cmd(t_comm *comm, t_ast *ast, int c);
static int	setup_comm_args(t_comm *comm, t_ast *ast, int c, int a);
static int	setup_comm_redirection(t_comm *comm, t_ast *ast);

t_comm	*init_command(t_shell *shell, t_ast *ast)
{
	t_comm	*comm;
	int		c;

	comm = malloc_or_exit(sizeof(t_comm));
	init_comm_helper(comm);
	comm->shell = shell;
	replace_variables(shell, ast, NULL);
	unpack_quotes(ast);
	if (variable_as_cmd(ast))
	{
		comm->e_type = INVALID;
		return (comm);
	}
	c = find_cmd_branch(ast);
	if (!setup_comm_cmd(comm, ast, c))
		return (comm);
	setup_comm_args(comm, ast, c, 0);
	setup_comm_redirection(comm, ast);
	if (comm->redir.ammount < 0)
		return (NULL);
	return (comm);
}

static int	setup_comm_cmd(t_comm *comm, t_ast *ast, int c)
{
	if (find_var_branch(ast) != -1)
	{
		comm->e_type = VAR_DEF;
		set_variable(comm->shell, ast);
		return (0);
	}
	else if (invalid_command(comm, ast, c))
		return (0);
	else
		comm->e_type = COMMAND;
	comm->is_ft = ft_iscomm(ast->branches[c]->my_tok->value);
	comm->cmd = ft_newpath(ast->branches[c]->my_tok->value, comm->shell->envp);
	return (1);
}

static int	setup_comm_args(t_comm *comm, t_ast *ast, int c, int a)
{
	int	ar;
	int	x;

	ar = find_args_branch(ast);
	x = 0;
	while (ar >= 0)
	{
		a += args_ammount(ast->branches[ar % 10]);
		ar = ar / 10;
		if (ar == 0)
			ar = -1;
	}
	if (a > 1)
	{
		x = store_args(comm, ast, a);
		comm->args[x] = NULL;
	}
	else
	{
		comm->args = malloc_or_exit(sizeof(char *) * 2);
		comm->args[0] = ast->branches[c]->my_tok->value;
		comm->args[1] = NULL;
	}
	return (1);
}

static int	setup_comm_redirection(t_comm *comm, t_ast *ast)
{
	int	red;

	red = find_redir_branch(ast);
	while (red >= 0)
	{
		init_comm_redir(comm, ast, red % 10);
		red = red / 10;
		if (red == 0)
			red = -1;
	}
	return (1);
}

static void	init_comm_helper(t_comm *comm)
{
	comm->args = NULL;
	comm->infile = NULL;
	comm->cmd = NULL;
	comm->unsorted_env = NULL;
	comm->outfile = NULL;
	comm->heredoc_word = NULL;
	comm->heredoc_filename = NULL;
	comm->redir.ammount = 0;
	comm->redir.reads = 0;
	comm->redir.writes = 0;
	comm->redir.appends = 0;
	comm->redir.heredoc = 0;
	comm->piping = 0;
	comm->is_ft = 0;
}
