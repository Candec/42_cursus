/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   unpack_quotes_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dareias- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/04 17:35:39 by dareias-          #+#    #+#             */
/*   Updated: 2022/02/04 20:14:54 by dareias-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	dq_expanded_len(char *str)
{
	int	i;
	int	j;
	int	len;

	i = 0;
	len = 0;
	j = 0;
	while (str[i] != '\0')
	{
		if (str[i] == '$')
			break ;
		i++;
	}
	len = i;
	while (str[i] != '\0' && str[i] != ' ')
		i++;
	while (str[i + j] != '\0')
		j++;
	len = len + j;
	return (len);
}
