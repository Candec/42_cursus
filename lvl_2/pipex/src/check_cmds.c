#include "../includes/pipex.h"

/*
**	| Command Validation |
*/

/*
**	1. Joins the path with the program name
**	2. Tries to access it until it finds a proper
**	   path and then exists the while loop
**	3. If no path is found, it Exits and cleans the memory
*/

void	check_cmd_path(t_pipex *p, char *args[], char *str)
{
	char	*cmd_path;
	int		i;

	i = -1;
	while (p->env_path[++i])
	{
		cmd_path = ft_strjoin(p->env_path[i], args[0]);
		if (access(cmd_path, X_OK) != -1)
		{
			ft_strdel(&cmd_path);
			break ;
		}
		ft_strdel(&cmd_path);
	}
	if (!p->env_path[i])
	{
		error_handling(p, str, FALSE);
		ft_strdel(&str);
		ft_str_array_del(&args);
		error_handling(p, "EXIT", TRUE);
	}
}   

/*
**	1. Checks the mode
**	2. Splits the command using the ' ' space character
**	3. Adds COMMAND to help finding it later
**	4. Checks if the command is actually a command
**	5. Delets the str and the array of Commands from the memory.
*/

void	validate_command(t_pipex *p, int argc, char *argv[])
{
	char	**cmd_args;
	int		i;
	char	*str;

	i = 1;
	if (p->mode == PIPE)
		i = 1;
	else if (p->mode == HERE_DOC)
		i = 2;
	while (++i < argc - 1)
	{
		cmd_args = ft_split(argv[i], ' ');
		str = ft_strjoin("COMMAND ", cmd_args[0]);
		check_cmd_path(p, cmd_args, str);
		ft_strdel(&str);
		ft_str_array_del(&cmd_args);
	}
}

/*
**	1. Looks for the env variable which in the 5 first chars has the "PATH="
**	2. Normally there are several paths divided by ':', so it split it
**	3. On the first one, we still have "PATH=", so we get ride of it
**	4. Added '/' so we can use it later for path checking.
*/

void	find_command_paths(t_pipex *p, int argc, char *argv[], char **envp)
{
	int	i;
    char *str;

	i = -1;
	while (envp[++i])
	{
		if (!ft_strncmp("PATH=", envp[i], 5))
			break ;
	}
	p->env_path = ft_split(envp[i], ':');
    str = p->env_path[0];
	p->env_path[0] = ft_substr(str, 5,
			ft_strlen(str - 5));
    free(str);
	i = -1;
	while (p->env_path[++i])
    {
        str = p->env_path[i];
		p->env_path[i] = ft_strjoin_char(str, '/');
        free(str);
    }
	validate_command(p, argc, argv);
}

/*
**	| Command addition to t_pipex |
*/

void	save_commands(t_pipex *p, char *cmds_arg[])
{
	char	*cmds_path;
	int		i;

	i = -1;
	while (p->env_path[++i])
	{
		cmds_path = ft_strjoin(p->env_path[i], *cmds_arg);
		if (access(cmds_path, X_OK) != -1)
		{
			*cmds_arg = cmds_path;
			break ;
		}
		ft_strdel(&cmds_path);
	}
}

void	get_commands(t_pipex *p)
{
	int		i;
	int		j;
	char	**cmds_args;

	p->cmds = ft_calloc(p->argc - 2, sizeof(char **));
	if (!p->cmds)
		error_handling(p, "MALLOC", TRUE);
	i = 1;
	if (p->mode == PIPE)
		i = 1;
	else if (p->mode == HERE_DOC)
		i = 2;
	j = -1;
	while (++i < p->argc - 1)
	{
		cmds_args = ft_split(p->argv[i], ' ');
		if (!cmds_args)
			error_handling(p, "SPLIT", TRUE);
		save_commands(p, &cmds_args[0]);
		p->cmds[++j] = cmds_args;
		p->n_cmds++;
	}
	ft_str_array_del(&p->env_path);
}
