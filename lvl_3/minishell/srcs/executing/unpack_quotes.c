/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   unpack_quotes.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jibanez- <jibanez-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/20 16:03:09 by dareias-          #+#    #+#             */
/*   Updated: 2022/03/10 10:53:55 by jibanez-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	unpack_quotes(t_ast *ast)
{
	int	i;
	int	ret;

	i = 0;
	ret = 0;
	while (ast && ast->branches && ast->branches[i] != NULL)
	{
		unpack_quotes(ast->branches[i]);
		if (ast->branches[i]->my_tok
			&& ast->branches[i]->my_tok->e_type == TOK_DQUOTED)
			ret += expand_quote(ast, i);
		i++;
	}
	return (ret);
}

int	expand_quote(t_ast *father, int i)
{
	int		j;
	t_ast	*son;
	char	*value;

	j = 0;
	son = father->branches[i];
	value = son->my_tok->value;
	while (value[j] != '\0')
	{
		if (value[j] == '$')
			break ;
		j++;
	}
	return (no_exp_needed(son, value));
}

// exp stands for expansion

int	no_exp_needed(t_ast *son, char *value)
{
	t_tok	*temp;

	temp = init_token(value, TOK_WORD);
	clean_tok(son->my_tok);
	son->my_tok = temp;
	return (1);
}
