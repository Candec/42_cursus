/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jibanez- <jibanez-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/02 15:48:17 by jibanez-          #+#    #+#             */
/*   Updated: 2021/10/17 13:31:50 by jibanez-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFT_H
# define LIBFT_H

/*
**Libraries
*/
# include <stdio.h>
# include <string.h>
# include <stdlib.h>
# include <unistd.h>
# include <limits.h>
# include <stdint.h>
# include <stddef.h>
# include <stdarg.h>
# include <fcntl.h>

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 300
# endif

# ifndef ASCII_OFFSET_NUM
#  define ASCII_OFFSET_NUM 48
# endif

typedef int	t_bool;

/*
**First half
*/
int				ft_atoi(const char *str);
void			ft_bzero(void *s, size_t n);
void			*ft_calloc(size_t nmemb, size_t size);
int				ft_isalnum(int c);
int				ft_isalpha(int c);
int				ft_isascii(int c);
int				ft_isdigit(int c);
int				ft_isprint(int c);
void			*ft_memccpy(void *dest, const void *src, int c, size_t n);
void			*ft_memchr(const void *s, int c, size_t n);
int				ft_memcmp(const void *s1, const void *s2, size_t n);
void			*ft_memcpy(void *dest, const void *src, size_t n);
void			*ft_memmove(void *dest, const void *src, size_t n);
void			*ft_memset(void *s, int c, size_t n);
char			**ft_split(char const *s, char c);
char			*ft_strncpy(char *dest, char *src, unsigned int n);
char			*ft_strchr(const char *s, int c);
char			*ft_strdup(const char *src);
size_t			ft_strlen(const char *s);
size_t			ft_strlcpy(char *dest, const char *src, size_t size);
size_t			ft_strlcat(char *dst, const char *src, size_t size);
int				ft_strncmp(const char *s1, const char *s2, size_t n);
char			*ft_strnstr(const char *a, const char *b, size_t len);
char			*ft_strrchr(const char *s, int c);
int				ft_tolower(int c);
int				ft_toupper(int c);

/*
**Second half
*/
char			*ft_substr(char const *s, unsigned int start, size_t len);
char			*ft_strjoin(char const *s1, char const *s2);
char			*ft_strtrim(char const *s1, char const *set);
char			*ft_itoa(int n);
char			*ft_strmapi(char const *s, char (*f)(unsigned int, char));
void			ft_putchar_fd(char c, int fd);
void			ft_putstr_fd(char const *s, int fd);
void			ft_putendl_fd(char const *s, int fd);
void			ft_putnbr_fd(int n, int fd);

/*
**Bonus from the exercise
*/
typedef struct s_list
{
	void			*content;
	struct s_list	*next;
}				t_list;

t_list			*ft_lstnew(void *content);
void			ft_lstadd_front(t_list **lst, t_list *new);
int				ft_lstsize(t_list *lst);
t_list			*ft_lstlast(t_list *lst);
void			ft_lstadd_back(t_list **lst, t_list *new);
void			ft_lstdelone(t_list *lst, void (*del)(void*));
void			ft_lstclear(t_list **lst, void (*del)(void*));
void			ft_lstiter(t_list *lst, void (*f)(void *));
t_list			*ft_lstmap(t_list *l, void *(*f)(void *), void (*d)(void *));

/*
**42 projects
*/
int				ft_get_next_line(int fd, char **line);

/*
**Extras
*/
char			*ft_strrev(char *s);
ssize_t			ft_ispositive(int n);
int				ft_isspace(char a);
int				ft_numlen(int_fast64_t value, int base);
int				ft_abs(int n);
int				ft_strcmp(char *s1, char *s2);
void			ft_strtoupper(char *str);
int				ft_max(int args, ...);
int				ft_isnumber(char *str);
char			*ft_strmerge(char **str, int space, int size);
char			*ft_strnew(size_t size);
char			*ft_strcat(char *s1, char *s2);
void			*ft_memalloc(size_t size);
void			ft_strdel(char **str);
void			ft_putstr(char *str);
char			*ft_strcpy(char *dest, char *src);
void			ft_str_array_del(char **str_arr);
void			ft_str_array_array_del(char ***str_arr);
t_bool			ft_strequal(char *s1, char *s2);
char			*ft_strjoin_char(const char *s1, char c);

#endif
