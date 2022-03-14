/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   process_quotes.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jibanez- <jibanez-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/09 17:15:05 by dareias-          #+#    #+#             */
/*   Updated: 2022/03/09 19:05:52 by jibanez-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

/*
//
// insert_str_in_str example:
// str = "ola||malta"
// insert = "minha"
// where = 4
// str = insert_str_in_str(str, insert, where)
// str = "ola|minha|malta"
*/

char	*insert_str_in_str(char *str, char *insert, int where)
{
	char	*new_str;
	int		i;
	int		n;
	int		s;

	if (where > ft_strlen(str) || !insert)
		return (str);
	new_str = malloc_or_exit(sizeof(char) * (ft_strlen(str)
				+ ft_strlen(insert) + 1));
	i = 0;
	n = 0;
	s = 0;
	while (str[s] != '\0' && s < where)
		new_str[n++] = str[s++];
	while (insert[i] != '\0')
		new_str[n++] = insert[i++];
	while (str[s] != '\0')
		new_str[n++] = str[s++];
	new_str[n] = '\0';
	free(str);
	return (new_str);
}

int	handle_expansion(t_shell *shell)
{
	char	*s;
	int		inhib;
	int		x;

	inhib = 0;
	x = 0;
	s = shell->line;
	while (x < ft_strlen(s) && s[x] != '\0')
	{
		if (s[x] == '$' && inhib != 1)
			try_add_expansion(shell, x);
		else if (s[x] == '\'')
			update_inhib(&inhib, 1);
		else if (s[x] == '\"')
			update_inhib(&inhib, 2);
		s = shell->line;
		x++;
	}
	return (inhib);
}

void	try_add_expansion(t_shell *shell, int where)
{
	char	*exp;
	char	*new_line;
	int		i;

	if (!exp_valid_format(shell->line, where + 1))
		return ;
	new_line = ft_strdup(shell->line);
	i = 0;
	while (exp_valid_format(new_line, (where + 1) + i))
		i++;
	exp = ft_substr(new_line, (where + 1), i);
	expand(shell, &exp);
	new_line = remove_old(new_line, where);
	new_line = insert_str_in_str(new_line, exp, where);
	safe_free(exp);
	safe_free(shell->line);
	shell->line = new_line;
}

int	exp_valid_format(char *s, int where)
{
	char	c;

	c = s[where];
	if (c == '\0')
		return (0);
	return (ft_isalnum(c) || c == '?');
}
