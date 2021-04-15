/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jibanez- <jibanez-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/14 15:46:57 by jibanez-          #+#    #+#             */
/*   Updated: 2021/04/14 15:46:57 by jibanez-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

/*
** Libraries
*/
# include <stdarg.h>
# include <stdbool.h>
# include <unistd.h>
# include <stdio.h>

/*
** Macros
*/
# define VALID "cspdiuxX%"

/*
** Structures
*/
typedef struct s_flags
{
	bool	hash : 1;
	bool	minus : 1;
	bool	plus : 1;
	bool	space : 1;
	bool	zero : 1;

}				t_flags;

typedef struct s_var
{
	int	precision;
	int	width;
}				t_var;

typedef struct s_printf
{
	const char	*str;
	char		*f_str;
	int			i;
	int			f_i;
	int			type_field;
	int			ret;
	va_list		args;
	t_flags		flags;
	t_var		var;

}				t_printf;

/*
** Printf_Prototypes
*/
int		ft_printf(const char *s, ...);
int		ft_init_printf(va_list args, const char *s);
void	into_loop(t_printf *p, char *s);
void	ft_collect_flags(t_printf *p);
void	ft_init_flags(t_printf *p);
int		ft_look_flags(t_printf *p);
void	ft_cancel_flags(t_printf *p);
void	ft_collect_width(t_printf *p);
void	ft_collect_precision(t_printf *p);
void	ft_collect_type(t_printf *p);
void	ft_collect_data(t_printf *p);
void	print_loop(t_printf *p, char s, int i);

/*
** Collect Functions
*/
void	collect_c(t_printf *p);
// void	collect_c(t_printf *p);
// void	collect_s(t_printf *p);
// void	collect_p(t_printf *p);
// void	collect_d(t_printf *p);
// void	collect_s(t_printf *p);
// void	collect_u(t_printf *p);
// void	collect_x(t_printf *p);
// void	collect_percent(t_printf *p);

/*
** Table of Functions
*/
typedef void		t_collect(t_printf *p);

static t_collect	*g_ft_table[] = {
	collect_c,
	// collect_s,
	// collect_p,
	// collect_d,
	// collect_d,
	// **  collect_o,
	// collect_u,
	// collect_x,
	// collect_x,
	// **  collect_f,
	// **  collect_b,
	// collect_percent
};

/*
** Mini_Libft
*/
void	ft_bzero(void *s, size_t n);
int		ft_atoi(const char *str);
int		ft_isdigit(int c);

#endif
