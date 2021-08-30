#include "../includes/pipex.h"

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
	p->fd_input = open("TMP.txt", O_WRONLY | O_CREAT, 0777);
	if (p->fd_input == ERROR)
		error_handling(p, "OPENING INPUTSTREAM", TRUE);
	p->fd_output = open(argv[argc - 1], O_WRONLY | O_CREAT | O_APPEND, 0777);
	if (p->fd_output == ERROR)
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
	p->fd_output = open(argv[argc - 1], O_WRONLY | O_CREAT | O_TRUNC, 0777);
	if (p->fd_output == ERROR)
		error_handling(p, "CANT OPEN OUTPUT FILE", TRUE);
}

/*
**	1. Are there enough arguments?
**	2. Here_doc requires one more arg to include the here_doc file
**	3. save the rest of the vars.
*/

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
