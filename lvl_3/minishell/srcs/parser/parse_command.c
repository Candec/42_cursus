/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_command.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dareias- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/07 18:30:01 by dareias-          #+#    #+#             */
/*   Updated: 2022/03/07 23:14:42 by dareias-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	command_parser(t_ast *ast, t_par *par, unsigned int i, int x)
{
	unsigned int	next;

	if (x != 0)
	{
		ast_add_branch(ast, parse_word(par), i++);
		parser_next(par, 42);
	}
	ast->branches[x]->e_type = AST_COMMAND;
	next = par->tok->e_type;
	if (!command_tok(next))
	{
		ast_add_branch(ast, parse_command(par), i++);
		next = par->tok->e_type;
	}
	while (next != TOK_EOL && next != TOK_SEMI && next != TOK_PIPE)
	{
		if (command_tok(next) == 2)
			ast_add_branch(ast, parse_redirect(par), i++);
		else if (command_tok(next) != 1)
			ast_add_branch(ast, parse_command(par), i++);
		next = par->tok->e_type;
	}
	return (i);
}

t_ast	*parse_command(t_par *par)
{
	t_ast			*ast;
	int				i;
	unsigned int	next;

	i = 0;
	ast = init_ast(AST_COMM_ARGS);
	next = par->tok->e_type;
	while (!command_tok(next))
	{
		ast_add_branch(ast, parse_word(par), i++);
		parser_next(par, 42);
		next = par->tok->e_type;
	}
	return (ast);
}

int	command_tok(unsigned int type)
{
	if (type == TOK_EOL || type == TOK_SEMI || type == TOK_PIPE)
		return (1);
	if (type == TOK_GT || type == TOK_LT
		|| type == TOK_ARROW_RIGHT || type == TOK_ARROW_LEFT)
		return (2);
	return (0);
}
