/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: isouaidi <isouaidi@student.42nice.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/17 22:41:29 by isouaidi          #+#    #+#             */
/*   Updated: 2024/03/26 17:41:11 by isouaidi         ###   ########.fr       */
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

int		main(void);
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
	int				intquote;
	t_token			tokken;
	t_built			built;
	char			*val;
	struct s_parser	*next;
}	t_parser;

typedef struct s_stru
{
	char	**args;
	int		sizetab;
	int		er_quote;
	int		s;
	int		d;
	int		i;
	int		dquote;
	int		squote;
}	t_stru;

// Utils
void	new_display(void);

// Lexer 
char	update_quote(char quote, char cur);
int		iterate(char *quote, char cur);
char	**split_line(char *str, t_stru *stru, int i);
char	*split_line_part2(char **list, char *str, t_stru *stru);
char	*split_line_part3(char *str, char *quote);
char	t_split(char c);
int		tok(char *str);
char	*redirections(char **list, char *str, t_stru *stru);
char	*other_tok(char **list, char *str, t_stru *stru);
char	**split_quote(t_stru *stru, char *str);

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
void	list_add(t_parser	*list, t_stru *stru);
t_token	tokken(t_parser *list);
t_built	builtines(t_parser *list);
void	builtines2(t_parser *list);
void	tok_end_built(t_parser *list);

#endif