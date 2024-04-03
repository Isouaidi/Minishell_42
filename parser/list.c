/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   list.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: isouaidi <isouaidi@student.42nice.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/23 14:37:26 by isouaidi          #+#    #+#             */
/*   Updated: 2024/04/03 13:05:13 by isouaidi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	printlist(t_parser *list)
{
	int	i;

	i = 0;
	while (list != NULL)
	{
		printf("----------------------------\n");
		printf("element [%d]: %s\n" , i, list->val);
		printf("tokken [%d] : %d\n", i ,list->tokken);
		printf("builtines [%d] : %d\n\n", i ,list->built);
		list = list->next;
		i++;
	}
}

void	clearlist(t_parser *list)
{
	t_parser	*temp;

	while (list)
	{
		temp = list->next;
		free (list);
		list = temp;
	}
}

t_parser	*pushlist(t_parser *st, char *str)
{
	t_parser	*element;
	t_parser	*temp;

	element = malloc(sizeof(t_parser));
	if (!element)
		return (0);
	element->val = str;
	element->next = NULL;
	if (st == NULL)
		return (element);
	temp = st;
	while (temp->next)
		temp = temp->next;
	temp->next = element;
	return (st);
}

void	list_add(t_parser *list, t_stru *stru, t_cmd *cmd)
{
	int	i;
	t_parser *cpy;

	i = 0;
	cmd = NULL;
	stru->er_tok = 0;
	if (stru->er_quote < 1)
	{
		while (stru->args[i])
		{
			list = pushlist(list, stru->args[i]);
			i++;
		}
		tok_end_built(*(&list));
		tokken_erreur(list, stru);
		cmd = list_to_cmd(list, cmd, 0, 0);
		cpy = list;
		//redi(cpy,*(&cmd));
		//check_t(list, *(&cmd));
		check_b(cpy, *(&cmd));
		// test_prom(cmd);
	}
	stru->er_quote = 0;
	if (print_erreur(stru) < 1)
	{
		printlist(list);
		//printf("9999999999999\n\n");
		//prompt_cmd(cmd);
	}
}
// if (current->tokken > 1 || t == 1)
		// {	
		// 	t = 1;
		// 	current = cmd->redirections;
		// 	current = current->next;
		// 	break;
		// }	



// void	get_com(data)
// {
// 	t_cmd *tmp;
// 	int n;
// 	int i;

// 	n = n_cmd(data.lexer);
// 	tmp = NULL;
// 	while (i <= n)
// 	{
// 		fonc_redir_in();
// 		fonct_redir_out(); //acualise ton lexer
// 		tab
// 		builtines;
// 		heredoc;
		
// 	}
	
// }