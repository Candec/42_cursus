#ifndef PIPEX_H
# define PIPEX_H

# include <sys/wait.h>
# include <stdlib.h>
# include <string.h>
# include <unistd.h>
# include <errno.h>
# include <fcntl.h>
# include <stdio.h>
# include "../libft/libft.h"

enum
{
	FALSE,
	TRUE,
	PIPE,
	HERE_DOC
};

# define WRITE_END 1
# define READ_END 0
# define CHILD_PROCESS 0
# define ERROR -1

typedef struct	s_pipex
{
	int		argc;
	char	**argv;
	char	**envp;
	char	**env_path;
	char	*cmds;
	int		n_cmds;
	int		fd_input;
	int		fd_output;
	int		fd[2];
	int		pid_cmd;
	int		status;
	int		mode;
	char	*limiter;
}				t_pipex;


#endif
