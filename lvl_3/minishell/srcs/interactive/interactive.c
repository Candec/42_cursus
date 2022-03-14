/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   interactive.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jibanez- <jibanez-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/06 19:52:43 by dareias-          #+#    #+#             */
/*   Updated: 2022/03/09 17:08:24 by jibanez-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

// int interactive_mode(t_shell *shell, char *argv[])
// {
// 	int ret;
// 	//int fd;
// 	//char *debugging;

// 	ret = 1;
// 	// Normally
// 	/*
// 	fd = ft_getfd(argv[1], 2);
// 	if (fd == -1)
// 		return (EXIT_FAILURE);
// 	while (ret)
// 	{	
// 		debugging = get_next_line(fd, NULL);
// 		//printf("Line from GNL ->%s<-\n", debugging);
// 		if (ft_strlen(debugging) == 0)
// 		{
// 			free(debugging);
// 			debugging = NULL;
// 		}
// 		if (shell->line != NULL)
// 			free(shell->line);
// 		shell->line = format_interactive_line(debugging);
// 		if (shell->line != NULL)
// 		{
// 			parse_line(shell);
// 			clean_shell(shell);
// 		}
// 		else
// 			ret = 0;
// 	}
// 	close(fd);
// 	*/

// 	// For testing
// 	shell->line = argv[2];
// 	// End of test

// 	ret = parse_line(shell);
// 	clean_shell(shell);
// 	if (shell->vars)
// 	{
// 		clean_vars(shell);
// 	}
// 	if (shell->envp)
// 		clean_envp(shell);
// 	return (ret);
// }

char	*format_interactive_line(char *line)
{
	int		len;
	char	*new_line;

	if (!line)
		return (NULL);
	len = ft_strlen(line);
	if (!len)
		return (NULL);
	if (line[len - 1] != '\n')
		return (line);
	new_line = ft_strdup(line);
	if (!new_line)
		return (line);
	new_line[len - 1] = '\0';
	free(line);
	return (new_line);
}
