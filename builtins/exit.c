/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exit.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bsafi <bsafi@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/09 13:14:36 by bsafi             #+#    #+#             */
/*   Updated: 2024/05/20 19:33:54 by bsafi            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	ft_exit(t_cmd *cmd)
{
	int	i;
	int	arg;

	arg = 0;
	i = countforall(cmd);
	if (i > 2)
	{
		printf("exit\nMinishell: exit: too many arguments\n");
		return (1);
	}
	printf("exit\n");
	if (i == 2 && valid(cmd) == 0)
		arg = ft_atoi(cmd->val[1]);
	else
		arg = 2;
	g_var = arg;
	exit(arg);
	return (0);
}

int	valid(t_cmd *cmd)
{
	int	i;

	i = 0;
	if (cmd->val[1][i] == '+' || cmd->val[1][i] == '-')
		i++;
	while (cmd->val[1][i])
	{
		if (!ft_isdigit(cmd->val[1][i]))
		{
			ft_putstr_fd("Minishell: ", 2);
			ft_putstr_fd(cmd->val[1], 2);
			ft_putstr_fd(": numeric argument required\n", 2);
			return (1);
		}
		i++;
	}
	return (0);
}
