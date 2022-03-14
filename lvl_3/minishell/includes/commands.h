/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   commands.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dareias- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/15 15:31:38 by dareias-          #+#    #+#             */
/*   Updated: 2022/03/05 19:11:36 by dareias-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef COMMANDS_H
# define COMMANDS_H

int		ft_cd(t_comm *ft_comm);
int		ft_pwd(t_comm *ft_comm);
int		ft_echo(t_comm *ft_comm);
int		ft_env(t_comm *ft_comm);
int		ft_export(t_comm *ft_comm);
int		ft_unset(t_comm *ft_comm);
void	ft_exit(t_comm *ft_comm);

// Envp
char	**add_envp(char **envp, char *add);
char	**rm_envp(char **envp, char *rm, int i, int l);
char	**rm_envp_two(char **new, char **envp, int i, int l);
void	rm_var(t_shell *shell, char *var, int size);
int		find_next_eq(char *str);
int		change_envp(char **envp, int where, char *new_val);
char	*whole_var_from_vars(char **vars, char *var);
void	rm_var_from_vars(t_shell *shell, char *var);
int		set_new_var(t_comm *ft_comm, int i, int save);
int		reset_var_vars(t_comm *c, int i, float var_set);
int		reset_var_envp(t_comm *ft_comm, int i, float var_set);

// EXPORT
int		ft_print_export(t_comm *ft_comm);
int		env_in_sorted(char **sorted_env, char *env);
int		get_next_lowest_env(char **sorted_env, char **unsorted);
int		is_it_lowest(char **sorted_env, char **unsorted, int i);
int		build_unsorted_env(t_comm *ft_comm);

#endif
