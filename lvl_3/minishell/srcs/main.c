/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jibanez- <jibanez-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/15 14:51:49 by dareias-          #+#    #+#             */
/*   Updated: 2022/03/11 14:35:11 by jibanez-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

/*
 * Four main steps:
 * 1 - Initialize the program
 * 2 - Read and parse the command given
 * 3 - Execute given command
 * 4 - Clean and exit
 *
 * Steps 2 & 3 run on a loop
 *
*/

int	main(int argc, char *argv[], char **envp)
{
	t_shell	shell;

	init_shell(&shell, envp);
	(void) argc;
	(void) argv;
	shell.loop = 1;
	while (shell.loop)
	{
		signal(SIGINT, handle_sig);
		signal(SIGQUIT, SIG_IGN);
		get_line(&shell);
		if (shell.line != NULL)
		{
			if (!parse_line(&shell))
				clean_shell(&shell);
		}
		else
			free(shell.prompt);
	}
	if (shell.vars)
		clean_vars(&shell);
	if (shell.envp)
		clean_envp(&shell);
	clear_history();
	return (EXIT_SUCCESS);
}
