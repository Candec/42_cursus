/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ast.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dareias- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/22 10:29:40 by dareias-          #+#    #+#             */
/*   Updated: 2022/03/07 23:06:58 by dareias-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

t_ast	*init_ast(int type)
{
	t_ast	*ast;

	ast = malloc_or_exit(sizeof(t_ast));
	ast->e_type = type;
	ast->my_tok = NULL;
	ast->branches = NULL;
	return (ast);
}

void	ast_add_branch(t_ast *parent, t_ast *child, int i)
{
	int		x;
	t_ast	**tree;

	tree = malloc_or_exit(sizeof(t_ast *) * (i + 2));
	x = 0;
	while (x < i)
	{
		tree[x] = parent->branches[x];
		x++;
	}
	tree[x++] = child;
	tree[x] = NULL;
	safe_free(parent->branches);
	parent->branches = tree;
}

void	ast_add_branch_idx(t_ast *parent, t_ast *child, int i, int idx)
{
	int		x;
	int		y;
	t_ast	**tree;

	if (idx > i)
		return ;
	tree = malloc_or_exit(sizeof(t_ast *) * (i + 2));
	x = 0;
	y = 0;
	while (x <= i)
	{
		if (x == idx)
			tree[x++] = child;
		else
		{
			tree[x] = parent->branches[y];
			x++;
			y++;
		}
	}
	tree[x] = NULL;
	safe_free(parent->branches);
	parent->branches = tree;
}

int	ast_branch_ammount(t_ast *ast)
{
	int	i;

	i = 0;
	while (ast && ast->branches && ast->branches[i] != NULL)
		i++;
	return (i);
}
