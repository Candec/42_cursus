/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_envp_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dareias- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/07 22:30:58 by dareias-          #+#    #+#             */
/*   Updated: 2022/03/07 22:31:01 by dareias-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	rm_var(t_shell *shell, char *var, int size)
{
	int		i;
	char	**temp;

	i = 0;
	temp = malloc_or_exit(sizeof(char *) * (size - 1));
	size = 0;
	while (shell->vars[i] != NULL || i % 2 != 0)
	{
		if (ft_strcmp_two(shell->vars[i], var))
		{
			free(shell->vars[i++]);
			if (shell->vars[i++])
				free(shell->vars[i - 1]);
		}
		if (shell->vars[i] || i % 2 != 0)
			temp[size++] = shell->vars[i++];
	}
	temp[size] = NULL;
	if (shell->vars)
		free(shell->vars);
	shell->vars = temp;
	return ;
}

char	**rm_envp_two(char **new, char **envp, int i, int l)
{
	new[l] = NULL;
	if (i == l)
	{
		free(new);
		return (envp);
	}
	free(envp);
	return (new);
}

int	find_next_eq(char *str)
{
	int	i;

	i = 0;
	while (str[i] != '\0')
	{
		if (str[i++] == '=')
			break ;
	}
	return (i);
}
