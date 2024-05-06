/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   export.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: isouaidi <isouaidi@student.42nice.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/25 13:17:27 by isouaidi          #+#    #+#             */
/*   Updated: 2024/04/28 18:42:35 by isouaidi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	insert_sorted(t_env **env, t_env *newenv)
{
	t_env	*current;

	if (*env == NULL || ft_strcmp((*env)->name, newenv->name) >= 0)
	{
		newenv->next = *env;
		*env = newenv;
	}
	else
	{
		current = *env;
		while (current->next
			&& ft_strcmp(current->next->name, newenv->name) < 0)
			current = current->next;
		newenv->next = current->next;
		current->next = newenv;
	}
}

t_env	*sorted_insertion(t_env **env)
{
	t_env	*sorted;
	t_env	*current;
	t_env	*next;

	sorted = NULL;
	current = *env;
	while (current)
	{
		next = current->next;
		insert_sorted(&sorted, current);
		current = next;
	}
	*env = sorted;
	return (*env);
}

t_env	*export_solo(t_env *env)
{
	t_env	*sort;

	sort = sorted_insertion(&env);
	while (sort)
	{
		printf("declare -x ");
		printf("%s=\"%s\"\n", sort->name, sort->value);
		sort = sort->next;
	}
	return (sort);
}
