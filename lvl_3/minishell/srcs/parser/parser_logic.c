/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser_logic.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dareias- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/24 10:58:17 by dareias-          #+#    #+#             */
/*   Updated: 2022/03/07 23:42:40 by dareias-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static int		var_parse(t_ast *ast, t_par *par, int *i);

t_ast	*parse_compound(t_par *par)
{
	t_ast			*ast;
	int				i;
	int				x;

	i = 0;
	x = 0;
	ast = init_ast(AST_COMPOUND);
	if (par->next == TOK_DOLLAR && !parse_exp_status(par))
	{
		ast_add_branch(ast, parse_expansion(par), i++);
		x++;
	}
	return (parse_compound_core(ast, par, i, x));
}

t_ast	*parse_compound_two(t_par *par, t_ast *ast, int i, int x)
{
	if (par->next == TOK_EQUALS)
		if (!var_parse(ast, par, &i))
			return (ast);
	if (par->next == TOK_SEMI || par->next == TOK_EOL)
	{
		if (i == 1 && ast->branches[0]->e_type != AST_VAR_EXP)
			ast->branches[0]->e_type = AST_COMMAND;
		return (ast);
	}
	else
	{
		i += command_parser(ast, par, i, x);
		return (ast);
	}
	return (ast);
}

static int	var_parse(t_ast *ast, t_par *par, int *i)
{
	ast->branches[0]->e_type = AST_VARIABLE;
	ast_add_branch(ast, parse_variable(par), *i++);
	if (par->next == TOK_SPACE)
	{
		free(par->tok);
		parser_next(par, 42);
	}
	if (par->next == TOK_SEMI || par->next == TOK_EOL)
		return (0);
	return (1);
}

t_ast	*parse_redirect(t_par *par)
{
	t_ast			*ast;
	int				i;
	unsigned int	next;

	ast = init_ast(AST_REDIRECT);
	i = 0;
	next = par->tok->e_type;
	ast_add_branch(ast, parse_word(par), i++);
	parser_next(par, 42);
	next = par->tok->e_type;
	if (next == TOK_SPACE)
	{
		ast_add_branch(ast, parse_word(par), i++);
		parser_next(par, 42);
		next = par->tok->e_type;
	}
	ast_add_branch(ast, parse_word(par), i++);
	parser_next(par, 42);
	next = par->tok->e_type;
	if (next == TOK_SPACE)
	{
		ast_add_branch(ast, parse_word(par), i++);
		parser_next(par, 42);
	}
	return (ast);
}
