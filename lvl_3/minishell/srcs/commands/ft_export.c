/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_export.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jibanez- <jibanez-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/20 14:38:27 by dareias-          #+#    #+#             */
/*   Updated: 2022/03/09 18:53:40 by jibanez-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static void	print_sorted_export(char **sorted_env);

int	ft_export(t_comm *ft_comm)
{
	float	var_set;
	int		where;
	int		i;
	int		save;

	i = 1;
	if (!ft_comm->args[1])
		return (ft_print_export(ft_comm));
	while (ft_comm->args[i])
	{
		var_set = var_is_set(ft_comm->shell, ft_comm->args[i]);
		where = (int)var_set;
		save = i;
		if (var_set == -1.0)
			i = set_new_var(ft_comm, i, save);
		else if (var_set - (float)where != 0.1)
			i = reset_var_vars(ft_comm, i, var_set);
		else
			i = reset_var_envp(ft_comm, i, var_set);
	}
	return (0);
}

int	ft_print_export(t_comm *ft_comm)
{
	int		sorted;
	int		next;
	char	**sorted_env;
	int		env_ammount;

	env_ammount = build_unsorted_env(ft_comm);
	sorted_env = malloc(sizeof(char *) * (env_ammount + 1));
	if (!sorted_env)
		return (print_error(MEMORY_FAIL));
	sorted_env[0] = NULL;
	sorted = 0;
	while (sorted < env_ammount)
	{
		next = get_next_lowest_env(sorted_env, ft_comm->unsorted_env);
		if (next == -1)
			break ;
		sorted_env[sorted++] = ft_comm->unsorted_env[next];
		sorted_env[sorted] = NULL;
	}
	sorted_env[sorted] = NULL;
	print_sorted_export(sorted_env);
	free(sorted_env);
	free(ft_comm->unsorted_env);
	return (0);
}

int	env_in_sorted(char **sorted_env, char *env)
{
	int	i;

	i = 0;
	while (sorted_env[i])
	{
		if (my_strcmp(sorted_env[i], env) == 0)
			return (1);
		i++;
	}
	return (0);
}

static void	print_sorted_export(char **sorted_env)
{
	int	i;
	int	j;

	i = 0;
	while (sorted_env[i])
	{
		printf("declare -x ");
		j = 0;
		while (sorted_env[i][j] != '=' && sorted_env[i][j] != '\0')
			printf("%c", sorted_env[i][j++]);
		if (sorted_env[i][j] == '\0')
		{
			i++;
			printf("\n");
			continue ;
		}
		printf("%c", sorted_env[i][j++]);
		printf("\"");
		while (sorted_env[i][j] != '\0')
			printf("%c", sorted_env[i][j++]);
		printf("\"\n");
		i++;
	}
}

int	get_next_lowest_env(char **sorted_env, char **unsorted)
{
	int	i;
	int	lowest;

	i = 0;
	while (unsorted[i])
	{
		if (env_in_sorted(sorted_env, unsorted[i]))
		{
			i++;
			continue ;
		}
		lowest = is_it_lowest(sorted_env, unsorted, i);
		if (lowest)
			return (i);
		i++;
	}
	return (-1);
}
