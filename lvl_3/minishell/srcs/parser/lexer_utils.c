/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lexer_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dareias- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/19 19:12:04 by dareias-          #+#    #+#             */
/*   Updated: 2022/03/07 23:09:09 by dareias-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

t_tok	*token_switch(char c, t_lex *lex)
{
	if (lex->c == ';')
		return (init_token(";", TOK_SEMI));
	if (lex->c == '~')
		return (init_token("~", TOK_TILDE));
	if (lex->c == '|')
		return (init_token("|", TOK_PIPE));
	if (lex->c == '=')
		return (init_token("=", TOK_EQUALS));
	if (lex->c == '\n')
		return (init_token("EOL", TOK_EOL));
	return (token_switch_two(c, lex));
}

t_tok	*token_switch_two(char c, t_lex *lex)
{
	if (c == '<')
	{
		if (lex->src[lex->i + 1] == '<')
		{
			lex_next(lex);
			return (init_token("<<", TOK_ARROW_LEFT));
		}
		return (init_token("<", TOK_LT));
	}
	if (c == '>')
	{
		if (lex->src[lex->i + 1] == '>')
		{
			lex_next(lex);
			return (init_token(">>", TOK_ARROW_RIGHT));
		}
		return (init_token(">", TOK_GT));
	}
	return (token_switch_three(lex));
}

t_tok	*token_switch_three(t_lex *lex)
{
	int	i;

	i = 0;
	while (ft_isspace(lex->c))
	{
		lex_next(lex);
		i++;
	}
	if (i == 0)
		return (NULL);
	lex->i--;
	lex->c = lex->src[lex->i];
	return (init_token(" ", TOK_SPACE));
}

int	nextquote(t_lex *lex, int q)
{
	int	i;

	i = 0;
	lex->c = lex->src[lex->i];
	if (ft_isquote(lex->c) == q)
		return (i);
	while (ft_isquote(lex->c) != q && lex->c != '\0')
	{
		i++;
		lex_next(lex);
	}
	if (lex->c == '\0')
	{
		ft_putstr_fd("minishell: Error: Unclosed quotes\n", 2);
		return (-1);
	}
	return (i);
}
