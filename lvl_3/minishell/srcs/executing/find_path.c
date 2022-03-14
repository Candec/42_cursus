/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   find_path.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dareias- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/15 16:16:21 by dareias-          #+#    #+#             */
/*   Updated: 2022/03/11 08:44:17 by dareias-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
 *
 * Given an array of possible paths we find the full path to be given to execve
 *
*/

#include "minishell.h"

static void	path_freer(char **path);

char	*ft_findpath(char **envp)
{
	int	i;

	i = 0;
	if (!envp || !envp[i])
		return (NULL);
	while (ft_strcmp(envp[i], "PATH", 4) == 0 && envp[i])
		i++;
	if (!envp[i])
		return (NULL);
	return (envp[i] + 5);
}

char	*ft_newpath(char *cmd, char **envp)
{
	int		i;
	char	**path;
	char	*full_cmd;

	i = 0;
	if (!cmd || cmd[0] == '\0')
		return (NULL);
	if (access(cmd, X_OK) == 0)
		return (ft_strdup(cmd));
	path = ft_split(ft_findpath(envp), ':');
	while (path && path[i] != NULL)
	{
		full_cmd = ft_append(path[i], cmd);
		if (access(full_cmd, X_OK) == 0)
		{
			path_freer(path);
			return (full_cmd);
		}
		free(full_cmd);
		i++;
	}
	path_freer(path);
	return (NULL);
}

static void	path_freer(char **path)
{
	int	i;

	i = 0;
	if (!path)
		return ;
	while (path[i] != NULL)
	{
		if (path[i])
			free(path[i]);
		i++;
	}
	free(path);
	return ;
}
