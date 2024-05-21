/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bsafi <bsafi@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/17 22:41:29 by isouaidi          #+#    #+#             */
/*   Updated: 2024/05/20 21:02:20 by bsafi            ###   ########.fr       */
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
# include <sys/wait.h>

# include "../libft/inc/libft.h"
# include "../libft/inc/ft_printf.h"
# include "../libft/inc/get_next_line_bonus.h"

extern int	g_var;

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

typedef struct s_pars
{
	t_token			tokken;
	t_built			built;
	char			*val;
	struct s_pars	*next;
}	t_pars;

typedef struct s_env
{
	char			*name;
	char			*value;
	struct s_env	*next;
}	t_env;

typedef struct s_cmd
{
	t_token			tokken;
	t_built			built;
	t_pars			*redirections;	
	char			**val;
	struct s_cmd	*next;
	pid_t			pid;
	int				here;
}	t_cmd;

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
	char	**path;
	char	*cmd;
	char	*flag;
	char	*flag2;
	int		fd0;
	int		fd1;
	char	*thefile;
	int		r;
	int		exitarg;
	int		test;
	int		numcmd;
	int		b;
	int		p;
	int		check;
	int		inson;
	t_env	*enuv;
	t_env	*cpoy_env;
	t_env	*sort;
	int		e;
	int		fd6;
}	t_stru;

typedef struct s_cpy
{
	t_env	*current_new;
	t_env	*current_old;
	t_env	*new_head;
	t_env	*temp;
	t_env	*next;
}	t_cpy;

typedef struct s_dol
{
	int		d;
	char	quote;
	char	*apres;
	char	*avant;
	char	*va;
	int		j;
	int		i;
}	t_dol;

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
void	printlist(t_pars *list);
void	clearlist(t_pars *list);
t_pars	*pushlist(t_pars *st, char *str);
t_pars	*in_list(t_pars *current, t_pars	*new_redirection);
t_pars	*in_list3(t_cmd *cmd, t_pars *cur, t_pars *redi);
t_cmd	*list_add(t_pars	*list, t_stru *stru, t_cmd *cmd, int i);
t_token	tokken(t_pars *list);
t_built	builtines(t_pars *list);
void	builtines2(t_pars *list);
void	tok_end_built(t_pars *list);
void	tokken_erreur(t_pars *list, t_stru *stru);
t_cmd	*list_to_cmd(t_pars *list, t_cmd *cmd, int i, int flag);
void	prompt_cmd(t_cmd *cmd);
int		count_l(t_pars *list, int flag);
void	check_b(t_pars *list, t_cmd *cmd);
void	after_pipe(int *flag, t_pars *p, t_pars *c, t_cmd *n);
void	init_cmd(t_cmd *cmd);

void	test_prom(t_cmd *cmd);
void	prev(t_cmd *cmd);

//ENV
void	print_env(char	**env);
char	**env00(char **splite, t_env *env, int *i, t_stru *stru);
t_env	*convert_env(t_env *env, t_stru *stru, t_pars *list);
char	*check_dol(char *str, t_env *env);
void	doll1(t_pars *list, t_env *env);
char	*check_dollars(char *str, t_env *env);
char	*apre(char *apres, char *recup, int *i, char *quote);
char	*ft_mostrjoin(char const *s1, char const *s2, char const *s3);
void	new_env(t_env *tes, t_stru *stru);
int		built_env(t_env *env);
void	parse_after_dollar(char *recup, t_env *env, t_dol *dol);
int		parse_before_dollar(char *recup, t_dol *dol);
void	extract_variable(char *recup, t_env *env, t_dol *dol);
void	parse_after(char *recup, t_dol *dol);

//export
void	export_solo(t_env *env);
int		export(t_stru *stru, t_cmd *cmd, int i, int j);
t_env	*sorted_insertion(t_env **env);
void	insert_sort(t_env **head, t_env *newenv);
void	push_back_list(t_stru *stru, char *str, char *str2, int f);
void	rac_push(t_env *check, t_env *element, int *f);

//supquote
void	supquote(t_pars *list);
void	remove_character_at_position(char *str, int pos);
void	is_in(char *in, char c);
void	delete(char *str);

//unset
t_env	*unset(t_env *env, char *str);
int		unset2(t_env *env, t_cmd *cmd);
void	parse_command(t_pars *list, t_cmd *ncmd, int *flag);
void	parse_redirection(t_cmd **ncmd, t_pars **current);
void	add_val_to_cmd(t_cmd *ncmd, t_pars *current, int *i);
void	append_redirection(t_cmd *ncmd, t_pars *new_redirection);
t_pars	*create_redirection_node(t_pars *current);
t_pars	*handle_redirection(t_cmd **ncmd, t_pars *current);
t_cmd	*create_cmd_struct(t_pars *list, int *flag);
t_pars	*racc(int *i, t_pars *current, t_cmd *cmd, t_pars *redi);
void	built_env_export(t_env *env);

//exec
char	*ft_strjoin2(char *s1, char *s2);
int		o(t_stru *stru);
void	getpath(t_stru *stru, char **env);
char	*pathcmd(t_stru *stru, t_cmd *cmd);
int		countcmd(t_cmd *cmd);
int		getcmd(t_cmd *cmd, t_stru *stru);
void	boss(t_cmd *cmd, t_stru *stru, char **env);
void	exec(t_cmd *cmd, t_stru *stru, char **env);
void	son(t_stru *stru, t_cmd *cmd, int *pipefd, char **env);
void	father(int *pipefd);
void	redirectin(t_cmd *cmd);
void	end(t_cmd *cmd, t_stru *stru, char **env);
void	lastex(t_cmd *cmd, t_stru *stru, char **env);
char	*ft_strdup2(char *s);
int		countforall(t_cmd *cmd);
void	moremore(t_cmd *cmd);
void	heredoc(t_cmd *cmd, t_stru *stru);
void	heredocson(t_cmd *cmd, int fd);
int		ft_strcmp(const char *s1, const char *s2);
void	redirectout(t_cmd *cmd);
int		strtofd(char *str);
void	echo(t_cmd *cmd);
int		echon(t_cmd *cmd);
int		echon2(t_cmd *cmd, int i);
int		pwd(void);
int		cd(t_cmd *cmd);
int		ft_exit(t_cmd *cmd);
void	built(char *s, t_stru *stru);
void	execbuilt(t_cmd *cmd, t_stru *stru);
void	sigint_handle(int sig);
char	*get_randomfile(void);
char	*get_randomfile0(void);
int		valid(t_cmd *cmd);
void	etsi(t_cmd *cmd, t_stru *stru, int i);
char	**convert_chaine(t_stru *stru);
void	glist(t_pars *list);
char	*modifintero(char *str, int i, int j);
t_env	*copy_list(t_env *head);
t_env	*new_node(const char *name, const char *value);
void	checkg(t_cmd *cmd, t_stru *stru);

//ca comble
void	exec2(t_cmd *cmd, t_cmd *test, t_stru *stru);
void	thewait(t_cmd *test);
void	freeing(char *path, char **all);
void	place(t_stru *stru, char **all, char **env, char *path);
char	**son2(t_cmd *cmd, int *pipefd);
void	place2(t_stru *stru, char **all, char **env, char *path);
char	**lastexe2(t_cmd *cmd);

#endif