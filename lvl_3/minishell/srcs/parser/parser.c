/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dareias- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/17 18:38:45 by dareias-          #+#    #+#             */
/*   Updated: 2022/03/07 23:30:25 by dareias-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	parse_line(t_shell *shell)
{
	t_lex	*lex;
	t_par	*par;
	t_ast	*root;

	if (handle_expansion(shell))
		return (ft_putstr_fd("minishell: Error: Unclosed quotes\n", 2));
	if (shell->line && shell->line[0] != '\0'
		&& shell->line[ft_strlen(shell->line) - 1] == '|')
		return (ft_putstr_fd("minishell: Error: Unclosed pipe\n", 2));
	lex = init_lexer(shell->line);
	if (!lex)
		return (1);
	par = init_parser(lex);
	if (!par)
		return (1);
	root = parse_to_ast(par);
	if (!root)
		return (1);
	shell->ast = root;
	shell->par = par;
	shell->line = par->lex->src;
	ast_handler(shell, root);
	return (0);
}

void	print_ast(t_ast *ast, int l)
{
	int	i;
	int	c;

	i = 0;
	c = 0;
	if (ast == NULL)
		return ;
	l++;
	while (c++ < l)
		printf("- ");
	printf("[%s]", ast_to_str(ast->e_type));
	if (ast->my_tok != NULL)
		printf(": (%s) :  ->%s<- \n", tok_to_str(ast->my_tok->e_type),
			ast->my_tok->value);
	if (!ast->my_tok)
		printf("\n");
	while (ast->branches && ast->branches[i] != NULL)
		print_ast(ast->branches[i++], l);
}

void	update_next(t_par *par, unsigned int *next)
{
	*next = par->tok->e_type;
}
