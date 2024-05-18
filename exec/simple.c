/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   simple.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bsafi <bsafi@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/13 14:27:46 by bsafi             #+#    #+#             */
/*   Updated: 2024/05/16 19:00:59 by bsafi            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	countcmd(t_cmd *cmd)
{
	t_cmd	*tmp;
	int		i;

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
	//printf("hello\n");
	//if (cmd->redirections->val[0] == '<')
	//redirectin(cmd);
	//printf("hello\n");

	//stru->r = 0;
	stru->exitarg = 0;
	stru->inson = countcmd(cmd);
	stru->fd0 = dup(STDIN_FILENO);
	stru->fd1 = dup(STDOUT_FILENO);
	pid = fork();
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

void	exec(t_cmd *cmd, t_stru *stru, char **env)
{
	int		e;
	t_cmd	*test;
	int		i;
	int		pipefd[2];
	//pid_t	pid;
	//char	*buf;
	//char	*str;
	//int		here[2];

	i = countcmd(cmd);
	//stru->numcmd = i;
	test = cmd;
	e = 0;
	//test->o = 0;
	while (i > 1)
	{
		//getcmd(cmd, stru);
		if (pipe(pipefd) == -1)
			exit(1);
		/*if (pipe(here) == -1)
			exit(1);*/
		cmd->pid = fork();
		//test->o++;
		if (cmd->pid == -1)
			exit(1);
		else if (cmd->pid == 0)
		{
			son(stru, cmd, pipefd, env);
			exit(0);
		}
		else
		{
			if (cmd->redirections && cmd->redirections->tokken == 5)
			{
				test->pid = cmd->pid;
				e = 1;
				waitpid(cmd->pid, NULL, 0);
			}
			father(pipefd);
		}
		i--;
		//if (e == 1)
		//	waitpid(cmd->pid, NULL, 0);
		cmd = cmd->next;
	}
	//if (stru->exitarg)
	//	exit(stru->exitarg);
	i = countcmd(test);
	/*while (test)
	{
		if (test->pid == 0)
			close(pipefd[0]);
		test = test->next;
	}*/
	/*while(read(here[0], buf, 1))
		str = ft_strjoin(str, buf);
	if (ft_strcmp("belek", str) == 0)
		waitpid(pid, NULL, 0);*/
	if (e == 1)
		waitpid(test->pid, NULL, 0);
	end(cmd, stru, env);
	/*while (test)
	{
		printf("le o : %d\n", test->o);
		test = test->next;
	}*/
	while (i > 1)
	{
		waitpid(test->pid, NULL, 0);
		test = test->next;
		i--;
	}
	//waitpid(cmd->pid, NULL, 0);
}

void	son(t_stru *stru, t_cmd *cmd, int *pipefd, char **env)
{
	char	**all;
	char	*path;
	int		i;
	int		j;

	j = 0;
	stru->b = 0;
	cmd->here = 0;
	redirectin(cmd);
	heredoc(cmd, stru);
	i = countforall(cmd);
	close(pipefd[0]);
	path = pathcmd(stru, cmd);
	//printf("path : %s\n", path);
	all = malloc(sizeof(char *) * (i + 1));
	while (j <= i)
	{
		all[j] = ft_strdup2(cmd->val[j]);
		//printf("all[%d], : %s\n", j, all[j]);
		j++;
	}
	//all[j + 1] = NULL;
	if (cmd->redirections && cmd->redirections->tokken == 2)
		redirectout(cmd);
	else
	{
		//printf("%d\n", pipefd[1]);
		dup2(pipefd[1], STDOUT_FILENO);
	}
	built(cmd->val[0], stru);
	//printf("%d\n", b);
	if (stru->b > 0)
	{
		execbuilt(cmd, stru);
		exit(1);
	}
	else
	{
		//printf("%d\n", pipefd[1]);
		if (execve(path, all, env) == -1)
		{
			dup2(stru->fd1, STDOUT_FILENO);
			printf("error exec\n");
			exit(1);
		}
	}
	free(path);
	free_tab(all);
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

	//heredoc(cmd, stru);
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
		//unlink(stru->thefile);
		//free(stru->thefile);
	}
}

