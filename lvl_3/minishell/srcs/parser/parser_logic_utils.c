/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser_logic_utils.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dareias- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/26 16:00:11 by dareias-          #+#    #+#             */
/*   Updated: 2022/03/07 22:48:26 by dareias-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

t_ast	*parse_compound_core(t_ast *ast, t_par *par, int i, int x)
{
	if (command_tok(par->next) == 2)
	{
		while (command_tok(par->next) == 2)
		{
			x++;
			ast_add_branch(ast, parse_redirect(par), i++);
		}
	}
	else if (par->next != TOK_EOL && par->next != TOK_SEMI)
	{
		ast_add_branch(ast, parse_word(par), i++);
		parser_next(par, 42);
	}
	return (parse_compound_two(par, ast, i, x));
}
