/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_command_utils_three.c                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jibanez- <jibanez-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/07 22:40:15 by dareias-          #+#    #+#             */
/*   Updated: 2022/03/10 10:49:05 by jibanez-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static int	store_args_core(t_comm *comm, t_ast *ast, int x, int ar);

int	args_ammount(t_ast *command)
{
	int	i;
	int	count;

	i = 0;
	count = 0;
	while (command && command->branches && command->branches[i] != NULL)
	{
		if (command->branches[i]->my_tok->e_type == TOK_WORD
			|| command->branches[i]->my_tok->e_type == TOK_EQUALS)
			if (command->branches[i]->my_tok->value != NULL)
				count++;
		i++;
	}
	return (count + 1);
}

int	compound_ammount(t_ast *root, int count)
{
	int	i;

	i = 0;
	while (root && root->branches && root->branches[i] != NULL)
	{
		count = compound_ammount(root->branches[i], count);
		if (root->branches[i]->e_type == AST_COMPOUND)
			count++;
		i++;
	}
	return (count);
}

int	store_args(t_comm *comm, t_ast *ast, int a)
{
	int	x;
	int	ar;

	x = 0;
	ar = find_args_branch(ast);
	comm->args = malloc_or_exit(sizeof(char *) * (a + 1));
	comm->args[x++] = ast->branches[find_cmd_branch(ast)]->my_tok->value;
	x = store_args_core(comm, ast, x, ar);
	return (x);
}

static int	ft_ar_calculation(int ar)
{
	ar = ar / 10;
	if (ar == 0)
		ar = -1;
	return (ar);
}

static int	store_args_core(t_comm *comm, t_ast *ast, int x, int ar)
{
	int	i;

	i = 0;
	while (ar >= 0)
	{
		while (ast->branches[ar % 10]->branches[i] != NULL)
		{
			if (ast->branches[ar % 10]->branches[i]
				->my_tok->e_type == TOK_SPACE)
				i++;
			else if (ast->branches[ar % 10]
				->branches[i]->e_type == AST_VAR_EXP)
				comm->args[x++] = var_expand(ast->branches[ar % 10]
						->branches[i++]);
			else if (ast->branches[ar % 10]->branches[i]->my_tok->value != NULL)
					comm->args[x++] = ast->branches[ar % 10]
					->branches[i++]->my_tok->value;
			else
				i++;
		}
		ar = ft_ar_calculation(ar);
	}
	return (x);
}
