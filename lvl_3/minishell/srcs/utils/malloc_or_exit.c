/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   malloc_or_exit.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dareias- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/07 22:37:06 by dareias-          #+#    #+#             */
/*   Updated: 2022/03/07 22:37:09 by dareias-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	*malloc_or_exit(size_t size)
{
	void	*ret;

	ret = malloc(size);
	if (!ret)
	{
		exit (print_error(MEMORY_FAIL));
	}
	return (ret);
}
