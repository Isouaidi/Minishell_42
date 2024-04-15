/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   env.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: isouaidi <isouaidi@student.42nice.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/06 07:59:10 by isouaidi          #+#    #+#             */
/*   Updated: 2024/04/15 18:44:34 by isouaidi         ###   ########.fr       */
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
	int j;
	char **split;
	//t_env *tes;

	i = 0;
	env = malloc(sizeof(t_env));
	//tes = env;
	while (stru->env[i])
	{
		j = 0;
		split = ft_split(stru->env[i], '=');
		j = ft_strlen(split[0]);
		env->name = malloc(sizeof(char) * (j + 1));
		env->name = split[0];
		if (split[1] != NULL)
			j = ft_strlen(split[1]);
		env->value = malloc(sizeof(char) * (j + 1));
		env->value = split[1];
		if (stru->env[i + 1] == NULL)
			env->next = NULL;
		else
			env->next = malloc(sizeof(t_env));
		free(split);
		env = env->next;
		i++;
	}
	i = 0;
	//chaine_env(tes);	
}

void	chaine_env(t_env *en)
{
	int i; 

	i = 0;
	while (en)
	{
		printf("name[%d] = %s\n",i, en->name);
		printf("value[%d] = %s\n\n",i, en->value);
		i++;
		en = en->next;
	} 	
}

void	check_dol(char *recup)
{	
	int i;
	int j;
	char *apres;
	char *avant;
	char *va;

	j = 0;
	i = 0;
	while (recup[i])
	{
		avant = malloc(sizeof(char) * (ft_strlen(recup + 1)));
		while (recup[i] != '$' && recup[i])
		{
			avant[j++] = recup[i++];		
		}
		avant[j] = '\0';
		printf("print 0 = %s\n", avant);
		j = 0;
		if(recup[i] == '$')
		{
			va = malloc(sizeof(char) * (ft_strlen(recup + 1)));
			while (recup[i] && recup[i] != '"')
				va[j++] = recup[i++];
			va[j] = '\0';
			printf("print 1 = %s\n", va);
		}
			j = 0;
			apres = malloc(sizeof(char) * (ft_strlen(recup + 1)));
			while (recup[i])
				apres[j++] = recup[i++];
			apres[j] = '\0';
			printf("print 2 = %s\n\n", apres);
		i++;
	}
}
void	doll1(t_parser *list)
{
	int f = 0;
	int j = 0;
	while (list)
	{
		f = 0;
		j = 0;
		while (list->val[j] && f != 1)
		{
			if (list->val[j] == '$')
			{	
				f = 1;
				break;
			}	
			j++;
		}
		if (f == 1)
		{
			check_dol(list->val);
		}
		list = list->next;
	}
		
}
