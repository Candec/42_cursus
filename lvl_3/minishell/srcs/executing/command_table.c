/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   command_table.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jibanez- <jibanez-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/24 15:58:18 by dareias-          #+#    #+#             */
/*   Updated: 2022/03/09 16:22:59 by jibanez-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static int	comm_table_pipes(t_shell *shell, t_ast *root);

int	command_table(t_shell *shell, t_ast *root)
{
	int	count;
	int	i;
	int	x;

	count = compound_ammount(root, 0);
	i = 0;
	x = 0;
	shell->commands = malloc(sizeof(t_comm *) * (count + 1));
	if (!shell->commands)
		return (0);
	while (i < count)
	{
		if (root->branches[i + x]->e_type == AST_WORD)
			x++;
		shell->commands[i] = init_command(shell, root->branches[i + x]);
		i++;
	}
	shell->commands[i] = NULL;
	comm_table_pipes(shell, root);
	return (i);
}

static void	set_as_piper(t_shell *shell, int i)
{
	if (shell->commands[i]->piping == 0)
		shell->commands[i]->piping = 2;
	else
		shell->commands[i]->piping = 3;
}

static void	set_as_piped(t_shell *shell, int i)
{
	if (shell->commands[i]->piping == 0)
		shell->commands[i]->piping = 1;
	else
		shell->commands[i]->piping = 3;
}

static int	comm_table_pipes(t_shell *shell, t_ast *root)
{
	int	i;
	int	x;

	i = 0;
	x = 0;
	while (root->branches && root->branches[x])
	{
		if (root->branches[x]->e_type == AST_WORD)
		{
			if (x > 0)
			{
				set_as_piper(shell, i - 1);
			}
			if (shell->commands[i] != NULL)
			{
				set_as_piped(shell, i);
			}
			x++;
		}
		i++;
		x++;
	}
	return (i);
}

int	run_comm_table(t_shell *shell)
{
	int	i;

	i = 0;
	while (shell->commands && shell->commands[i] != NULL)
	{
		if (shell->commands[i]->e_type == VAR_DEF)
		{
			if (shell->debug)
			{
				if (shell->commands[i]->redir.reads)
					printf("%sVariable set%s \n", ft_color(BLU), ft_color(WHT));
				else
					printf("%sW!: variable%s \n", ft_color(RED), ft_color(WHT));
			}
			i++;
		}
		else if (shell->commands[i]->e_type == INVALID)
			i++;
		else
			shell->last_exit = run_command(shell->commands[i++]);
	}
	reset_std_io(shell, 1, 1);
	unlink(".mini.thd");
	return (i);
}
