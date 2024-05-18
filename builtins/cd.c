/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cd.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bsafi <bsafi@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/03 19:05:52 by bsafi             #+#    #+#             */
/*   Updated: 2024/05/17 16:32:29 by bsafi            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int g_var = 0;

int	cd(t_cmd *cmd)
{
	int	i;

	//printf("t la ?\n");
	i = countforall(cmd);
	if (i > 2)
	{
		ft_putstr_fd("cd: too many arguments\n", 2);
		return (1) ;
	}
	else if (i == 2)
	{
		//chdir("/home/mirio/codage/42/Minishell/builtins");
		if (chdir(cmd->val[1]) == -1)
		{
			printf("error no file or directory\n");
			return (1);
		}
	}
	else
		chdir("/home");
	return (0);
}
