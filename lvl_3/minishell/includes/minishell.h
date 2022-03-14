/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jibanez- <jibanez-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/15 14:52:23 by dareias-          #+#    #+#             */
/*   Updated: 2022/03/09 18:52:53 by jibanez-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINISHELL_H
# define MINISHELL_H

# ifdef unix
#  define IS_LINUX 1
#  define MAX_PATH 4096
# else
#  define IS_LINUX 0
#  define MAX_PATH 1024
# endif

# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>
# include <fcntl.h>
# include <signal.h>
# include <readline/readline.h>
# include <readline/history.h>
# include <sys/wait.h>
# include <termios.h>
# include <termcap.h>
# include <term.h>

# include "structures.h"
# include "commands.h"
# include "executing.h"
# include "utils.h"
# include "redirecting.h"
# include "reader.h"
# include "cleaning.h"
# include "parser.h"
# include "interactive.h"
# include "initialization.h"

#endif
