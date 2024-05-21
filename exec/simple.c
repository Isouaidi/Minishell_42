/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   simple.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bsafi <bsafi@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/13 14:27:46 by bsafi             #+#    #+#             */
/*   Updated: 2024/05/20 20:43:51 by bsafi            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	countcmd(t_cmd *cmd)
{
	t_cmd	*tmp;
	int		i;

	if (cmd->val[0] == NULL)
		return (0);
	tmp = cmd;
	i = 0;
	while (tmp)
	{
		i++;
		tmp = tmp->next;
	}
	return (i);
}

int	countforall(t_cmd *cmd)
{
	int	i;

	i = 0;
	while (cmd->val[i])
		i++;
	return (i);
}

void	boss(t_cmd *cmd, t_stru *stru, char **env)
{
	pid_t	pid;

	stru->exitarg = 0;
	stru->inson = countcmd(cmd);
	stru->fd0 = dup(STDIN_FILENO);
	stru->fd1 = dup(STDOUT_FILENO);
	pid = fork();
	if (stru->inson == 1 && cmd != NULL)
		checkg(cmd, stru);
	if (pid == -1)
		exit(1);
	else if (pid == 0)
	{
		exec(cmd, stru, env);
		exit(0);
	}
	else
	{
		waitpid(pid, NULL, 0);
	}
}

void	checkg(t_cmd *cmd, t_stru *stru)
{
	char	*path;

	path = pathcmd(stru, cmd);
	if (access(path, X_OK) == -1)
		g_var = 127;
	else
		g_var = 0;
}

void	exec(t_cmd *cmd, t_stru *stru, char **env)
{
	t_cmd	*test;
	int		i;
	int		pipefd[2];

	i = countcmd(cmd);
	test = cmd;
	stru->e = 0;
	while (i > 1)
	{
		pipe(pipefd);
		cmd->pid = fork();
		if (cmd->pid == 0)
			son(stru, cmd, pipefd, env);
		else
		{
			exec2(cmd, test, stru);
			father(pipefd);
		}
		i--;
		cmd = cmd->next;
	}
	if (stru->e == 1)
		waitpid(test->pid, NULL, 0);
	end(cmd, stru, env);
	thewait(test);
}
