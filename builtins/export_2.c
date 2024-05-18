/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   export_2.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: isouaidi <isouaidi@student.42nice.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/18 15:41:30 by isouaidi          #+#    #+#             */
/*   Updated: 2024/05/18 15:42:00 by isouaidi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

t_env	*new_node(const char *name, const char *value)
{
	t_env	*new;

	new = malloc(sizeof(t_env));
	if (!new)
		return (NULL);
	new->name = ft_strdup(name);
	if (value != NULL)
		new->value = ft_strdup(value);
	else
		new->value = ft_strdup("");
	new->next = NULL;
	return (new);
}

void	free_er(t_cpy *cpy)
{
	while (cpy->temp)
	{
		cpy->next = cpy->temp->next;
		free(cpy->temp->name);
		free(cpy->temp->value);
		free(cpy->temp);
		cpy->temp = cpy->temp->next;
	}
}

t_env	*copy_list(t_env *head)
{
	t_cpy	cpy;

	cpy.new_head = new_node(head->name, head->value);
	if (!cpy.new_head)
		return (NULL);
	cpy.current_new = cpy.new_head;
	cpy.current_old = head->next;
	while (cpy.current_old)
	{
		cpy.current_new->next = new_node(cpy.current_old->name,
				cpy.current_old->value);
		if (!cpy.current_new->next)
		{
			cpy.temp = cpy.new_head;
			free_er(&cpy);
			return (NULL);
		}
		cpy.current_new = cpy.current_new->next;
		cpy.current_old = cpy.current_old->next;
	}
	return (cpy.new_head);
}
