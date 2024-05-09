/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   env2.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: isouaidi <isouaidi@student.42nice.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/09 19:25:08 by isouaidi          #+#    #+#             */
/*   Updated: 2024/05/09 19:40:14 by isouaidi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	built_env(t_env *env)
{
	while (env)
	{
		printf("%s", env->name);
		printf("=");
		if (env->value == NULL)
			printf("\n");
		else
			printf("%s\n", env->value);
		env = env->next;
	}
	printf("\n");
}

t_env	*push_back_list(t_env *env, char *str, char *str2, int f)
{
	t_env	*element;
	t_env	*check;
	t_env	*temp;
	t_env	*before;

	check = env;
	before = check;
	element = malloc(sizeof(t_env));
	element->name = ft_strdup(str);
	element->value = ft_strdup(str2);
	element->next = NULL;
	while (check)
	{
		rac_push(*(&check), *(&element), &f);
		check = check->next;
	}
	temp = before;
	if (f == 0)
	{
		while (temp->next != NULL)
			temp = temp->next;
		temp->next = element;
	}
	return (env);
}

void	rac_push(t_env *check, t_env *element, int *f)
{
	if (ft_strcmp(check->name, element->name) == 0)
	{
		check->value = element->value;
		free(element->name);
		*f = 1;
	}
}
