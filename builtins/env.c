/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   env.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: isouaidi <isouaidi@student.42nice.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/06 07:59:10 by isouaidi          #+#    #+#             */
/*   Updated: 2024/04/06 11:03:59 by isouaidi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	print_env(char	**env)
{
	while (*env)
	{
	 	printf("%s\n", *env);
		env++;
	}
		
}
void	convert_env(t_env *env, t_stru *stru)
{
	int i;
	char **split;
	t_env *tes;

	i = 0;
	env = malloc(sizeof(t_env));
	tes = env;
	while (stru->env[i])
	{
		split = ft_split(stru->env[i], '=');
		env->name = malloc(sizeof(char) * (100));
		env->name = split[0];
		env->value = malloc(sizeof(char) * (100));
		env->value = split[1];
		if (stru->env[i + 1] == NULL)
			env->next = NULL;
		else
			env->next = malloc(sizeof(t_env));
		env = env->next;
		i++;
	}
	i = 0;
	while (tes)
	{
		printf("name[%d] = %s\n",i, tes->name);
		printf("value[%d] = %s\n",i, tes->value);
		i++;
		tes = tes->next;
	}
	 
}
