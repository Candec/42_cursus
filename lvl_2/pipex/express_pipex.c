#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <unistd.h>

int	main(int argc, char *argv[])
{
	int fd[2];
	int pid1;
	int pid2;

	if (pipe(fd) == -1)
		return (-1);

	pid1 = fork();

	if (pid1 < 0)
		return (2);

	if (pid1 == 0)
	{
		//child process 1
		dup2(fd[1], STDOUT_FILENO);
		close(fd[0]);
		close(fd[1]);
		//program execution
	}

	pid2 = fork();
	if (pid < 0)
		return (3);

	if (pid2 == 0)
	{
		//child process 2
		dup2(fd[0], STDIN_FILENO);
		close(fd[0]);
		close(fd[1]);
		//program execution
	}

	close(fd[0]);
	close(fd[1]);

	waitpid(pid1, NULL, 0);
	waitpid(pid2, NULL, 0);
	return (0);
}
