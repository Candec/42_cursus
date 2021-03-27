/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   header.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jibanez- <jibanez-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/12 11:27:49 by jibanez-          #+#    #+#             */
/*   Updated: 2021/03/12 11:27:49 by jibanez-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

/*
** Libraries
*/
# include <stdarg.h>
# include <stdio.h>
# include <string.h>
# include <stdlib.h>
# include <unistd.h>
# include <stdbool.h>
# include <limits.h>

/*
** Flags
*/
typedef struct	s_variables
{
	int			width;
	int			precision;
}				t_variables;

typedef struct	s_flag
{
	bool		hash : 1;
	bool		zero : 1;
	bool		minus : 1;
	bool		plus : 1;
	bool		space : 1;
}				t_flag;

typedef struct	s_length
{
	bool		hh : 1;
	bool		h : 1;
	bool		l : 1;
	bool		ll : 1;
	bool		uppercase_l : 1;
}				t_length;

/*
** storage
*/
typedef struct	s_storage
{
	const char	*str;
	t_flag		flags;
	t_variables	vars;
	t_length	len;
	va_list		arguments;
	int			width_field;
	int			precision_field;
	int			length_field;
	int			type_field;
	int			i;
	int			i_prev;
}				t_storage;

/*
** Printf Prototypes
*/
int			ft_printf(const char *fmt, ...);
void		ft_start_printf(va_list args, const char *fmt);
void		ft_initialized_vars(t_storage *obj);
void		ft_parse(t_storage *obj);
void		ft_initialized_flags_and_tags(t_storage *obj);
int			ft_collect_flags(t_storage *obj);
void		ft_collect_width(t_storage *obj);
void		ft_collect_precision(t_storage *obj);
void		ft_collect_length(t_storage *obj);
void		ft_collect_type_of_field(t_storage *obj);

/*
** Other Prototypes
*/
size_t		ft_strlen(const char *s);
void		ft_bzero(void *s, size_t n);
int			ft_isdigit(int c);
int			ft_atoi(const char *str);
void		ft_putstr(char const *s);
void		ft_putchar(const char c);

/*
** c Prototypes
*/
void	collect_c(t_storage *obj);


/*
** Dispatch table
*/
typedef void	t_ft_print_functions(t_storage *obj);

static	t_ft_print_functions *g_ft_dispatch_table[] =
{
	collect_c,
	// collect_s,
	// collect_p,
	// collect_d,
	// collect_d,
	// collect_o,
	// collect_u,
	// collect_x,
	// collect_x,
	// collect_f,
	// collect_b,
	// collect_percent
};



#endif
