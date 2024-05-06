/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cmd_2.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: isouaidi <isouaidi@student.42nice.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/28 18:43:22 by isouaidi          #+#    #+#             */
/*   Updated: 2024/04/28 19:56:59 by isouaidi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

t_parser	*in_list(t_parser *current, t_parser	*new_redirection)
{
	new_redirection = malloc(sizeof(t_parser));
	new_redirection->tokken = current->tokken;
	new_redirection->val = ft_strdup(current->val);
	new_redirection->next = malloc(sizeof(t_parser));
	new_redirection->next->tokken = current->next->tokken;
	new_redirection->next->val = ft_strdup(current->next->val);
	new_redirection->next->next = NULL;
	return (new_redirection);
}

void	in_list2(t_parser *new_redirection, t_cmd *ncmd)
{
	t_parser	*temp;

	temp = ncmd->redirections;
	while (temp->next != NULL)
		temp = temp->next;
	temp->next = new_redirection;
}

t_parser	*in_list3(t_cmd *cmd, t_parser *cur, t_parser *redi)
{
	redi = in_list(*(&cur), *(&redi));
	if (cmd->redirections == NULL)
		cmd->redirections = redi;
	else
		in_list2(*(&redi), *(&cmd));
	cur = cur->next;
	return (redi);
}

t_cmd *declaration(t_cmd *ncmd, t_parser *redir, t_parser *current, int *flag)
{
	int	i;

	i = 0;
	if (current->tokken == 1)
	{
		*flag = 1;
		return (NULL);
	}
	if (current->tokken > 1)
		redir = in_list3(*(&ncmd), *(&current),
				*(&redir));
	else
	{
		ncmd->val[i] = ft_strdup(current->val);
		i++;
	}
	return (ncmd);
}
