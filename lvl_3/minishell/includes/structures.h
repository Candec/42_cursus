/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   structures.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jibanez- <jibanez-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/18 19:56:38 by dareias-          #+#    #+#             */
/*   Updated: 2022/03/09 18:53:10 by jibanez-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef STRUCTURES_H
# define STRUCTURES_H

typedef struct s_shell	t_shell;
typedef struct s_tok
{
	char	*value;
	enum
	{
		TOK_WORD,
		TOK_DOLLAR,
		TOK_LT,
		TOK_GT,
		TOK_ARROW_RIGHT,
		TOK_ARROW_LEFT,
		TOK_OPTION,
		TOK_TILDE,
		TOK_S_QUOTE,
		TOK_D_QUOTE,
		TOK_SEMI,
		TOK_COLLON,
		TOK_DOT,
		TOK_EQUALS,
		TOK_BSLASH,
		TOK_OPAREN,
		TOK_CPAREN,
		TOK_SPACE,
		TOK_PIPE,
		TOK_SQUOTED,
		TOK_DQUOTED,
		TOK_ERROR,
		TOK_EOL
	} e_type;
}				t_tok;

typedef struct s_lex
{
	int		i;
	char	c;
	char	*src;
	int		size;
	int		q;
}			t_lex;

typedef struct s_par
{
	t_lex			*lex;
	t_tok			*tok;
	unsigned int	next;
}			t_par;

typedef struct s_ast	t_ast;

typedef struct s_ast
{
	enum
	{
		AST_ROOT,
		AST_COMPOUND,
		AST_VARIABLE,
		AST_VAR_DEF,
		AST_VAR_EXP,
		AST_COMMAND,
		AST_COMM_ARGS,
		AST_REDIRECT,
		AST_DELIMITER,
		AST_WORD,
		AST_NULL
	}		e_type;
	t_ast	**branches;
	t_tok	*my_tok;
}			t_ast;

typedef struct s_redir
{
	int		reads;
	int		writes;
	int		appends;
	int		heredoc;
	int		ammount;
	int		read_ammount;
	int		write_ammount;
	int		append_ammount;
	int		heredoc_ammount;
}				t_redir;

typedef struct s_comm
{
	enum
	{
		VAR_DEF,
		COMMAND,
		INVALID
	} e_type;
	char	*infile;
	char	*outfile;
	char	*heredoc_filename;
	char	*heredoc_word;
	t_redir	redir;
	char	*cmd;
	char	**args;
	char	**unsorted_env;
	t_shell	*shell;
	int		piping;
	int		is_ft;
}			t_comm;

typedef struct s_termcaps
{
	struct termios	old_term;
	struct termios	new_term;
	char			*buffer;
	char			*keys_on;
	char			*keys_off;
	char			*up_arrow;
	char			*down_arrow;
	char			*backspace;
	char			*del_line;
	char			*set_cursor_begin;
}				t_termcaps;

typedef struct s_io
{
	int		save_in;
	int		save_out;
	int		saved_in;
	int		saved_out;
	int		my_pipe[2];
	int		current_in;
	int		current_out;
}				t_io;

typedef struct s_shell
{
	char				**envp;
	char				*line;
	int					debug;
	char				**vars;
	int					exit_status;
	struct sigaction	sa;
	t_termcaps			termcaps;
	t_comm				**commands;
	int					loop;
	char				*prompt;
	int					last_exit;
	t_io				io;	
	t_par				*par;
	t_ast				*ast;

}			t_shell;

#endif
