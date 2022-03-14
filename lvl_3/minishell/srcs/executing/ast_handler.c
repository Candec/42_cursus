/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ast_handler.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jibanez- <jibanez-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/24 15:27:56 by dareias-          #+#    #+#             */
/*   Updated: 2022/02/15 18:53:16 by jibanez-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	ast_handler(t_shell *shell, t_ast *root)
{
	int	i;

	i = 0;
	command_table(shell, root);
	i = run_comm_table(shell);
	return (i);
}

int	branch_ammount(t_ast *ast)
{
	int	i;

	i = 0;
	while (ast->branches && ast->branches[i] != NULL)
		i++;
	return (i);
}
