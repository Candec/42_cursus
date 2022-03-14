/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_shell.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dareias- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/07 22:35:04 by dareias-          #+#    #+#             */
/*   Updated: 2022/03/11 09:31:49 by dareias-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	handle_sig(int sig)
{
	if (sig == SIGINT)
	{
		printf("\n");
		rl_on_new_line();
		rl_replace_line("", 0);
		rl_redisplay();
	}
}

void	termios_init(void)
{
	struct termios	term;

	if (tcgetattr(0, &term) != 0)
		return ;
	term.c_lflag &= ~ECHOCTL;
	if (tcsetattr(0, TCSANOW, &term) != 0)
		return ;
}

void	init_shell(t_shell *shell, char **envp)
{
	shell->loop = 0;
	shell->last_exit = 0;
	shell->envp = dup_envp(envp);
	shell->line = 0;
	shell->debug = 0;
	shell->commands = NULL;
	shell->vars = NULL;
	shell->prompt = NULL;
	shell->par = NULL;
	shell->ast = NULL;
	shell->io.save_in = -1;
	shell->io.save_out = -1;
	shell->io.saved_in = 0;
	shell->io.saved_out = 0;
	shell->io.current_in = STDIN_FILENO;
	shell->io.current_out = STDOUT_FILENO;
	shell->io.my_pipe[0] = -2;
	shell->io.my_pipe[1] = -2;
	termios_init();
}
