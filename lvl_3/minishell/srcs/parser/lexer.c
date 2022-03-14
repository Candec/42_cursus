/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lexer.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dareias- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/07 22:35:51 by dareias-          #+#    #+#             */
/*   Updated: 2022/03/07 23:04:11 by dareias-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

t_tok	*init_token(char *value, int type)
{
	t_tok	*tok;

	tok = malloc_or_exit(sizeof(t_tok));
	tok->value = value;
	tok->e_type = type;
	return (tok);
}

t_lex	*init_lexer(char *src)
{
	t_lex	*lex;

	lex = malloc_or_exit(sizeof(t_lex));
	lex->i = 0;
	lex->c = src[lex->i];
	lex->src = src;
	lex->size = ft_strlen(src);
	lex->q = 0;
	return (lex);
}

void	lex_next(t_lex *lex)
{
	if (lex->i < lex->size && lex->c != '\0')
	{
		lex->i++;
		lex->c = lex->src[lex->i];
	}
}

t_tok	*lex_get_word(t_lex *lex)
{
	char	*value;
	int		i;
	int		x;
	int		store;

	x = lex->i;
	store = 0;
	i = lex_get_word_core(lex, &store);
	if (i == -1)
	{
		lex_next(lex);
		return (init_token(NULL, TOK_ERROR));
	}
	value = ft_dupnoq(ft_substr(lex->src, x, i));
	if (!value)
	{	
		lex_next(lex);
		return (init_token(NULL, TOK_ERROR));
	}
	if (store == 2)
		return (init_token(value, TOK_DQUOTED));
	return (init_token(value, TOK_WORD));
}

t_tok	*next_token(t_lex *lex)
{
	t_tok	*tok;

	while (lex->c != '\0')
	{
		tok = token_switch(lex->c, lex);
		if (tok)
		{
			lex_next(lex);
			return (tok);
		}
		else
		{
			return (lex_get_word(lex));
		}
	}
	return (init_token(NULL, TOK_EOL));
}
