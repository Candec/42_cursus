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

typedef struct s_pipex
{
	int		argc;
	char	**argv;
	char	**envp;
	char	**env_path;
	char	***cmds;
	char	*limiter;
	int		n_cmds;
	int		fd_input;
	int		fd_output;
	int		fd[2];
	int		status;
	int		mode;
	pid_t	pid_cmd;
}				t_pipex;

/*
**	pipex.c
*/

void	pipe_closer(t_pipex *p);
void	clear_data(t_pipex *p);
void	pipex_init(t_pipex *p, char **argv);
void	error_handling(t_pipex *p, char *error, int exit);

/*
**	check_mode.c
*/

void	check_input(t_pipex *p, int argc, char *argv[], char *envp[]);
void	check_pipe_mode(t_pipex *p, int argc, char *argv[], char *envp[]);
void	check_heredoc_mode(t_pipex *p, int argc, char *argv[], char *envp[]);

/*
**	check_cmds.c
*/

void	find_command_paths(t_pipex *p, int argc, char *argv[], char *envp[]);
void	validate_command(t_pipex *p, int argc, char *argv[]);
void	check_cmd_path(t_pipex *p, char *args[], char *str);
void	find_command_paths(t_pipex *p, int argc, char *argv[], char *envp[]);
void	get_commands(t_pipex *p);

/*
**	pipe_mode.c
*/

void	pipe_mode(t_pipex *p);
void	child_process(t_pipex *p, int ant_fd, int i);

/*
**	here_doc_mode.c
*/

void	here_doc_mode(t_pipex *p);
void	gnl_ret(t_pipex *p, int ret, char **line, char **readstr);
void	pipe_mode_bridge(t_pipex *p, char *inputstream);
void	ft_free_cube(t_pipex *p);

#endif
