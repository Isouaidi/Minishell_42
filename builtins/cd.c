/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cd.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bsafi <bsafi@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/03 19:05:52 by bsafi             #+#    #+#             */
/*   Updated: 2024/05/20 16:36:03 by bsafi            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	cd(t_cmd *cmd)
{
	int	i;

	i = countforall(cmd);
	if (i > 2)
	{
		ft_putstr_fd("cd: too many arguments\n", 2);
		return (1);
	}
	else if (i == 2)
	{
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
