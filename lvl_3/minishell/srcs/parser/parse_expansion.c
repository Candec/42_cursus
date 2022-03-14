/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_expansion.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dareias- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/17 15:13:37 by dareias-          #+#    #+#             */
/*   Updated: 2022/03/07 23:17:40 by dareias-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

t_ast	*parse_var_exp(t_par *par);

t_ast	*parse_expansion(t_par *par)
{
	t_ast			*ast;
	int				i;

	i = 0;
	ast = init_ast(AST_VAR_EXP);
	ast_add_branch(ast, parse_var_exp(par), i++);
	parser_next(par, 42);
	if (command_tok(par->next) == 1)
		return (ast);
	ast_add_branch(ast, parse_var_exp(par), i++);
	parser_next(par, 42);
	return (ast);
}

t_ast	*parse_var_exp(t_par *par)
{
	t_ast	*ast;

	ast = init_ast(AST_WORD);
	ast->branches = NULL;
	ast->my_tok = par->tok;
	return (ast);
}

int	parse_exp_status(t_par *par)
{
	t_lex			lex_temp;
	t_par			par_temp;
	unsigned int	next;

	lex_temp.src = par->lex->src;
	lex_temp.size = ft_strlen(lex_temp.src);
	lex_temp.i = par->lex->i;
	lex_temp.c = par->lex->c;
	lex_temp.q = par->lex->q;
	par_temp.lex = &lex_temp;
	parser_next(&par_temp, 42);
	next = par_temp.tok->e_type;
	free(par_temp.tok);
	if (command_tok(next) == 1)
		return (1);
	return (0);
}
