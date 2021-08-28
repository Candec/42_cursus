#include "../includes/pipex.h"

/*
**	Possible errors to handle
**	1. Not enough arguments
**	2. No input file or no access to the input file
**	3. Problems opening the input file
**	4. Problems opening the output file
**	5. Command(s) not found or incorrect
**
**	Extra check to clear if the code could not continue
*/

void	error_handling(t_pipex *p, char *error, int exit)
{
	if (ft_strequal(error, "INSUFICIENT ARGUMENTS"))
	{
		ft_putendl_fd("Insuficient amount of arguments", 2);
		ft_putstr_fd(error, 2);
		ft_putstr_fd(": ./pipex \"filename of file 1\"", 2);
		ft_putstr_fd(" \"n Commands (with flags or args)\"", 2);
		ft_putstr_fd(" \"filename of file 2\"\n", 2);
	}
	else if (ft_strequal(error, "INSUFICIENT PERMISSIONS")
			|| ft_strequal (error, "NO INPUT FILE"))
		perror(error);
	else if (ft_strequal(error, "CANT OPEN INPUT FILE"))
		perror(error);
	else if (ft_strequal(error, "CANT OPEN OUTPUT FILE"))
		perror(error);
	else if (ft_strequal(error, "COMMAND NOT FOUND"))
		perror(error);
	if (exit == TRUE)
	{
		//clear_data(p);
		exit(EXIT_FAILURE);
	}
}

/*
**	1. As Here_doc has 1 more argument, it needs to be accounted for
**	2. Looks for the commands in the enviroments var using the paths
**	3. Creates or opens the file "inputstream.txt"
**	4. Handles errors with the file
**	5. Opens the file indicated in the arguments
**	6. Handles errors with the file
*/

void	check_heredoc_mode(t_pipex *p, int argc, char *argv[], char *envp[])
{
	if (argc < 6)
		error_handling(p, "HERE_DOC MODE USAGE", TRUE);
	find_command_paths(p, argc, argv, envp);
	p->fd_input = open("inputstream.txt", O_WRONLY | O_CREAT, 0777);
	if (p->fd_input == ERROR)
		error_handling(p, "OPENING INPUTSTREAM", TRUE);
	p->fd_out = open(argv[argc - 1], O_WRONLY | O_CREAT | O_APPEND, 0777);
	if (p->fd_out == ERROR)
		error_handling(p, "OPENING OUTPUT FILE", TRUE);
	p->limiter = ft_strdup(argv[2]);
}

void	check_pipe_mode(t_pipex *p, int argc, char *argv[], char *envp[])
{
	if (access())
}

void	check_input(t_pipex *p, int argc, char *argv[], char *envp[])
{
	if (argc < 5)
		error_handling(p, "INSUFICIENT ARGUMENTS", TRUE);
	if (p->mode == HERE_DOC)
		check_heredoc_mode(p, argc, argv, envp);
	else
		check_pipe_mode(p, argc, argv, envp);
	p->argc = argc;
	p->argv = argv;
	p->envp = envp;
}

void	pipex_init(t_pipex *p, char **argv)
{
	p->env_path = NULL;
	p->cmds = NULL;
	p->n_cmds = 0;
	p->fd_input = -1;
	p->fd_output = -1;
	p.fd[1] = -1;
	p.fd[2] = -1;
	p->pid_cmd = -1;
	if (ft_strequal(argv[1], "here_doc"))
		p->mode = HERE_DOC;
	else
		p->mode = PIPE;
	p->limiter = NULL;
}

/*
**	1.Initialize the t_pipex struct.
**	2.error handling
**	3.command checking
**	4.piping
**	5.close pipes
*/

int	main(int argc, char *argv[], char *envp[])
{
	t_pipex p;

	pipex_init(&p, argv);
	check_input(&p, argc, argv, envp);

}

