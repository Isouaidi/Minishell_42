/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   echo.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bsafi <bsafi@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/01 17:05:39 by bsafi             #+#    #+#             */
/*   Updated: 2024/05/20 18:45:50 by bsafi            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	echon(t_cmd *cmd)
{
	char	*join;
	int		i;

	i = 0;
	if (!cmd->val[i + 1])
	{
		printf("\n");
		exit(0);
	}
	if (cmd->val[1][0] == '-' && cmd->val[1][1] == 'n')
	{
		i = echon2(cmd, i);
		join = ft_strdup(cmd->val[i++]);
		while (cmd->val[i] != NULL)
		{
			join = ft_strjoin(join, " ");
			join = ft_strjoin(join, cmd->val[i]);
			i++;
		}
		printf("%s", join);
	}
	else
		echo(cmd);
	return (0);
}

int	echon2(t_cmd *cmd, int i)
{
	int	j;

	while (cmd->val[++i])
	{
		j = 0;
		if (cmd->val[i][j++] == '-' && cmd->val[i][j] == 'n')
		{
			while (cmd->val[i][j] == 'n')
				j++;
			if (cmd->val[i][j] && cmd->val[i][j] != 'n')
				break ;
		}
		else
			break ;
	}
	return (i);
}

void	echo(t_cmd *cmd)
{
	int		i;
	char	*join;

	i = 2;
	if (!cmd->val[1])
		printf("\n");
	join = ft_strdup(cmd->val[1]);
	while (cmd->val[i] != NULL)
	{
		join = ft_strjoin(join, " ");
		join = ft_strjoin(join, cmd->val[i]);
		i++;
	}
	printf("%s", join);
	printf("\n");
}
