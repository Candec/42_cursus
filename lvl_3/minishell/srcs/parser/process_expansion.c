/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   process_expansion.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jibanez- <jibanez-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/09 17:14:56 by dareias-          #+#    #+#             */
/*   Updated: 2022/03/09 18:54:55 by jibanez-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	expand(t_shell *shell, char **exp)
{
	char	*temp;

	temp = ft_variable(shell, *exp);
	safe_free(*exp);
	*exp = temp;
}

char	*remove_old(char *s, int where)
{
	char	*temp;
	int		i;
	int		j;

	i = 0;
	j = 0;
	while (exp_valid_format(s, (where + 1) + i))
		i++;
	if (!s)
		return (NULL);
	temp = malloc_or_exit(sizeof(char) * (ft_strlen(s) - i));
	while (s[j] != '\0' && j < where)
	{
		temp[j] = s[j];
		j++;
	}
	while (s[j + i + 1] != '\0')
	{
		temp[j] = s[j + i + 1];
		j++;
	}
	temp[j] = '\0';
	safe_free(s);
	return (temp);
}
