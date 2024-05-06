/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_3.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: isouaidi <isouaidi@student.42nice.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/28 17:47:35 by isouaidi          #+#    #+#             */
/*   Updated: 2024/04/28 17:57:35 by isouaidi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	clear_env(t_env *list)
{
	t_env	*temp;

	while (list)
	{
		temp = list->next;
		free(list->name);
		free(list->value);
		free (list);
		list = temp;
	}
}

void	clear_cmd(t_cmd *list)
{
	t_cmd	*temp;

	while (list)
	{
		temp = list->next;
		free(list->val);
		free(list->redirections);
		free (list);
		list = temp;
	}
}
