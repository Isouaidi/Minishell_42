/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   echo.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bsafi <bsafi@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/01 17:05:39 by bsafi             #+#    #+#             */
/*   Updated: 2024/05/17 15:16:54 by bsafi            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	echon(t_cmd *cmd)
{
	char	*join;
	int		i;
	int		j;

	i = 0;
	//printf("renter\n");
	if (!cmd->val[i + 1])
	{
		printf("\n");
		exit(0);
	}
	if (cmd->val[1][0] == '-' && cmd->val[1][1] == 'n')
	{
		while (cmd->val[++i])
		{
			j = 0;
			if (cmd->val[i][j++] == '-' && cmd->val[i][j] == 'n')
			{
				while (cmd->val[i][j] == 'n')
					j++;
				if (cmd->val[i][j] && cmd->val[i][j] != 'n')
					break ;
				//echon(cmd);
			}
			else
				break ;
		}
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
