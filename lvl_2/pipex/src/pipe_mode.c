#include "../includes/pipex.h"

void	ft_free_cube(char ***cmds)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (cmds[i])
	{
		j = 0;
		while (cmds[i][j])
		{
			free(cmds[i][j]);
			j++;
		}
		free(cmds[i]);
		i++;
	}
	free(cmds);
}

void	child_process(t_pipex *p, int ant_fd, int i)
{
	if (ant_fd != STDIN_FILENO && i != 0)
		dup2(ant_fd, STDIN_FILENO);
	else
		dup2(p->fd_input, STDIN_FILENO);
	if (i != p->n_cmds - 1)
		dup2(p->fd[WRITE_END], STDOUT_FILENO);
	else
		dup2(p->fd_output, STDOUT_FILENO);
	pipe_closer(p);
	if (execve(p->cmds[i][0], p->cmds[i], p->envp) == ERROR)
		error_handling(p, "EXE ERROR", TRUE);
}

void	pipe_mode(t_pipex *p)
{
	int	i;
	int	ant_fd;

	i = -1;
	ant_fd = p->fd_input;
	while (++i < p->n_cmds)
	{
		if (pipe(p->fd) == ERROR)
			error_handling(p, "PIPE OPENING", TRUE);
		p->pid_cmd = fork();
		if (p->pid_cmd == ERROR)
			error_handling(p, "FORK", TRUE);
		if (p->pid_cmd == CHILD_PROCESS)
			child_process(p, ant_fd, i);
		close(ant_fd);
		close(p->fd[WRITE_END]);
		ant_fd = p->fd[READ_END];
		if (waitpid(p->pid_cmd, &p->status, 0) == ERROR)
			error_handling(p, "WAIT", TRUE);
		if (WIFEXITED(p->status) != TRUE && WEXITSTATUS(p->status) != 0)
			error_handling(p, "COMMAND FAILURE", TRUE);
	}
}
