/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   here.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bsafi <bsafi@student.42nice.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/08 13:27:12 by bsafi             #+#    #+#             */
/*   Updated: 2024/05/16 12:19:05 by bsafi            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

/*void	heredoc(t_cmd *cmd, t_stru *stru)
{
	//pid_t	pid;
	int		fd;

	if (cmd->redirections && cmd->redirections->tokken == 5)
	{
		stru->thefile = get_randomfile();
		fd = open(stru->thefile, O_CREAT | O_WRONLY | O_RDONLY);
		cmd->redirections = cmd->redirections->next;
		//pid = fork();
		//if (pid == 0)
		//{
			heredocson(cmd, fd);
		//}
		//waitpid(pid, NULL, 0);
		close(fd);
		fd = open(stru->thefile, O_RDONLY);
		dup2(fd, STDIN_FILENO);
		close(fd);
		cmd->redirections = cmd->redirections->next;
	}
}

void	heredocson(t_cmd *cmd, int fd)
{
	char	*txt;
	//char	*file;
	//pid_t	pid;
	//int		fd;
	//stru->thefile = NULL;
	//int		i;
		//set_signal_action();
		//pid = fork();
		//if (pid == 0)
		//{
			//signal(SIGINT, &sigint_handle);
			//stru->thefile = get_randomfile();
			//fd = open(stru->thefile, O_CREAT | O_WRONLY | O_RDONLY);
			//write(fd, "lrorl", 5);
			txt = readline(">");
			while (ft_strcmp(txt, cmd->redirections->val) != 0)
			{
				write(fd, txt, ft_strlen(txt));
				write(fd, "\n", 1);
				free(txt);
				//i = 0;
				//printf("ici\n");
				txt = readline(">");
				if (!txt)
					return ;
				//signal(SIGINT, sigint_handle);
			}
			if (txt)
				free(txt);
			//close(fd);
			//fd = open(stru->thefile, O_RDONLY);
			//dup2(fd, STDIN_FILENO);
			//close(fd);
			//cmd->redirections = cmd->redirections->next;
		//}
		//waitpid(pid, NULL, 0);
}*/

void	heredoc(t_cmd *cmd, t_stru *stru)
{
	char	*txt;
	int		fd;
	//char	*file;
	//pid_t	pid;
	//stru->thefile = NULL;
	//int		i;

	if (cmd->redirections && cmd->redirections->tokken == 5)
	{
		cmd->here = 1;
		cmd->redirections = cmd->redirections->next;
		//set_signal_action();
		//pid = fork();
		//if (pid == 0)
		//{
		signal(SIGINT, &sigint_handle);
		stru->thefile = get_randomfile();
		fd = open(stru->thefile, O_CREAT | O_WRONLY | O_RDONLY);
		//write(fd, "lrorl", 5);
		txt = readline(">");
		while (ft_strcmp(txt, cmd->redirections->val) != 0)
		{
			write(fd, txt, ft_strlen(txt));
			write(fd, "\n", 1);
			free(txt);
			//i = 0;
			//printf("ici\n");
			txt = readline(">");
			//if (!txt)
			//signal(SIGINT, sigint_handle);
		}
		if (txt)
			free(txt);
		close(fd);
		fd = open(stru->thefile, O_RDONLY);
		dup2(fd, STDIN_FILENO);
		close(fd);
		cmd->redirections = cmd->redirections->next;
		//exit(0);
		//}
		//else
		//waitpid(pid, NULL, 0);
	}
}

char	*get_randomfile(void)
{
	int		fd;
	int		random;
	char	*thefile;
	char	*therandom;
	int		i;

	i = 1;
	while (i > 0)
	{
		i--;
		fd = open("/dev/random", O_RDONLY);
		if (fd == -1)
			return ("f44rgr9t");
		read(fd, &random, sizeof(int));
		close(fd);
		if (random < 0)
			random *= -1;
		therandom = ft_itoa(random);
		thefile = ft_strjoin("/tmp/heredoc", therandom);
		if (access(thefile, F_OK) == -1)
			return (thefile);
		else
		{
			free(thefile);
			free(therandom);
			random = 0;
			i = 1;
		}
	}
	return (NULL);
}

void	sigint_handle(int sig)
{
	(void)sig;
	printf("\n");
}
