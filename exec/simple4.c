/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   simple4.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bsafi <bsafi@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/20 19:36:10 by bsafi             #+#    #+#             */
/*   Updated: 2024/05/20 20:11:09 by bsafi            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

char	**lastexe2(t_cmd *cmd)
{
	int		i;
	char	**all;
	int		j;

	i = countcmd(cmd);
	all = malloc(sizeof(char *) * (i + 1));
	j = -1;
	while (++j <= i)
		all[j] = ft_strdup2(cmd->val[j]);
	if (cmd->redirections && cmd->redirections->tokken == 2)
		redirectout(cmd);
	else if (cmd->redirections && cmd->redirections->tokken == 3)
		moremore(cmd);
	return (all);
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
