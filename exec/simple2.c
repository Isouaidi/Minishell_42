/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   simple2.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bsafi <bsafi@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/20 19:34:12 by bsafi             #+#    #+#             */
/*   Updated: 2024/05/20 20:43:42 by bsafi            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	exec2(t_cmd *cmd, t_cmd *test, t_stru *stru)
{
	if (cmd->redirections && cmd->redirections->tokken == 5)
	{
		test->pid = cmd->pid;
		stru->e = 1;
		waitpid(cmd->pid, NULL, 0);
	}
}

void	thewait(t_cmd *test)
{
	int	i;

	i = countcmd(test);
	while (i > 1)
	{
		waitpid(test->pid, NULL, 0);
		test = test->next;
		i--;
	}
}

void	son(t_stru *stru, t_cmd *cmd, int *pipefd, char **env)
{
	char	**all;
	char	*path;

	stru->b = 0;
	redirectin(cmd);
	heredoc(cmd, stru);
	close(pipefd[0]);
	path = pathcmd(stru, cmd);
	all = son2(cmd, pipefd);
	built(cmd->val[0], stru);
	if (stru->b > 0)
	{
		execbuilt(cmd, stru);
		exit(1);
	}
	else
	{
		if (stru->p > 0)
		{
			place(stru, all, env, path);
			exit(1);
		}
	}
	freeing(path, all);
	exit(0);
}

void	freeing(char *path, char **all)
{
	free(path);
	free_tab(all);
}

void	place(t_stru *stru, char **all, char **env, char *path)
{
	if (execve(path, all, env) == -1)
	{
		g_var = 127;
		dup2(stru->fd1, STDOUT_FILENO);
		printf("error exec\n");
		exit(1);
	}
}
