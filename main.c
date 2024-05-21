/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: isouaidi <isouaidi@student.42nice.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/15 20:07:33 by isouaidi          #+#    #+#             */
/*   Updated: 2024/05/21 18:23:22 by isouaidi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static	int	txt_null(char *txt)
{
	if (txt == NULL)
	{
		printf("exit\n");
		return (1);
	}
	return (0);
}

void	print_env(char **env)
{
	int	i;

	i = 0;
	while (env[i])
	{
		printf("%s\n", env[i]);
		i++;
	}
	return ;
}

void	main2(char **env, t_stru *stru, char *txt)
{
	t_pars		*pars;
	t_cmd		*cmd;

	cmd = NULL;
	pars = NULL;
	getargs(stru, txt);
	cmd = list_add(pars, stru, cmd, 0);
	if (stru->er_tok == 0 && stru->er_pipe == 0 && stru->er_quote == 0)
	{
		getpath(stru, env);
		etsi(cmd, stru, countcmd(cmd));
		boss(cmd, stru, env);
	}
	stru->p = 0;
	free_tab(stru->args);
	add_history(txt);
	free(txt);
	clearlist(pars);
	clear_cmd(cmd);
}

int	main(int ac, char **av, char **env)
{
	t_stru		stru;
	char		*txt;

	(void)av;
	stru.env = env;
	stru.check = 0;
	stru.p = 0;
	if (ac == 1 && env[0] != NULL)
	{
		set_signal_action();
		while (1)
		{
			txt = readline("Minishell> ");
			if (txt_null(txt) == 1)
				break ;
			main2(env, &stru, txt);
		}
		clear_env(stru.enuv);
		clear_env(stru.cpoy_env);
	}
	return (0);
}

void	etsi(t_cmd *cmd, t_stru	*stru, int i)
{
	stru->check = 0;
	if (i == 1 && ft_strcmp(cmd->val[0], "exit") == 0)
		ft_exit(cmd);
	else if (i == 1 && ft_strcmp(cmd->val[0], "cd") == 0)
	{
		if (cd(cmd) != 0)
			g_var = 1;
	}
	else if (i == 1 && ft_strcmp(cmd->val[0], "export") == 0)
	{
		stru->check = 1;
		if (export(stru, cmd, 1, 0) != 0)
			g_var = 1;
	}
	else if (i == 1 && ft_strcmp(cmd->val[0], "unset") == 0)
	{
		if (unset2(stru->enuv, cmd) != 0)
			g_var = 1;
	}
	else if (i == 1 && ft_strcmp(cmd->val[0], "env") == 0)
	{
		if (built_env(stru->enuv) != 0)
			g_var = 1;
	}
}
