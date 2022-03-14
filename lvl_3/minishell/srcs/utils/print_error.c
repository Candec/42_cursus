/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_error.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dareias- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/17 16:12:47 by dareias-          #+#    #+#             */
/*   Updated: 2021/12/30 15:05:19 by dareias-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	print_error(int error)
{
	if (error == -1)
		perror("minishell: ");
	if (error == MEMORY_FAIL)
		perror("minishell: Failed to allocate memory: ");
	if (error == FILE_OPEN_FAIL)
		perror("minishell: Couldn't open file: ");
	if (error == FORK_FAIL)
		perror("minishell: Failed to create fork: ");
	if (error == EXEC_FAIL)
		perror("minishell: Couldn't execute: ");
	if (error == COMM_FAIL)
		perror("minishell: Command not found: ");
	if (error == IN_N_OUT_FAIL)
		perror("minishell: Failed setting input and output: ");
	return (1);
}
