/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_unset.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jibanez- <jibanez-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/20 18:58:00 by dareias-          #+#    #+#             */
/*   Updated: 2022/02/15 18:44:22 by jibanez-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	ft_unset(t_comm *ft_comm)
{
	float	var_set;
	int		where;
	int		i;
	t_shell	*sh;

	i = 1;
	sh = ft_comm->shell;
	if (!ft_comm->args[i])
		return (1);
	while (ft_comm->args[i])
	{
		var_set = var_is_set(sh, ft_comm->args[i]);
		where = (int)var_set;
		if (var_set > -1 && var_set - (float)where == 0)
			rm_var_from_vars(sh, ft_comm->args[i]);
		else if (var_set > -1)
		{
			sh->envp = rm_envp(sh->envp, sh->envp[where], 0, 0);
			rm_var_from_vars(sh, ft_comm->args[i]);
		}
		i++;
	}
	return (0);
}
