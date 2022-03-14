/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   variable_expansion.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jibanez- <jibanez-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/17 15:36:06 by dareias-          #+#    #+#             */
/*   Updated: 2022/03/09 17:25:07 by jibanez-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

char	*var_expand(t_ast *ast)
{
	int	i;

	i = 0;
	while (ast->branches[i] != NULL)
	{
		if (ast->branches[i]->my_tok->e_type == TOK_WORD)
			return (ast->branches[i]->my_tok->value);
		i++;
	}
	return (NULL);
}

void	replace_variables(t_shell *shell, t_ast *ast, t_ast *father)
{
	int		i;
	int		c;
	int		x;
	t_ast	*temp;

	i = 0;
	c = 0;
	x = 1;
	if (ast == NULL)
		return ;
	if (ast->e_type == AST_VAR_EXP)
	{
		temp = init_ast(AST_WORD);
		while (ast->branches[c]->my_tok->e_type != TOK_WORD)
			c++;
		init_token_branch(ast, temp, shell, c);
		if (father)
		{
			while (father->branches[i]->e_type != AST_VAR_EXP)
				i++;
			ast_update(father, temp, i);
			x = 0;
		}
	}
	while_replace_vars(x, ast, shell);
}

char	*ft_variable(t_shell *shell, char *str)
{
	int		where;
	float	var_set;

	if (str && my_strcmp(str, "?") == 0)
		return (ft_strdup(ft_itoa(shell->last_exit)));
	var_set = var_is_set(shell, str);
	where = (int)var_set;
	if (var_set == -1)
		return (NULL);
	if (var_set - (float)where == 0)
		return (ft_strdup(shell->vars[where + 1]));
	return (expansion_from_envp(shell, where));
}

void	ast_update(t_ast *parent, t_ast *child, int up)
{
	int		x;
	int		i;
	t_ast	**tree;

	i = 0;
	while (parent->branches && parent->branches[i] != NULL)
		i++;
	tree = malloc(sizeof(t_ast *) * (i + 1));
	if (!tree)
		return ;
	x = 0;
	while (x++ < i)
	{
		if (x != up)
			tree[x] = parent->branches[x];
		else
			tree[x] = child;
	}
	tree[x] = NULL;
	if (up != -42)
		clean_ast(parent->branches[up]);
	if (parent->branches)
		free(parent->branches);
	parent->branches = tree;
}

int	variable_as_cmd(t_ast *root)
{
	int	i;
	int	x;

	i = 0;
	x = 0;
	while (root->branches[i] != NULL)
	{
		if (root->branches[i]->e_type == AST_WORD)
		{
			x = 1;
			root->branches[i]->e_type = AST_COMMAND;
			break ;
		}
		i++;
	}
	if (root->branches[i] && x == 1)
		if (root->branches[i]->my_tok
			&& root->branches[i]->my_tok->value == NULL)
			return (1);
	return (0);
}
