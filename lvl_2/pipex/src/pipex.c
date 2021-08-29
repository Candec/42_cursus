#include "../includes/pipex.h"

void	check_cmd_path(t_pipex *p, char *args[], char *error)
{
	char	*cmd_path;
	int		i;

	i = 0;
	while (p->env_path[i])
	{
		cmd_path = ft_strjoin(p->env_path[i], args[0])
		if (access(cmd_path, X_OK) != -1)
		{
			ft_strdel(&cmd_path);
			break	;
		}
		ft_strdel(&cmd_path);
		i++;
	}
	if (!p->env_path[i])
	{
		error_handling(p, error, FALSE);
		ft_strdel(&error);
		//ft_str_array_del(args)
		error_handling(p, "EXIT", TRUE);
	}
}

	validate_command(t_pipex *p, int argc, char *argv[])
{
	char	**cmd_args;
	int		i;
	char	*error;

	i = 1;
	if (p->mode == PIPE)
		i = 0;
	else if (p->mode == HERE_DOC)
		i = 1;
	while (i++ < argc - 1)
	{
		cmd_args = ft_split(argv[i], ' ');
		error = ft_strjoin("COMMAND ", cmd_args[0]);
		check_cmd_path(p, cmd_args, error);
	}
}


void	find_command_paths(t_pipex *p, int argc, char *argv[], char *envp[])
{
	int i;

	i = 0;
	while (envp[i] ! = NULL)
	{
		if (!ft_strncmp("PATH=", envp[i], 5))
			break ;
		i++;
	}
	p->env_path = ft_split(envp[i], ':');
	p->env_path[0] = ft_substr(p->env_path[0], 5, ft_strlen(p->env_path[0] - 5));
	i = 0;
	while (p->env_path[i])
	{
		p->env_path[i] = ft_strjoin(p->env_path[i], "/");
		i++;
	}
	validate_command(p, argc, argv);
}


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

/*
**	1. Checks the existance of an inputfile
**	2. Cheks the permissions of the inputfile
**	3. It fetchs the commands
**	4. Opens the input file
**	5. Opens the output file
*/

void	check_pipe_mode(t_pipex *p, int argc, char *argv[], char *envp[])
{
	if (access(argv[1], F_OK) == ERROR)
		error_handling(p, "NO INPUT FILE", TRUE);
	if (access(argv[1], R_OK) == ERROR)
		error_handling(p, "INSUFICIENT PERMISSIONS", TRUE);
	find_command_paths(p, argc, argv, envp);
	p->fd_input = open(argv[1], O_RDONLY);
	if (p->fd_input == ERROR)
		error_handling(p, "CANT OPEN INPUT FILE", TRUE);
	p->fd_output = open(argv[argc - 1], O_WRONLY | O_CREATE | O_TRUNC, 0777);
	if (p->fd_output == ERROR)
		error_handling(p, "CANT OPEN OUTPUT FILE", TRUE);
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