void	lastex(t_cmd *cmd, t_stru *stru, char **env)
{
	char	**all;
	char	*path;
	int		i;
	int		j;
	//int		fd;

	j = 0;
	stru->b = 0;
	cmd->here = 0;
	redirectin(cmd);
	heredoc(cmd, stru);
	i = countforall(cmd);
	//printf("quand\n");
	path = pathcmd(stru, cmd);
	all = malloc(sizeof(char *) * (i + 1));
	while (j <= i)
	{
		all[j] = ft_strdup2(cmd->val[j]);
		//printf("%s\n", cmd->val[j]);
		j++;
	}
	//all[j + 1] = NULL;
	if (cmd->redirections && cmd->redirections->tokken == 2)
	{
		redirectout(cmd);
	}
	else if (cmd->redirections && cmd->redirections->tokken == 3)
		moremore(cmd);
	//printf("%s\n", cmd->val[0]);
	built(cmd->val[0], stru);
	if (stru->b > 0)
	{
		execbuilt(cmd, *(&stru));
		//printf("%drtfr\n", stru->exitarg);
		//if (stru->exitarg == 0)
		//exit(1);
	}
	else
	{
		if (execve(path, all, env) == -1)
		{
			dup2(stru->fd1, STDOUT_FILENO);
			printf("error exec\n");
			exit(1);
		}
	}
	unlink(stru->thefile);
	exit(0);
	//printf("tett\n");
}

void	moremore(t_cmd *cmd)
{
	int	fd;

	cmd->redirections = cmd->redirections->next;
	if (access(cmd->redirections->val, F_OK) == -1)
		fd = open(cmd->redirections->val, O_CREAT | O_WRONLY | O_APPEND);
	else
		fd = open(cmd->redirections->val, O_WRONLY | O_APPEND);
	dup2(fd, STDOUT_FILENO);
}

void	redirectout(t_cmd *cmd)
{
	int	fd;

	cmd->redirections = cmd->redirections->next;
	if (access(cmd->redirections->val, F_OK) == -1)
		fd = open(cmd->redirections->val, O_CREAT | O_WRONLY | O_TRUNC);
	else
		fd = open(cmd->redirections->val, O_WRONLY | O_TRUNC);
	dup2(fd, STDOUT_FILENO);
}

void	redirectin(t_cmd *cmd)
{
	int	fd;

	if (cmd->redirections && cmd->redirections->tokken == 4)
	{
		cmd->redirections = cmd->redirections->next;
		if (access(cmd->redirections->val, F_OK | R_OK) == -1)
		{
			printf("error : %s no file this type\n", cmd->redirections->val);
			exit(1);
		}
		else
			fd = open(cmd->redirections->val, O_RDONLY);
		dup2(fd, STDIN_FILENO);
		cmd->redirections = cmd->redirections->next;
	}
}

/*int		getcmd(t_cmd *cmd, t_stru *stru)
{
	int		i;
	char	**tmp;

	i = -1;
	printf("la cmd : %s\n", cmd->val[0]);
	while (cmd->val[0][++i])
	{
		if (cmd->val[0][i] == ' ')
		{
			tmp = ft_split(cmd->val[0], ' ');
			stru->cmd = ft_strdup(tmp[0]);
			if (tmp[1])
				stru->flag = ft_strdup(tmp[1]);
			else
				stru->flag = NULL;
			return (0);
		}
	}
	stru->cmd = ft_strdup(cmd->val[0]);
	if (cmd->val[1])
		stru->flag = ft_strdup(cmd->val[1]);
	else
		stru->flag = NULL;
	if (cmd->val[2])
		stru->flag2 = ft_strdup(cmd->val[2]);
	else
		stru->flag2 = NULL;
	printf("le flag2 : %s \n", stru->flag2);
	return (0);
}*/

int	ft_strcmp(const char *s1, const char *s2)
{
	size_t	i;

	i = 0;
	if (!s1)
		return (1);
	while (s1[i] || s2[i])
	{
		if (s1[i] != s2[i])
			return ((unsigned char)s1[i] - ((unsigned char)s2[i]));
		i++;
	}
	return (0);
}

int	strtofd(char *str)
{
	int	fd[2];
	int	pid;
	int	new_fd;

	if (!str)
		str = NULL;
	if (pipe(fd) == -1)
		return (-1);
	pid = fork();
	if (!pid)
	{
		close(fd[0]);
		ft_putstr_fd(str, fd[1]);
		close(fd[1]);
		exit(0);
	}
	waitpid(pid, NULL, 0);
	close(fd[1]);
	new_fd = dup(fd[0]);
	close(fd[0]);
	return (new_fd);
}
/*pour heredoc faire un while(1) avec readline et prendre arg et tt ca dans un processus 
fils */

// faire un while (i) si le fichier existe remettre i a 1 et recommencer pour ft_heredoc.
