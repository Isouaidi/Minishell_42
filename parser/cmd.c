/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cmd.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: isouaidi <isouaidi@student.42nice.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/29 15:34:20 by isouaidi          #+#    #+#             */
/*   Updated: 2024/05/09 19:45:30 by isouaidi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

t_cmd	*list_to_cmd(t_parser *list, t_cmd *cmd, int i, int flag)
{
	t_cmd		*ncmd;
	t_parser	*current;
	t_parser	*pipe_start;
	t_parser	*new_redirection;
	int			count;

	ncmd = malloc(sizeof(t_cmd));
	count = count_l(list, flag);
	ncmd->val = (char **)malloc(sizeof(char *) * (count + 1));
	ncmd->redirections = NULL;
	current = list;
	while (current && flag != 1)
	{
		if (current->tokken == 1)
		{
			flag = 1;
			break ;
		}
		current = racc(&i,*(&current), *(&ncmd), *(&new_redirection));
	}
	ncmd->val[i] = NULL;
	after_pipe(&flag, *(&pipe_start),*(&current),*(&ncmd));
	cmd = ncmd;
	return (cmd);
}

int	count_l(t_parser *list, int flag)
{
	int			count;
	t_parser	*current;

	count = 0;
	current = list;
	while (current && flag != 1)
	{
		if (current->tokken == 1)
		{
			flag = 1;
			break ;
		}
		count++;
		current = current->next;
	}
	return (count);
}

void	after_pipe(int *flag, t_parser *p, t_parser *c, t_cmd *n)
{
	if ((*flag) == 1 && c != NULL)
	{
		p = c->next;
		n->next = list_to_cmd(p, NULL, 0, 0);
	}
	else
		n->next = NULL;
}

void	init_cmd(t_cmd *cmd)
{
	while (cmd)
	{
		cmd->built = 0;
		cmd->tokken = 0;
		cmd = cmd->next;
	}
}

void	check_b(t_parser *list, t_cmd *cmd)
{
	t_parser	*temp;

	init_cmd(cmd);
	temp = list;
	while (temp)
	{
		if (temp->built > 0)
		{
			cmd->built = temp->built;
			if (cmd->next != NULL)
				cmd = cmd->next;
		}
		temp = temp->next;
	}
}

void	prompt_cmd(t_cmd *cmd)
{
	int	i;
	int	j;

	j = 0;
	if (cmd != NULL)
	{
		while (cmd != NULL)
		{
			i = 0;
			printf("---------\n");
			printf("element chaine (CMD) : [%d]\n", j);
			printf("builtines [%d] : %d\n", j ,cmd->built);
			printf("\n");
			printf("Tab de tab (commande) :\n");
			while (cmd->val[i])
			{
				printf("cmd[%d]: %s\n", i, cmd->val[i]);
				i ++;
			}
			i = 0;
			printf("\n");
			if (cmd->redirections != NULL)
			{
			printf("list chaine (redirection) :\n");
			while (cmd->redirections)
			{
					printf("redi val[%d] : %s\n", i ,cmd->redirections->val);
					printf("redi tok[%d]: %d\n", i ,cmd->redirections->tokken);
					i++;
					cmd->redirections = cmd->redirections->next;
			}
			}
			printf("---------\n\n");
			j ++;
			cmd = cmd->next;
		}
	}
}
