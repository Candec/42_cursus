/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   redirecting.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jibanez- <jibanez-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/15 16:37:01 by dareias-          #+#    #+#             */
/*   Updated: 2022/03/09 18:49:06 by jibanez-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef REDIRECTING_H
# define REDIRECTING_H

int		ft_getfd(char *filename, int type);
int		change_in(int old_in_fd, char *new_in, int redir);
int		change_out(int old_out_fd, char *new_out, int redir);
int		set_in_and_out(t_comm *comm);
int		reset_std_io(t_shell *shell, int reset_in, int reset_out);
void	save_std_io(t_shell *shell, int in, int out);
void	close_std_io_dups(t_shell *shell);
int		set_pipes(t_comm *comm);
int		fd_closer(t_comm *comm);
char	*ft_heredoc(t_comm *comm);

int		while_set_in_and_out(t_comm *comm, int *reset_in, int *reset_out);
int		comm_read(t_comm *comm, int *reset_in);
int		comm_appends(t_comm *comm, int *reset_out);
int		comm_write(t_comm *comm, int *reset_out);
int		comm_heredoc(t_comm *comm, int *reset_in);
void	comm_piping(t_comm *comm, int *reset_in, int *reset_out);

#endif
