/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   list.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: isouaidi <isouaidi@student.42nice.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/23 14:37:26 by isouaidi          #+#    #+#             */
/*   Updated: 2024/05/21 18:23:17 by isouaidi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	printlist(t_pars *list)
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

void	clearlist(t_pars *list)
{
	t_pars	*temp;

	while (list)
	{
		temp = list->next;
		free (list);
		list = temp;
	}
}

t_pars	*pushlist(t_pars *st, char *str)
{
	t_pars	*element;
	t_pars	*temp;

	element = malloc(sizeof(t_pars));
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

t_cmd	*list_add(t_pars *list, t_stru *stru, t_cmd *cmd, int i)
{
	cmd = NULL;
	stru->er_tok = 0;
	if (stru->er_quote < 1)
	{
		while (stru->args[i])
			list = pushlist(list, stru->args[i++]);
		tok_end_built(*(&list));
		tokken_erreur(list, stru);
		if (erreurs(stru) == 0)
		{
			stru->enuv = convert_env(stru->enuv, stru, *(&list));
			supquote(*(&list));
		}
		if (stru->er_tok == 0 && stru->er_pipe == 0 && stru->er_quote == 0)
		{
			cmd = list_to_cmd(list, cmd, 0, 0);
			check_b(list, *(&cmd));
			clearlist(list);
			return (cmd);
		}
	}
	clear_cmd(cmd);
	return (NULL);
}

char	*modifintero(char *str, int i, int j)
{
	char	*av;
	char	*va;
	char	*ap;
	char	*final;

	while (str[i] && str[i] != '$')
		i++;
	av = malloc(sizeof(char) * (i + 1));
	ft_strlcpy(av, str, i + 1);
	va = ft_strdup(ft_itoa(g_var));
	j = ft_strlen(str);
	i = i + 2;
	ap = malloc(sizeof(char) * (j - i) + 1);
	j = 0;
	while (str[i])
		ap[j++] = str[i++];
	ap[j] = '\0';
	final = ft_strjoin(av, va);
	final = ft_strjoin(final, ap);
	return (final);
}
