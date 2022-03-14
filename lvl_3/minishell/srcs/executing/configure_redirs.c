/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   configure_redirs.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dareias- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/07 22:39:32 by dareias-          #+#    #+#             */
/*   Updated: 2022/03/07 22:39:34 by dareias-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static int	redir_expansion(t_comm *comm, t_ast *b);

void	config_writes_redir(t_comm *comm, t_ast *b)
{
	int	i;

	i = 0;
	comm->redir.writes = 1;
	comm->redir.write_ammount++;
	comm->redir.ammount++;
	i = redir_expansion(comm, b);
	if (i < 0)
		return ;
	safe_free(comm->outfile);
	comm->outfile = ft_strdup(b->branches[i]->my_tok->value);
	create_if_needed(comm->outfile, comm->redir.writes);
}

void	config_reads_redir(t_comm *comm, t_ast *b)
{
	int	i;

	i = 0;
	comm->redir.reads = 2;
	comm->redir.read_ammount++;
	comm->redir.ammount++;
	i = redir_expansion(comm, b);
	if (i < 0)
		return ;
	safe_free(comm->infile);
	comm->infile = ft_strdup(b->branches[i]->my_tok->value);
}

void	config_appends_redir(t_comm *comm, t_ast *b)
{
	int	i;

	i = 0;
	comm->redir.appends = 3;
	comm->redir.append_ammount++;
	comm->redir.ammount++;
	i = redir_expansion(comm, b);
	if (i < 0)
		return ;
	safe_free(comm->outfile);
	comm->outfile = ft_strdup(b->branches[i]->my_tok->value);
	create_if_needed(comm->outfile, comm->redir.appends);
}

void	config_heredoc_redir(t_comm *comm, t_ast *b)
{
	int	i;

	i = 0;
	comm->redir.heredoc = 4;
	comm->redir.heredoc_ammount++;
	comm->redir.ammount++;
	i = redir_expansion(comm, b);
	if (i < 0)
		return ;
	safe_free(comm->heredoc_word);
	comm->heredoc_word = ft_strdup(b->branches[i]->my_tok->value);
	safe_free(comm->heredoc_filename);
	comm->heredoc_filename = ft_heredoc(comm);
}

static int	redir_expansion(t_comm *comm, t_ast *b)
{
	int	i;

	i = 0;
	while (b->branches[i] && b->branches[i]->my_tok->e_type != TOK_WORD)
		i++;
	if (!b->branches[i])
	{
		comm->redir.ammount = -1;
		return (-1);
	}
	return (i);
}
