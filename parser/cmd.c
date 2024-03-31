/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cmd.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: isouaidi <isouaidi@student.42nice.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/29 15:34:20 by isouaidi          #+#    #+#             */
/*   Updated: 2024/03/31 19:31:32 by isouaidi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

t_cmd	*list_to_cmd(t_parser *list, t_cmd *cmd, int i, int flag)
{
	t_cmd		*ncmd;
	t_parser	*current;
	t_parser	*pipe_start;
	int			count;

	ncmd = malloc(sizeof(t_cmd));
	count = count_l(list, flag);
	ncmd->val = (char **)malloc(sizeof(char *) * (count + 1));
	current = list;
	while (current && flag != 1)
	{
		if (current->tokken == 1)
		{
			flag = 1;
			break ;
		}
		ncmd->val[i] = ft_strdup(current->val);
		i++;
		current = current->next;
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
			printf("element[%d]\n", j);
			//printf("tokken [%d] : %d\n", j ,cmd->tokken);
			//printf("builtines [%d] : %d\n", j ,cmd->built);
			while (cmd->val[i])
			{
				printf("cmd[%d]: %s\n", i, cmd->val[i]);
				i ++;
			}
			printf("---------\n\n");
			j ++;
			cmd = cmd->next;
		}
	}
}

// void	check_t_b(t_parser *list, t_cmd *cmd)
// {
// 	int i = 0;
// 	int t = 0;
// 	int b = 0;
// 	while (cmd)
// 	{
// 		while (cmd->val[i])
// 		{
// 			t = tokken()
// 		}
		
// 	}
// }
