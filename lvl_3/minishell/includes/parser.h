/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dareias- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/18 19:50:03 by dareias-          #+#    #+#             */
/*   Updated: 2022/03/07 23:30:20 by dareias-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PARSER_H
# define PARSER_H

// parser
int		parse_line(t_shell *shell);
void	print_ast(t_ast *ast, int l);
void	update_next(t_par *par, unsigned int *next);

// lexer
t_tok	*init_token(char *value, int type);
t_lex	*init_lexer(char *src);
void	lex_next(t_lex *lex);
t_tok	*lex_get_word(t_lex *lex);
t_tok	*next_token(t_lex *lex);

// lexer_utils
t_tok	*token_switch(char c, t_lex *lex);
t_tok	*token_switch_two(char c, t_lex *lex);
t_tok	*token_switch_three(t_lex *lex);
int		nextquote(t_lex *lex, int q);
char	*ft_dupnoq(char *s);
int		lex_get_word_core(t_lex *lex, int *store);

// ast
t_ast	*init_ast(int type);
void	ast_add_branch(t_ast *parent, t_ast *child, int i);
int		ast_branch_ammount(t_ast *ast);
void	ast_add_branch_idx(t_ast *parent, t_ast *child, int i, int idx);

// parser_logic
t_ast	*parse_compound(t_par *par);
t_ast	*parse_compound_two(t_par *par, t_ast *ast, int i, int x);
t_ast	*parse_compound_core(t_ast *ast, t_par *par, int i, int x);
t_ast	*parse_redirect(t_par *par);

// parser_utils
t_par	*init_parser(t_lex *lex);
t_tok	*parser_next(t_par *par, unsigned int type);
t_ast	*parse_to_ast(t_par *par);
int		parse_to_ast_core(t_ast *root, t_par *par, int i);
t_ast	*parse_word(t_par *par);
t_ast	*parse_variable(t_par *par);

// parse_command
int		command_parser(t_ast *ast, t_par *par, unsigned int i, int x);
t_ast	*parse_command(t_par *par);
int		command_tok(unsigned int type);

// parse_expansion
t_ast	*parse_expansion(t_par *par);
int		parse_exp_status(t_par *par);

// new adittions - preparsing

void	expand(t_shell *shell, char **exp);
char	*remove_old(char *s, int where);
char	*insert_str_in_str(char *str, char *insert, int where);
int		handle_expansion(t_shell *shell);
void	try_add_expansion(t_shell *shell, int where);
int		exp_valid_format(char *s, int where);

#endif
