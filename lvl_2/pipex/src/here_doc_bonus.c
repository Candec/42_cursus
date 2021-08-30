#include "../includes/pipex.h"

void	pipe_mode_bridge(t_pipex *p, char *inputstream)
{
	p->fd_input = open(inputstream, O_RDONLY);
	if (p->fd_input == ERROR)
		error_handling(p, "OPENING INPUTSTREAM", TRUE);
	pipe_mode(p);
	if (unlink(inputstream) == ERROR)
		error_handling(p, "UNLINKING INPUTSTREAM", TRUE);
}

void	gnl_ret(t_pipex *p, int ret, char **line, char **readstr)
{
	if (ret == ERROR || ret == 0)
	{
		if (*line)
			ft_strdel(line);
		if (*readstr)
			ft_strdel(readstr);
		if (ret == ERROR)
			error_handling(p, "INPUT READING", TRUE);
		else
			error_handling(p, "EOF BEFORE LIMITER", TRUE);
	}
	else if (ret == 1)
	{
		*readstr = ft_strjoin(*readstr, *line);
		*readstr = ft_strjoin(*readstr, "\n");
		ft_strdel(line);
	}
}

void	here_doc_mode(t_pipex *p)
{
	char	*line;
	char	*str;
	int		ret;

	line = NULL;
	str = NULL;
	ret = ft_get_next_line(STDIN_FILENO, &line);
	gnl_ret(p, ret, &line, &str);
	while (ret)
	{
		ret = ft_get_next_line(STDIN_FILENO, &line);
		if (ft_strequal(line, p->limiter))
		{
			if (*line)
				ft_strdel(&line);
			break ;
		}
		gnl_ret(p, ret, &line, &str);
	}
	write(p->fd_input, str, ft_strlen(str));
	close(p->fd_input);
	ft_strdel(&str);
	pipe_mode_bridge(p, "TMP.txt");
}
