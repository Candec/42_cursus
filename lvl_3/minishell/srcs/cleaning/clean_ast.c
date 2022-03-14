/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   clean_ast.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jibanez- <jibanez-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/26 12:55:17 by dareias-          #+#    #+#             */
/*   Updated: 2022/02/15 18:20:31 by jibanez-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

/*
 *
 * When freeing tokens: make sure we free every single one 
 * that we dont use (while parsing)!
 * free the ones that we do;
 *
 */

int	clean_ast(t_ast *ast)
{
	int	i;

	i = 0;
	if (!ast)
		return (0);
	while (ast->branches && ast->branches[i] != NULL)
		clean_ast(ast->branches[i++]);
	if (ast->branches)
		free(ast->branches);
	if (ast->my_tok)
		clean_tok(ast->my_tok);
	if (ast)
		free(ast);
	return (i);
}

int	clean_parser(t_par *par)
{
	int	i;

	i = 0;
	i = clean_lexer(par->lex);
	free(par);
	return (i);
}

int	clean_lexer(t_lex *lex)
{
	free(lex);
	return (1);
}

int	clean_tok(t_tok *tok)
{
	if (tok->e_type == TOK_WORD)
		free(tok->value);
	free(tok);
	return (1);
}
