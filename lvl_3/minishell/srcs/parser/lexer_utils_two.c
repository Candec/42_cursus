/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lexer_utils_two.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dareias- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/12 18:44:08 by dareias-          #+#    #+#             */
/*   Updated: 2022/03/07 23:07:21 by dareias-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

t_tok	*unclosed_quote(t_lex *lex, int q)
{
	int		i;
	char	*value;

	i = 0;
	i += nextquote(lex, q);
	value = ft_dupnoq(ft_substr(lex->src, lex->i, i));
	if (q == 1)
		return (init_token(value, TOK_WORD));
	else
		return (init_token(value, TOK_DQUOTED));
}

int	lex_get_word_core(t_lex *lex, int *store)
{
	int	i;
	int	q;

	i = 0;
	while (!ft_isforb(lex->c))
	{
		q = ft_isquote(lex->c);
		if (q > 0)
		{
			i++;
			lex_next(lex);
			*store = q;
			q = nextquote(lex, q);
			if (q > 0)
				i += q - 1;
			else if (q < 0)
				return (-1);
		}
		i++;
		lex_next(lex);
	}
	return (i);
}
