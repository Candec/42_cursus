#ifndef HEADER_H
# define HEADER_H

/*
** Libraries
*/
# include <stdarg.h>
# include <stdio.h>
# include <string.h>
# include <stdlib.h>
# include <unistd.h>
# include <stdbool.h>

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
** Prototypes
*/
int			ft_printf(const char *fmt, ...);
size_t		ft_strlen(const char *s);

#endif
