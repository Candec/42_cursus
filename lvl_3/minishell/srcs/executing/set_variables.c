/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_variables.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dareias- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/17 16:24:28 by dareias-          #+#    #+#             */
/*   Updated: 2022/03/05 19:44:25 by dareias-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static int	create_vars_table(t_shell *shell, char *var, char *expands)
{
	shell->vars = malloc_or_exit(sizeof(char *) * 3);
	shell->vars[0] = ft_strdup(var);
	if (!expands)
		shell->vars[1] = NULL;
	else
		shell->vars[1] = ft_strdup(expands);
	shell->vars[2] = NULL;
	return (1);
}

int	add_variable(t_shell *shell, char *var, char *expands)
{
	char	**temp;
	int		i;

	i = 0;
	if (!shell->vars)
		return (create_vars_table(shell, var, expands));
	while (shell->vars[i] != NULL || i % 2 != 0)
		i++;
	temp = malloc_or_exit(sizeof(char *) * (i + 3));
	i = 0;
	while (shell->vars[i] != NULL || i % 2 != 0)
	{
		temp[i] = shell->vars[i];
		i++;
	}
	temp[i++] = ft_strdup(var);
	if (!expands)
		temp[i++] = NULL;
	else
		temp[i++] = ft_strdup(expands);
	temp[i] = NULL;
	safe_free(shell->vars);
	shell->vars = temp;
	return (1);
}

int	set_variable(t_shell *shell, t_ast *ast)
{
	int		var;
	int		var_def;
	float	var_set;
	char	*variable;
	char	*variable_def;

	var = find_var_branch(ast);
	var_def = var + 1;
	variable = ast->branches[var]->my_tok->value;
	variable_def = ast->branches[var_def]->branches[1]->my_tok->value;
	var_set = var_is_set(shell, variable);
	if (var_set > -1)
		return (update_var(shell, variable, variable_def, var_set));
	return (add_variable(shell, variable, variable_def));
}

int	update_var(t_shell *shell, char *var, char *expands, float var_set)
{
	char	*new_env;
	char	*temp;
	int		where;

	new_env = NULL;
	temp = NULL;
	where = (int)var_set;
	if (var_set - (float)where == 0)
		var_already_set(shell, expands, where);
	temp = ft_strcat(var, "=");
	if (!temp)
		return (1);
	new_env = ft_strcat(temp, expands);
	if (!new_env)
	{
		free(temp);
		return (1);
	}
	shell->envp[where] = new_env;
	free(temp);
	return (0);
}

int	find_var_branch(t_ast *ast)
{
	int	i;
	int	novar;

	i = 0;
	novar = -1;
	while (ast->branches[i] != NULL)
	{
		if (ast->branches[i]->e_type == AST_VARIABLE)
		{
			novar = 1;
			break ;
		}
		i++;
	}
	if (novar == -1)
		return (novar);
	return (i);
}
