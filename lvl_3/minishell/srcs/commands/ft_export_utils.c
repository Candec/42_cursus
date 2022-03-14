/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_export_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dareias- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/07 22:30:09 by dareias-          #+#    #+#             */
/*   Updated: 2022/03/07 22:30:15 by dareias-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static void	add_all_unsorted(t_comm *ft_comm);

int	build_unsorted_env(t_comm *ft_comm)
{
	int		i;
	int		j;
	int		failed_exp;
	char	**unsorted_env;

	i = 0;
	j = 0;
	failed_exp = 0;
	while (ft_comm->shell->envp && ft_comm->shell->envp[i])
		i++;
	while (ft_comm->shell->vars && (ft_comm->shell->vars[j] || j % 2 != 0))
	{
		if (!ft_comm->shell->vars[j] && j % 2 != 0)
			failed_exp++;
		j++;
	}
	unsorted_env = malloc(sizeof(char *) * (i + failed_exp + 1));
	if (!unsorted_env)
		return (print_error(MEMORY_FAIL));
	unsorted_env[0] = NULL;
	ft_comm->unsorted_env = unsorted_env;
	add_all_unsorted(ft_comm);
	return (i + failed_exp);
}

static void	add_all_unsorted(t_comm *ft_comm)
{
	int	i;
	int	j;
	int	l;

	i = 0;
	j = 0;
	l = 0;
	while (ft_comm->shell->envp[i])
	{
		ft_comm->unsorted_env[l++] = ft_comm->shell->envp[i++];
	}
	while (ft_comm->shell->vars && (ft_comm->shell->vars[j] || j % 2 != 0))
	{
		if (!ft_comm->shell->vars[j])
			ft_comm->unsorted_env[l++] = ft_comm->shell->vars[j - 1];
		j++;
	}
	ft_comm->unsorted_env[l] = NULL;
}
