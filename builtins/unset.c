/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   unset.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: isouaidi <isouaidi@student.42nice.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/26 19:22:18 by isouaidi          #+#    #+#             */
/*   Updated: 2024/05/07 23:04:59 by isouaidi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

t_env	*unset(t_env *env, char *str)
{
	t_env	*current;

	current = env;
	if (ft_strcmp(env->name, str) == 0)
	{
		env = env->next;
		return (env);
	}
	while (current != NULL && current->next != NULL)
	{
		if (ft_strcmp(current->next->name, str) == 0)
			current->next = current->next->next;
		current = current->next;
	}
	return (env);
}
