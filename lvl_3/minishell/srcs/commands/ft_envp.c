/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_envp.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dareias- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/20 18:16:14 by dareias-          #+#    #+#             */
/*   Updated: 2022/03/05 19:55:07 by dareias-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

char	**add_envp(char **envp, char *add)
{
	int		i;
	char	**new;

	i = 0;
	while (envp[i])
		i++;
	new = malloc_or_exit(sizeof(char *) * (i + 2));
	i = 0;
	while (envp[i])
	{
		new[i] = envp[i];
		i++;
	}
	new[i++] = add;
	new[i] = NULL;
	free(envp);
	return (new);
}

char	**rm_envp(char **envp, char *rm, int i, int l)
{
	int		j;
	int		found;
	char	**new;

	if (!envp || !envp[0])
		return (NULL);
	j = nta_size(envp);
	new = malloc_or_exit(sizeof(char *) * (j));
	found = 0;
	while (i < j && envp[i])
	{
		if (!found && ft_strcmp_two(rm, envp[i]))
		{
			safe_free(envp[i]);
			found = ++i;
		}
		if (!envp[i])
			break ;
		new[l++] = envp[i++];
	}
	return (rm_envp_two(new, envp, i, l));
}

char	*whole_var_from_vars(char **vars, char *var)
{
	int		i;
	char	*temp;
	char	*final;

	i = 0;
	if (!vars || !vars[0])
		return (NULL);
	while (vars[i])
	{
		if (ft_strcmp_two(vars[i], var))
			break ;
		i = i + 2;
	}
	if (!vars[i])
		return (NULL);
	if (!vars[i + 1])
		return (NULL);
	temp = ft_strcat(vars[i], "=");
	final = ft_strcat(temp, vars[i + 1]);
	free(temp);
	return (final);
}

void	rm_var_from_vars(t_shell *shell, char *var)
{
	int		i;
	int		size;
	int		var_set;

	i = 0;
	size = 0;
	var_set = 0;
	if (!shell->vars || !shell->vars[i])
		return ;
	while (shell->vars[size] != NULL || size % 2 != 0)
		size++;
	if (size == 0)
		return ;
	while (shell->vars[i] != NULL || i % 2 != 0)
	{
		if (ft_strcmp_two(shell->vars[i], var))
			var_set = 1;
		i++;
	}
	if (!var_set)
		return ;
	rm_var(shell, var, size);
}

int	change_envp(char **envp, int where, char *new_val)
{
	int		i;
	int		j;
	char	*new_env;

	i = 0;
	j = 0;
	if (!envp[where])
		return (1);
	i = find_next_eq(envp[where]);
	new_env = malloc_or_exit(sizeof(char) * (i + ft_strlen(new_val) + 1));
	while (j < i)
	{
		new_env[j] = envp[where][j];
		j++;
	}
	j = 0;
	while (new_val[j] != '\0')
	{
		new_env[i++] = new_val[j++];
	}
	new_env[i] = '\0';
	return (0);
}
