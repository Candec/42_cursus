/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_variables_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jibanez- <jibanez-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/07 22:42:19 by dareias-          #+#    #+#             */
/*   Updated: 2022/03/09 18:54:57 by jibanez-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	var_already_set(t_shell *shell, char *expands, int where)
{
	safe_free(shell->vars[where + 1]);
	shell->vars[where + 1] = ft_strdup(expands);
	if (!shell->vars[where + 1])
		return (1);
	return (0);
}
