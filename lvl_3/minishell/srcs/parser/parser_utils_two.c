/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser_utils_two.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dareias- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/09 17:14:04 by dareias-          #+#    #+#             */
/*   Updated: 2022/03/09 17:14:06 by dareias-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	parse_to_ast_core(t_ast *root, t_par *par, int i)
{
	while (par->tok->e_type == TOK_SEMI || par->tok->e_type == TOK_SPACE)
	{
		free(par->tok);
		parser_next(par, 42);
	}
	if (par->tok->e_type == TOK_PIPE)
	{
		ast_add_branch(root, parse_word(par), i++);
		parser_next(par, 42);
	}
	while (par->tok->e_type == TOK_SEMI || par->tok->e_type == TOK_SPACE)
	{
		free(par->tok);
		parser_next(par, 42);
	}
	if (par->tok->e_type != TOK_EOL && par->tok->e_type != TOK_SEMI)
		ast_add_branch(root, parse_compound(par), i++);
	return (i);
}
