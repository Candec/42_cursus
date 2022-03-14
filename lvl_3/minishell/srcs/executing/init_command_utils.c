/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_command_utils.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dareias- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/07 12:25:55 by dareias-          #+#    #+#             */
/*   Updated: 2022/03/05 14:12:40 by dareias-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	init_comm_redir(t_comm *comm, t_ast *ast, int r)
{
	int		i;
	t_ast	*b;

	i = 0;
	b = ast->branches[r];
	while (b->branches[i] != NULL)
	{
		if (b->branches[i]->my_tok->e_type == TOK_SPACE)
			i++;
		if (b->branches[i] == NULL)
			break ;
		if (b->branches[i]->my_tok->e_type == TOK_GT)
			config_writes_redir(comm, b);
		else if (b->branches[i]->my_tok->e_type == TOK_LT)
			config_reads_redir(comm, b);
		else if (b->branches[i]->my_tok->e_type == TOK_ARROW_RIGHT)
			config_appends_redir(comm, b);
		else if (b->branches[i]->my_tok->e_type == TOK_ARROW_LEFT)
			config_heredoc_redir(comm, b);
		i++;
	}
	return (comm->redir.ammount);
}

int	find_redir_branch(t_ast *ast)
{
	int	i;
	int	count;
	int	nor;

	i = 0;
	count = 0;
	nor = -1;
	while (ast->branches[i] != NULL)
	{
		if (ast->branches[i]->e_type == AST_REDIRECT)
		{
			count = i + count * 10;
			nor = 1;
		}
		i++;
	}
	if (nor == -1)
		return (-1);
	count = invert_count(count);
	return (count);
}

int	find_cmd_branch(t_ast *ast)
{
	int	i;

	i = 0;
	while (ast->branches[i] != NULL && ast->branches[i]->e_type != AST_COMMAND)
		i++;
	return (i);
}

int	find_args_branch(t_ast *ast)
{
	int	i;
	int	count;
	int	noa;

	i = 0;
	count = 0;
	noa = -1;
	while (ast->branches[i] != NULL)
	{
		if (ast->branches[i]->e_type == AST_COMM_ARGS)
		{
			count = i + count * 10;
			noa = 1;
		}
		i++;
	}
	if (noa == -1)
		return (noa);
	return (count);
}
