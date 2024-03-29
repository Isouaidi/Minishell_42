/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cmd.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: isouaidi <isouaidi@student.42nice.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/29 15:34:20 by isouaidi          #+#    #+#             */
/*   Updated: 2024/03/29 17:57:28 by isouaidi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	list_to_cmd(t_parser *list, t_cmd *cmd)
{
	int i = 0;
	while (list && list->tokken != pipee)
	{
		strcpy(cmd->val[i], list->val);
		i++;
		list = list->next;
	}
	i++;
	list=list->next;
}
