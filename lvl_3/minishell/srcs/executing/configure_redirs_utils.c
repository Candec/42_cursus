/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   configure_redirs_utils.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jibanez- <jibanez-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/09 16:23:25 by jibanez-          #+#    #+#             */
/*   Updated: 2022/03/09 16:23:33 by jibanez-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	create_if_needed(char *filename, int mode)
{
	int	i;

	if (filename)
	{
		i = ft_getfd(filename, mode);
		if (i >= 0)
			close(i);
	}
}
