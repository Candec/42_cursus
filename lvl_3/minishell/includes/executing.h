/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   executing.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dareias- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/15 16:17:04 by dareias-          #+#    #+#             */
/*   Updated: 2022/03/10 20:04:35 by dareias-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef EXECUTING_H
# define EXECUTING_H

char	*ft_newpath(char *cmd, char **envp);
char	*ft_findpath(char **envp);
t_comm	*init_command(t_shell *shell, t_ast *ast);
int		init_comm_redir(t_comm *comm, t_ast *ast, int r);
int		config_redir(t_comm *comm, t_ast *ast, int redir);
int		find_cmd_branch(t_ast *ast);
int		find_redir_branch(t_ast *ast);
int		find_args_branch(t_ast *ast);
int		args_ammount(t_ast *command);
int		compound_ammount(t_ast *root, int count);
int		invert_count(int count);
int		store_args(t_comm *comm, t_ast *ast, int a);
int		ast_handler(t_shell *shell, t_ast *root);
int		branch_ammount(t_ast *ast);
int		command_table(t_shell *shell, t_ast *root);
int		run_comm_table(t_shell *shell);
int		invalid_command(t_comm *comm, t_ast *ast, int c);

char	*var_expand(t_ast *ast);
char	*ft_variable(t_shell *shell, char *str);
void	replace_variables(t_shell *shell, t_ast *ast, t_ast *father);
void	ast_update(t_ast *parent, t_ast *child, int up);

// Set_Variables.c
int		add_variable(t_shell *shell, char *var, char *expands);
int		set_variable(t_shell *shell, t_ast *ast);
int		find_var_branch(t_ast *ast);
int		update_var(t_shell *shell, char *var, char *expands, float var_set);
int		variable_as_cmd(t_ast *root);

// Variables.c
float	var_is_set(t_shell *shell, char *var);
int		var_in_vars(char **vars, char *var);
int		var_in_envp(char **envp, char *var);
char	*expansion_from_envp(t_shell *shell, int where);
int		var_already_set(t_shell *shell, char *expands, int where);

int		run_command(t_comm *comm);
int		run_ft_command(t_comm *ft_comm);
int		exec_ft_comm(t_comm *ft_comm);

void	while_replace_vars(int x, t_ast *ast, t_shell *shell);
void	init_token_branch(t_ast *ast, t_ast *temp, t_shell *shell, int c);

// unpack_quotes (&& utils)
int		no_exp_needed(t_ast *son, char *value);
int		expand_quote(t_ast *father, int i);
int		unpack_quotes(t_ast *ast);
int		dq_expanded_len(char *str);

// configure_redirs.c

void	config_writes_redir(t_comm *comm, t_ast *b);
void	config_reads_redir(t_comm *comm, t_ast *b);
void	config_appends_redir(t_comm *comm, t_ast *b);
void	config_heredoc_redir(t_comm *comm, t_ast *b);
void	create_if_needed(char *filename, int mode);

#endif
