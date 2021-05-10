#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <limits.h>
# include <stdlib.h>
# include <stdarg.h>
# include <string.h>
# include "../libft/libft.h"

# define TYPES "cspdiuxX"
# define DEC_BASE "0123456789"
# define HEX_BASE "0123456789abcdef"
# define BUFF_LEN 20

typedef struct s_printf{
	int				zero;
	int				nbr_zeros;
	int				minus;
	int				width;
	int				prec;
	int				w_inp;
	int				p_inp;
	int				w_aster;
	int				p_aster;
	char			type;
	void			*content;
	char			chr;
	int				len;
	int				negative;
	int				invalid;
}				t_printf;

int		ft_printf(const char *str, ...);
int		write_char(char *t_str, char *str, int last);
void	memories_init(t_printf *p);
void	conversion(va_list *args, char **str);
void	clean(t_printf *p);
void	int_type_mem(t_printf *p, va_list *args, char *buffer);
void	char_type_mem(t_printf *p, va_list *args);
void	n_to_str(t_printf *p, unsigned long long n, char *base, char *buffer);
void	write_buffer(t_printf *p);

#endif