/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   change_out.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jibanez- <jibanez-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/15 16:39:01 by dareias-          #+#    #+#             */
/*   Updated: 2022/03/09 17:09:57 by jibanez-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	change_out(int old_out_fd, char *new_out, int redir)
{
	int	out;

	out = ft_getfd(new_out, redir);
	if (out == -1)
		return (print_error(FILE_OPEN_FAIL) - 2);
	dup2(out, old_out_fd);
	return (out);
}
