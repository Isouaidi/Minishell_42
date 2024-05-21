/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   simple3.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bsafi <bsafi@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/20 19:35:11 by bsafi             #+#    #+#             */
/*   Updated: 2024/05/20 20:44:01 by bsafi            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

char	**son2(t_cmd *cmd, int *pipefd)
{
	int		i;
	char	**all;
	int		j;

	i = countforall(cmd);
	all = malloc(sizeof(char *) * (i + 1));
	j = 0;
	while (j <= i)
	{
		all[j] = ft_strdup2(cmd->val[j]);
		j++;
	}
	if (cmd->redirections && cmd->redirections->tokken == 2)
		redirectout(cmd);
	else
		dup2(pipefd[1], STDOUT_FILENO);
	return (all);
}

void	father(int *pipefd)
{
	close(pipefd[1]);
	dup2(pipefd[0], STDIN_FILENO);
	close(pipefd[0]);
}

void	end(t_cmd *cmd, t_stru *stru, char **env)
{
	pid_t	pid;

	pid = fork();
	if (pid == -1)
		exit(1);
	else if (pid == 0)
	{
		lastex(cmd, stru, env);
		exit(0);
	}
	else
	{
		waitpid(pid, NULL, 0);
		dup2(stru->fd0, STDIN_FILENO);
		dup2(stru->fd1, STDOUT_FILENO);
	}
}

void	lastex(t_cmd *cmd, t_stru *stru, char **env)
{
	char	**all;
	char	*path;

	stru->b = 0;
	cmd->here = 0;
	redirectin(cmd);
	heredoc(cmd, stru);
	path = pathcmd(stru, cmd);
	all = lastexe2(cmd);
	built(cmd->val[0], stru);
	if (stru->b > 0)
	{
		execbuilt(cmd, *(&stru));
		exit(0);
	}
	else
	{
		if (stru->p > 0)
			place2(stru, all, env, path);
	}
	unlink(stru->thefile);
	exit(0);
}

void	place2(t_stru *stru, char **all, char **env, char *path)
{
	if (execve(path, all, env) == -1)
	{
		g_var = 127;
		dup2(stru->fd1, STDOUT_FILENO);
		printf("error exec\n");
		exit(1);
	}
}
