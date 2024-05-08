/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: isouaidi <isouaidi@student.42nice.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/17 22:41:29 by isouaidi          #+#    #+#             */
/*   Updated: 2024/05/08 21:29:56 by isouaidi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINISHELL_H
# define MINISHELL_H

# include <unistd.h>
# include <readline/readline.h>
# include <readline/history.h>
# include <fcntl.h>
# include <stdio.h>
# include <signal.h>
# include <stdlib.h>
# include <limits.h>

# include "../libft/inc/libft.h"
# include "../libft/inc/ft_printf.h"
# include "../libft/inc/get_next_line_bonus.h"

int		main(int ac, char **av, char **env);
void	set_signal_action(void);
void	sign( int signal);

typedef enum e_token
{
	undefine,
	pipee,
	more,
	more_more,
	less,
	les_less,
}	t_token;

typedef enum e_built
{
	undefined,
	b_echo,
	b_cd,
	b_pwd,
	b_export,
	b_unset,
	b_env,
	b_exit,
}	t_built;

typedef struct s_parser
{
	t_token			tokken;
	t_built			built;
	char			*val;
	struct s_parser	*next;
}	t_parser;

typedef struct s_cmd
{
	t_token			tokken;
	t_built			built;
	t_parser		*redirections;	
	char			**val;
	struct s_cmd	*next;
}	t_cmd;

typedef struct s_env
{
	char			*name;
	char			*value;
	struct s_env	*next;
}	t_env;

typedef struct s_stru
{
	char	**args;
	int		sizetab;
	int		er_quote;
	int		er_tok;
	int		er_pipe;
	char	**env;
	char	**env1;
	int		s;
	int		d;
	int		i;
	int		dquote;
	int		squote;
}	t_stru;

// Utils
void	new_display(void);
void	free_tab(char **tab);
int		print_erreur(t_stru *stru);
int		erreurs(t_stru *stru);
void	clear_env(t_env *list);
void	clear_cmd(t_cmd *list);

// Lexer 
char	update_quote(char quote, char cur);
int		iterate(char *quote, char cur);
char	**split_line(char *str, t_stru *stru, int i);
char	*split_line_part2(char **list, char *str, t_stru *stru);
char	*split_line_part3(char *str, char *quote);
char	t_split(char c);
int		tok(char *str);
char	*redirections(char **list, char *str, t_stru *stru);
char	*redirections1(char **list, char *str, t_stru *stru);
char	*redirections2(char **list, char *str, t_stru *stru);
char	*other_tok(char **list, char *str, t_stru *stru);
char	**split_quote(t_stru *stru, char *str);
void	free_list(char **list);
void	pipe_begin(char *str, t_stru *stru);

int		tablen(char **tab);
void	getargs(t_stru *stru, char *str);
void	print_tab(t_stru *stru);

void	all_quotes(t_stru *stru);
void	solo_quote(t_stru *stru, int j, int i);
int		simple_q(int j, int w, int i, t_stru *stru);
int		double_q(int j, int q, int i, t_stru *stru);
void	final_part(t_stru *stru, int j, int i);
void	check_quote(t_stru *stru);

//Parser
void	printlist(t_parser *list);
void	clearlist(t_parser *list);
t_parser	*pushlist(t_parser *st, char *str);
t_cmd	*list_add(t_parser	*list, t_stru *stru, t_cmd *cmd, t_env **env);
t_token	tokken(t_parser *list);
t_built	builtines(t_parser *list);
void	builtines2(t_parser *list);
void	tok_end_built(t_parser *list);
void	tokken_erreur(t_parser *list, t_stru *stru);
t_cmd	*list_to_cmd(t_parser *list, t_cmd *cmd, int i, int flag);
void	prompt_cmd(t_cmd *cmd);
int		count_l(t_parser *list, int flag);
void	check_b(t_parser *list, t_cmd *cmd);
void	after_pipe(int *flag, t_parser *p, t_parser *c, t_cmd *n);
void	init_cmd(t_cmd *cmd);

void	test_prom(t_cmd *cmd);
void	prev(t_cmd *cmd);
void	chaine_env(t_env *en);
t_parser	*in_list(t_parser *current, t_parser	*new_redirection);
t_parser	*in_list3(t_cmd *cmd, t_parser *cur, t_parser *redi);

//ENV
void	print_env(char	**env);
char	**env00(char **splite, t_env *env, int *i, t_stru *stru);
t_env	*convert_env(t_env *env, t_stru *stru, t_parser *list);
char	*check_dol(char *str, t_env *env, int i, int j);
void	doll1(t_parser *list, t_env *env);
char	*check_dollars(char *str, t_env *env);
char	*apre(char *apres, char *recup, int *i, char *quote);
char	*ft_mostrjoin(char const *s1, char const *s2, char const *s3);
void	new_env(t_env *tes, t_stru *stru);
void	built_env(t_env *env);
t_env	*push_back_list(t_env *env, char *str, char *str2);
char	*parse_after(char *recup, int *i, char quote);
char	*parse_after_dollar(char *recup, int *i, t_env *env, char quote);
char	*parse_before_dollar(char *recup, int *i, char quote);
char	*extract_variable(char *recup, int *i, t_env *env, char quote);

//export
t_env	*export_solo(t_env *env);
t_env	*sorted_insertion(t_env **env);
void	insert_sort(t_env **head, t_env *newenv);

//supquote
void	supquote(t_parser *list);
void	remove_character_at_position(char *str, int pos);
void	is_in(char *in, char c);
void	delete(char *str);

//unset
t_env	*unset(t_env *env, char *str);
void	parse_command(t_parser *list, t_cmd *ncmd, int *flag);
void	parse_redirection(t_cmd **ncmd, t_parser **current);
void	add_val_to_cmd(t_cmd *ncmd, t_parser *current, int *i);
void	append_redirection(t_cmd *ncmd, t_parser *new_redirection);
t_parser	*create_redirection_node(t_parser *current);
t_parser	*handle_redirection(t_cmd **ncmd, t_parser *current);
t_cmd		*create_cmd_struct(t_parser *list, int *flag);
t_parser	*racc(int *i, t_parser *current, t_cmd *cmd, t_parser *redi);

#endif