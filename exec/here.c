/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   here.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bsafi <bsafi@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/08 13:27:12 by bsafi             #+#    #+#             */
/*   Updated: 2024/05/20 21:03:17 by bsafi            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	heredoc(t_cmd *cmd, t_stru *stru)
{
	char	*txt;

	if (cmd->redirections && cmd->redirections->tokken == 5)
	{
		cmd->redirections = cmd->redirections->next;
		stru->thefile = get_randomfile();
		stru->fd6 = open(stru->thefile, O_CREAT | O_WRONLY | O_RDONLY);
		txt = readline(">");
		while (1)
		{
			if (ft_strcmp(txt, cmd->redirections->val) == 0)
				break ;
			write(stru->fd6, txt, ft_strlen(txt));
			write(stru->fd6, "\n", 1);
			free(txt);
			txt = readline(">");
		}
		if (txt)
			free(txt);
		close(stru->fd6);
		stru->fd6 = open(stru->thefile, O_RDONLY);
		dup2(stru->fd6, STDIN_FILENO);
		close(stru->fd6);
		cmd->redirections = cmd->redirections->next;
	}
}

char	*get_randomfile0(void)
{
	int		fd;
	int		random;
	char	*therandom;

	random = 0;
	fd = open("/dev/random", O_RDONLY);
	if (fd == -1)
		return ("f44rgr9t");
	read(fd, &random, sizeof(int));
	close(fd);
	if (random < 0)
		random *= -1;
	therandom = ft_itoa(random);
	return (therandom);
}

char	*get_randomfile(void)
{
	char	*thefile;
	char	*therandom;
	int		i;

	i = 1;
	while (i > 0)
	{
		therandom = get_randomfile0();
		i--;
		thefile = ft_strjoin("/tmp/heredoc", therandom);
		if (access(thefile, F_OK) == -1)
			return (thefile);
		else
		{
			free(thefile);
			free(therandom);
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
