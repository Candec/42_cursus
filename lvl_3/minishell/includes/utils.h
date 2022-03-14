/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jibanez- <jibanez-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/15 16:24:46 by dareias-          #+#    #+#             */
/*   Updated: 2022/02/15 15:04:18 by jibanez-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef UTILS_H
# define UTILS_H

typedef enum e_exit_code
{
	MEMORY_FAIL,
	FILE_OPEN_FAIL,
	FORK_FAIL,
	EXEC_FAIL,
	COMM_FAIL,
	IN_N_OUT_FAIL,
	PARSE_FAIL
}			t_exit_code;

typedef enum e_color
{
	WHT,
	BLK,
	RED,
	YEL,
	BLU,
	GRN,
	CYA,
	PUR
}			t_color;

// Strings
char	**ft_split(char const *s, char c);
int		my_strcmp(char *str1, char *str2);
int		ft_strcmp(char *str1, char *str2, int cmp);
int		ft_strcmp_two(char *str1, char *str2);
int		ft_strcmp_envp(char *whole_var, char *var);
char	*ft_strnstr(char *haystack, char *needle);
int		ft_strlen(char *str);
char	*ft_append(char *str, char *append);
char	*ft_strdup(char *s);
int		ft_strchr(char c, char *s);
char	*ft_substr(char *str, int start, int ammount);
char	*ft_strcat(char *str, char *append);
char	*ft_color(unsigned int color);
void	change_color(unsigned int color);
int		ft_putint(int c);
char	*ft_strjoin(char *s1, char *s2);

// Error printing
int		print_error(int error);
int		ft_putstr_fd(char *s, int fd);
char	*tok_to_str(unsigned int type);
char	*ast_to_str(unsigned int type);
void	comm_printer(t_comm *comm);

// Pattern matching
int		is_spec(char c);
int		ft_isalpha(int c);
int		ft_isdigit(int c);
int		ft_isalnum(int c);
int		ft_isspace(int c);
int		ft_isquote(int c);
int		ft_isword(int c);
int		ft_isforb(int c);
int		ft_iscomm(char *str);
int		wordquotetok(unsigned int type);
int		update_inhib(int *inhib, int mode);

// Get quote - adapted from gnl
// char	*store_buffer(char *holder, char *buff);
// char	*store_line(char **line, char *holder, int ret);
// char	*get_next_line(int fd, char *s);
// char	*gnl_helper(char **holder, char *line, int ret);
// void	store_line_helper(char **line, char **holder, char *temp, int i);

// Math
int		ft_max(int a, int b);
int		ft_min(int a, int b);
int		ft_atoi(const char *str);
char	*ft_itoa(int n);

char	**dup_envp(char **envp);

char	*get_cwd(t_shell *shell);

int		nta_size(char **array);
int		nta_on_even_size(char **array);

void	*malloc_or_exit(size_t size);
int		safe_free(void *ptr);

#endif
