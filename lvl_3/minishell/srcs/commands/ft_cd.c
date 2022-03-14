/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_cd.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jibanez- <jibanez-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/15 15:25:46 by dareias-          #+#    #+#             */
/*   Updated: 2022/02/15 18:24:55 by jibanez-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static void	update_pwd(t_shell *shell);

int	ft_cd(t_comm *ft_comm)
{
	int	i;

	i = chdir(ft_comm->args[1]);
	if (i == -1)
		perror("Minishell: ");
	update_pwd(ft_comm->shell);
	return (i);
}

static void	update_pwd(t_shell *shell)
{
	char	*pwd;
	char	*temp;
	int		i;

	i = 0;
	if (!shell->envp || !shell->envp[i])
		return ;
	while (shell->envp[i] && ft_strcmp(shell->envp[i], "PWD", 3) == 0)
		i++;
	temp = getcwd(NULL, 0);
	if (!temp)
		return ;
	pwd = ft_strjoin("PWD=", temp);
	free(temp);
	if (!shell->envp[i])
		shell->envp = add_envp(shell->envp, pwd);
	else
	{
		free(shell->envp[i]);
		shell->envp[i] = pwd;
	}
}
