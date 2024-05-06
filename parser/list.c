/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   list.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: isouaidi <isouaidi@student.42nice.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/23 14:37:26 by isouaidi          #+#    #+#             */
/*   Updated: 2024/04/28 18:41:02 by isouaidi         ###   ########.fr       */
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
		printf("element [%d]: %s\n", i, list->val);
		printf("tokken [%d] : %d\n", i, list->tokken);
		printf("builtines [%d] : %d\n\n", i, list->built);
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

t_cmd	*list_add(t_parser *list, t_stru *stru, t_cmd *cmd, t_env **env)
{
	int	i;

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
		if (erreurs(stru) == 0)
		{
			*env = convert_env(*env, stru, *(&list));
			supquote(*(&list));
			//*env = push_back_list(*env, "ilyes", "moi");
			//built_env(*env);
			//sorted_insertion(env);
			//*env = push_back_list(*env, "ilyes", "non");
			//*env = unset(*env, "CHROME_DESKTOP");
			//*env = export_solo(*env);
			//chaine_env(*env);
			//clear_env(*env);
		}
		if (stru->er_tok == 0 && stru->er_pipe == 0 && stru->er_quote == 0)
		{
			cmd = list_to_cmd(list, cmd, 0, 0);
			check_b(list, *(&cmd));
			//clearlist(*(&list));
			//clear_cmd(*(&cmd));
			//clear_env(**(&env));
		}
	}
	if (print_erreur(stru) < 1)
	{
		//doll1(list);
		//printlist(list);
		//printf("9999999999999\n\n");
		prompt_cmd(cmd);
		return (cmd);
		stru->er_quote = 0;
		stru->er_pipe = 0;
		stru->er_tok = 0;
	}
	return(NULL);
}
