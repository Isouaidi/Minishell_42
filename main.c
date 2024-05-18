/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: isouaidi <isouaidi@student.42nice.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/15 20:07:33 by isouaidi          #+#    #+#             */
/*   Updated: 2024/05/18 16:47:31 by isouaidi         ###   ########.fr       */
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

int	main(int ac, char **av, char **env)
{
	t_stru		stru;
	t_pars	*pars;
	t_cmd		*cmd;
	// char 	**env1;
	t_env		*v_env;
	(void)ac;
	char		*txt;

	(void)av;
	stru.env = env;
	v_env = NULL;
	stru.check = 0;
	pars = NULL;
	cmd = NULL;
	stru.p = 0;
//	int   i = 0;
	if (ac == 1 && env[0] != NULL)
	{
		set_signal_action();
		while (1)
		{
			txt = readline("Minishell> ");
			if (txt_null(txt) == 1)
				break ;
			getargs(&stru, txt);
			cmd = list_add(pars, &stru, cmd);
			//prompt_cmd(cmd);
			// env1 = convert_chaine(&stru);
			getpath(&stru, env);
			o(&stru);
			etsi(cmd, &stru, countcmd(cmd));
			//o(&stru);
			//printf("%d\n", stru.p);
			if (stru.p > 0)
				boss(cmd, &stru, env);
			// else
			// 	printf("error PATH\n");
			stru.p = 0;
			free_tab(stru.args);
			add_history(txt);
			free(txt);
			//clearlist(pars);
			//clear_cmd(cmd);
			free_tab(stru.path);
		}
	clear_env(v_env);
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
