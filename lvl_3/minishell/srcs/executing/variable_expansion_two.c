/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   variable_expansion_two.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jibanez- <jibanez-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/09 16:58:52 by jibanez-          #+#    #+#             */
/*   Updated: 2022/03/09 17:01:14 by jibanez-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

//move to a file
void	while_replace_vars(int x, t_ast *ast, t_shell *shell)
{
	int	i;

	i = 0;
	while (x && ast->branches && ast->branches[i] != NULL)
		replace_variables(shell, ast->branches[i++], ast);
}

//move to a file
void	init_token_branch(t_ast *ast, t_ast *temp, t_shell *shell, int c)
{
	if (ast->branches[c] != NULL)
		temp->my_tok = init_token(ft_variable(shell,
					ast->branches[c]->my_tok->value), TOK_WORD);
}
