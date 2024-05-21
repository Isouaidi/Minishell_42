/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   path.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bsafi <bsafi@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/13 14:10:46 by bsafi             #+#    #+#             */
/*   Updated: 2024/05/20 18:39:21 by bsafi            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	getpath(t_stru *stru, char **env)
{
	int		i;
	int		j;
	char	*line;

	i = -1;
	while (env[++i])
	{
		j = 4;
		if (ft_strncmp(env[i], "PATH", j++) == 0)
		{
			line = ft_strdup(env[i] + j);
		}
	}
	if (o(stru) == 1)
		return ;
	stru->path = ft_split(line, ':');
	free(line);
	i = -1;
	while (stru->path[++i])
		stru->path[i] = ft_strjoin2(stru->path[i], "/");
}

int	o(t_stru *stru)
{
	t_env	*temp;

	temp = stru->enuv;
	while (temp)
	{
		if (ft_strcmp(temp->name, "PATH") == 0)
		{
			stru->p++;
		}
		temp = temp->next;
	}
	if (stru->p == 0)
	{
		g_var = 127;
		printf("error PATH\n");
		return (1);
	}
	return (0);
}

char	*ft_strjoin2(char *s1, char *s2)
{
	size_t	i;
	size_t	j;
	char	*str;

	i = -1;
	j = 0;
	str = malloc(sizeof(char) * ft_strlen(s1) + ft_strlen(s2) + 1);
	if (!str)
		return (0);
	if (!s1 || !s2)
		return (0);
	while (s1[++i])
		str[i] = s1[i];
	while (s2[j])
	{
		str[i] = s2[j];
		i++;
		j++;
	}
	if (s1)
		free(s1);
	str[i] = '\0';
	return (str);
}

char	*pathcmd(t_stru *stru, t_cmd *cmd)
{
	int		i;
	char	*test;

	i = -1;
	while (stru->path[++i])
	{
		test = ft_strjoin(stru->path[i], cmd->val[0]);
		if (access(test, F_OK | X_OK) == 0)
			return (test);
		free(test);
	}
	test = ft_strdup(cmd->val[0]);
	return (test);
}

char	*ft_strdup2(char *s)
{
	char	*s2;
	int		i;

	if (!s)
		return (NULL);
	s2 = malloc(sizeof(char) * (ft_strlen(s) + 1));
	i = 0;
	if (!s2)
		return (0);
	while (s[i])
	{
		s2[i] = s[i];
		i++;
	}
	s2[i] = '\0';
	return (s2);
}
