/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_is_two.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dareias- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/26 16:17:06 by dareias-          #+#    #+#             */
/*   Updated: 2022/01/21 15:18:53 by dareias-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	ft_isquote(int c)
{
	if (c == '\'')
		return (1);
	if (c == '\"')
		return (2);
	return (0);
}

int	ft_isword(int c)
{
	if (ft_isquote(c) || ft_isalnum(c))
		return (1);
	if (c == '.' || c == '/' || c == '-'
		|| c == '_' || c == '~')
		return (1);
	return (0);
}

int	ft_isforb(int c)
{
	if (ft_isspace(c))
		return (1);
	if (ft_strchr(c, "<>=;|") > -1)
		return (1);
	if (c == '\0')
		return (1);
	return (0);
}

int	ft_iscomm(char *str)
{
	if (ft_strcmp_two(str, "cd"))
		return (1);
	if (ft_strcmp_two(str, "pwd"))
		return (2);
	if (ft_strcmp_two(str, "echo"))
		return (3);
	if (ft_strcmp_two(str, "env"))
		return (4);
	if (ft_strcmp_two(str, "export"))
		return (5);
	if (ft_strcmp_two(str, "unset"))
		return (6);
	if (ft_strcmp_two(str, "exit"))
		return (7);
	return (0);
}

int	wordquotetok(unsigned int type)
{
	if (type == TOK_WORD || type == TOK_DQUOTED)
		return (1);
	return (0);
}
