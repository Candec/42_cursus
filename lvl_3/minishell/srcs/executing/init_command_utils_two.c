/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_command_utils_two.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dareias- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/20 12:18:30 by dareias-          #+#    #+#             */
/*   Updated: 2022/03/10 20:11:04 by dareias-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

// For better organization of init command
int	invalid_command(t_comm *comm, t_ast *ast, int c)
{
	if (!ast->branches[c] || !ast->branches[c]->my_tok)
	{
		comm->e_type = INVALID;
		return (1);
	}
	return (0);
}

int	invert_count(int count)
{
	int	ret;

	ret = 0;
	while (count >= 0)
	{
		ret = ret * 10 + (count % 10);
		count = count / 10;
		if (count == 0)
			count = -1;
	}
	return (ret);
}
