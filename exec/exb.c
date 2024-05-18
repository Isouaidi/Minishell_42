/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exb.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: isouaidi <isouaidi@student.42nice.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/01 17:46:46 by bsafi             #+#    #+#             */
/*   Updated: 2024/05/18 16:46:15 by isouaidi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	built(char *s, t_stru *stru)
{
	if (ft_strcmp(s, "echo") == 0)
	{
		//printf("LA");
		stru->b = 1;
	}
	if (ft_strcmp(s, "cd") == 0)
		stru->b = 2;
	if (ft_strcmp(s, "pwd") == 0)
		stru->b = 3;
	if (ft_strcmp(s, "export") == 0 || stru->check == 1)
		stru->b = 4;
	if (ft_strcmp(s, "unset") == 0)
		stru->b = 5;
	if (ft_strcmp(s, "env") == 0)
		stru->b = 6;
	if (ft_strcmp(s, "exit") == 0)
		stru->b = 7;
}

void	execbuilt(t_cmd *cmd, t_stru *stru)
{
	//int	i;
	//i = countcmd(cmd);
	if (stru->b == 1)
	{
		//printf("re\n");grthf
		if (echon(cmd) != 0)
			g_var = 1;
	}
	else if (stru->b == 2 && stru->inson > 1)
	{
		//printf(" MONN BUITLIN\n");
		if (cd(cmd) != 0)
			g_var = 1;
	}
	else if (stru->b == 3)
	{
		if (pwd() != 0)
			g_var = 1;
	}
	// else if (stru->b == 4)
		//  export(*(&stru), cmd);
	//else if (stru->b == 5)
	//	stru->enuv = unset2(stru->enuv, cmd);
	//else if (stru->b == 6)
	//	built_env(stru->enuv);
	else if (stru->b == 7 && stru->inson > 1)
	{
		ft_exit(cmd);
	}
	else
		return ;
	//close(fd);
}
char	**convert_chaine(t_stru *stru)
{
	int 	i;
	char 	**env;
	t_env 	*temp;
	t_env 	*temp2;
	
	temp2 = stru->enuv;
	temp = stru->enuv;
	i = 0;
	while (temp)
	{
		i++;
		temp = temp->next;
	}
	printf("%d\n", i);
	env = malloc(sizeof(char *) * i + 1);
	i = 0;
	while (temp2)
	{
		env[i] = ft_strjoin2(temp2->name, "=");
		env[i] = ft_strjoin(env[i], temp2->value);
		//env[i] = ft_strjoin(env[i], "\0");
		i++;
		temp2 = temp2->next; 
	}
	//env[i] = 0;
	//i = 0;
	// while (env[i])
	// {
	// 	printf("%s\n", env[i++]);
	// }
	
	return(env);
}
